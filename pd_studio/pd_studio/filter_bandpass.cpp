#include "filter_bandpass.h"
#include "fdacoefs_FilterCoef.h"
#include "ui_filter_bandpass.h"
#include "filter_bandpass.h"
#include <qwidget.h>
#include <vector>
#include "qscrollarea.h"
#include "QWT\qwt_plot.h"
#include "QWT\qwt_plot_curve.h"
#include "QWT\qwt_plot_magnifier.h"
#include "QWT\qwt_plot_panner.h"
#include "QWT\qwt_plot_zoomer.h"
#include "QWT\qwt_legend.h"
#include "QWT\qwt_plot_grid.h"
#include "QWT\qwt_plot_rescaler.h"

using std::vector;


filter_bandpass::filter_bandpass(
	vector<ResultantAcc> acc, QWidget *parent):
	QWidget(parent), ui(new Ui::filter_bandpass)
{
	ui->setupUi(this);

	for (auto item : acc) {
		filter_time.push_back(item.time);
		filter_sig.push_back(item.data);
	}
}


filter_bandpass::~filter_bandpass()
{
	delete ui;
}

int filter_bandpass::FiltData(
	vector<ResultantAcc> &v_ra)
{
	if (filter_sig.size()<1)
		return 0;

	//filt
	SigConv();
	if (filted.size() < 1) {
		return 0;
	}

	ResultantAcc ra;
	for (int i = 0; i < filted.size(); i++) {
		ra.data = filted[i];
		ra.time = filter_time[i];
		v_ra.push_back(ra);
	}
	return v_ra.size();
}

void filter_bandpass::SigConv()
{
	vector<double> coefs;
	for (auto item : B) {
		coefs.push_back(item);
	}

    if (filter_sig.size() > coefs.size()) {
		Convolution(filter_sig, coefs);
	}
	else {
		Convolution(coefs, filter_sig);
	}
}

void filter_bandpass::Convolution(vector<double> signal,
	vector<double> coefs)
{
	int sigLen = signal.size() - 1;
	int coefLen = coefs.size() - 1;
	int length = sigLen + coefLen;
	vector<double> result;

    for (int r = 0; r <= length; r++) {
		result.push_back(0.0);
	}
	
	for (int i = 1; i <= length; ++i) {
		result[i] = 0.0;
		if (i < coefLen) {
			for (int j = 1; j <= i; ++j)
				result[i] += coefs[j] * signal[i - j + 1];
		}
		else if (i <= sigLen) {
			for (int j = 1; j <= coefLen; ++j)
				result[i] += coefs[j] * signal[i - j + 1];
		} 
		else {
			for (int j = i - sigLen + 1; j <= coefLen; ++j)
				result[i] += coefs[j] * signal[i - j + 1];
		}
	}

	for (int i = 0; i <= sigLen;i++) {
		filted.push_back(result[i]);
	}
}

QWidget* filter_bandpass::ShowResult(int w, int h)
{
	if (filted.size() < 1)
		return ui->wgt_main;

    //draw
	ui->wgt_main->resize(w - 20, h - 20);
	ShowOneByOne(ui->wgt_signal, true, filter_sig);
    ShowOneByOne(ui->wgt_filter, false, filted);
	ui->wgt_main->setStyleSheet("background-color:rgb(255, 34, 198)");

	return ui->wgt_main;  
}

void filter_bandpass::ShowOneByOne(QWidget *widget,
    bool flag, vector<double> ydata)
{
	widget->resize((ui->wgt_main->width() - 20) / 2,
		ui->wgt_main->height()-20);
	widget->setStyleSheet("background-color:rgb(200, 233, 168)");
	//widget->setMinimumSize(800 , 300);
	QwtPlot *plot = new QwtPlot(widget);
	plot->resize(widget->width(), widget->height());
	plot->move(0, 0);
	plot->setAutoFillBackground(true);
	Init_QwtPlot(plot);
	plot->setAutoReplot(true);
	QFont font("msyh", 10);
	plot->setFont(font);
	plot->setAxisTitle(QwtPlot::yLeft, "a / mm^2");
	plot->setAxisTitle(QwtPlot::xBottom, "time /ms");
	//计算曲线数据
	QVector<double> xs;
	QVector<double> ys;
	
    for (auto item : filter_time) {
		xs.push_back(item);
	}
    for (auto item : ydata) {
		ys.push_back(item);
	}
	
	//调试程序时，验证是不是数据影响了图像显示
	/*for (int i = 0; i < 10; i++) {
		xs.push_back(i);
		ys.push_back(i*i);
	}*/
	//构造曲线数据
	QwtPlotCurve *curve = new QwtPlotCurve();
	if (flag) {
		curve->setTitle("Raw Signal");
	}
	else {
		curve->setTitle("After Filted");
	}
	curve->attach(plot);
	curve->setSamples(xs, ys);
	//设置曲线上是点还是线，默认是线
	curve->setStyle(QwtPlotCurve::Lines); //Dots
										  //使曲线更光滑，不加这句曲线会很硬朗，有折点
	curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
	//设置画笔
	curve->setPen(QPen(Qt::red));
	plot->replot();
	plot->show();
}

void filter_bandpass::PlotFilted(QWidget *widget, QString title,
	vector<ResultantAcc> data)
{
	widget->setStyleSheet("background-color:rgb(200, 233, 168)");
	QwtPlot *plot = new QwtPlot(widget);
	plot->resize(widget->width(), widget->height());
	plot->setMinimumSize(285, 270);
	plot->move(0, 0);
	plot->setAutoFillBackground(true);
	Init_QwtPlot(plot);
	plot->setAutoReplot(true);
	QFont font("msyh", 10);
	plot->setFont(font);
	plot->setAxisTitle(QwtPlot::yLeft, "a / mm^2");
	plot->setAxisTitle(QwtPlot::xBottom, "time /ms");
	//计算曲线数据
	QVector<double> xs;
	QVector<double> ys;

	for (auto item : data) {
		xs.push_back(item.time);
		ys.push_back(item.data);
	}

	QwtPlotCurve *curve = new QwtPlotCurve(title);
	curve->attach(plot);
	curve->setSamples(xs, ys);
	//设置曲线上是点还是线，默认是线
	curve->setStyle(QwtPlotCurve::Lines);
	curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
	//设置画笔
	curve->setPen(QPen(Qt::red));
	plot->replot();
}

void filter_bandpass::Init_QwtPlot(QwtPlot *plot)
{
	plot->autoFillBackground();
	//坐标轴设置：主要显示xBottom, yLeft
	plot->enableAxis(QwtPlot::yLeft, true);
	plot->enableAxis(QwtPlot::yRight, false);
	plot->enableAxis(QwtPlot::xTop, false);
	plot->enableAxis(QwtPlot::xBottom, true);
	//加上网格
	QwtPlotGrid *grid = new QwtPlotGrid();
	//设置网格线的样式
	grid->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine));
	grid->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
	grid->attach(plot);
	plot->setAxisLabelAlignment(QwtPlot::xBottom,
		Qt::AlignLeft | Qt::AlignBottom);
	//使用滚轮放大/缩小
	(void) new QwtPlotMagnifier(plot->canvas());
	QwtPlotZoomer *zoomer = new QwtPlotZoomer(plot->canvas());
	zoomer->setRubberBandPen(QColor(Qt::yellow));
	zoomer->setTrackerPen(QColor(Qt::blue));
	zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
		Qt::RightButton, Qt::ControlModifier);
	plot->replot();
}
