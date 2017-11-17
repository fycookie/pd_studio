#include "trim_signal.h"
#include <vector>
#include <qwidget.h>
#include "global_data.h"
#include "ui_trim_signal.h"
#include "qscrollarea.h"
#include "qmenu.h"
#include "math.h"
#include <QDateTime>
#include <QMessageBox>
#include <fstream>
#include "QWT\qwt_plot.h"
#include "QWT\qwt_plot_curve.h"
#include "QWT\qwt_plot_magnifier.h"
#include "QWT\qwt_plot_panner.h"
#include "QWT\qwt_plot_zoomer.h"
#include "QWT\qwt_legend.h"
#include "QWT\qwt_plot_grid.h"
#include "QWT\qwt_plot_rescaler.h"

using namespace std;


trim_signal::trim_signal(
	QWidget *parent) : QWidget(parent),
		ui(new Ui::trim_signal)
{
	ui->setupUi(this);
	ui->trim_signal_main->setStyleSheet(
		"background-color:rgb(255, 34, 198)");
	ui->widget->setStyleSheet(
		"background-color:rgb(125, 34, 198)");
}

trim_signal::~trim_signal()
{
	delete ui;
}

void trim_signal::ReadFile(
        FileSuffixType fType, string fPath)
{
	switch (fType)
	{
	case csv:
		ReadCSV(fPath);
		if (vecSignal.size()>0) {
			vecDataTrim.assign(vecSignal.begin(),
				vecSignal.end());
		}
		break;
	case txt:
		break;
	case xls:
		break;
	default:
		break;
	}
}

void trim_signal::SlotTrimSave(double begin, double end)
{
    vecDataTrim.clear();

    for(auto item: vecSignal){
        if(item.t < begin)
            continue;
        else{
            if(item.t < end)
                break;
            vecDataTrim.push_back(item);
        }
    }

    PlotSignal();
}

void trim_signal::SlotTrimReset()
{
    vecDataTrim.assign(vecSignal.begin(),
                       vecSignal.end());
    PlotSignal();
}

void trim_signal::SlotTrimExport()
{
	if (vecDataTrim.size() < 1) {
		QMessageBox::information(this, "Warning",
			"Data of trim is empty.", QMessageBox::Yes);
		return;
	}
    QDateTime dt;
    QString day = dt.currentDateTime().toString("yyyyMMdd");
    QString time= dt.currentDateTime().toString("hh_mm_ss");
    QString path = "..//data//"+day+"//"+time+".csv";
    ofstream ofile;
    ofile.open(path.toStdString(), ios::out);
    ofile << "data trim:" << endl;
    ofile << "time" << "," << "signal" << endl;

    for (int i = 0; i < sizeof(vecDataTrim.size()); i++) {
        ofile << vecDataTrim[i].t << "," <<
                 vecDataTrim[i].o << endl;
    }

    ofile.close();
}

void trim_signal::SlotTrimUpdate(QWidget *widegt)
{
    PlotSignal();
}

void trim_signal::ReadCSV(string path)
{
    ifstream iFile(path);
    if (iFile.is_open()) {
        while (!iFile.eof()) {
            iFile.getline(buffer, 256);
            int reg = sscanf(buffer, "%lf, %lf, %lf, %lf",
                &signal.t, &signal.x, &signal.y, &signal.z);
            if (reg == 4) {
                signal.o = sqrt(signal.x * signal.x +
                                signal.y * signal.y +
                                signal.z * signal.z);
                vecSignal.push_back(signal);
            }
            else {
                continue;
            }
        }
        iFile.close();
    }
    else {
        QMessageBox::information(this, "Warning",
            "Cannot open the file.", QMessageBox::Yes);
    }
}

QWidget* trim_signal::PlotSignal()
{
    if(vecDataTrim.size()<1)
        return ui->trim_signal_main;

	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(5, 5, 5, 5);
	//给tab添加滚动条
	QScrollArea *scroll = new QScrollArea;
	scroll->setWidget(ui->trim_signal_main);
	layout->addWidget(scroll);
	setLayout(layout);

    PlotOneByOne(x_axis, ui->widget_x);
    PlotOneByOne(y_axis, ui->widget_y);
    PlotOneByOne(z_axis, ui->widget_z);
    PlotOneByOne(o_axis, ui->widget);
    //ui->offline_edit_main->repaint();

	return ui->trim_signal_main;
}

void trim_signal::PlotOneByOne(
	SigTypeByAxis axis,
    QWidget *widget)
{
	widget->setStyleSheet("background-color:rgb(200, 233, 168)");
	QwtPlot *plot = new QwtPlot(widget);
	//设置最小画布
	//plot->setMinimumSize(550, 200);
	//设置控件的大小
	//int w = widget->width();
	//plot->resize(widget->width() - 5, widget->height() - 5);
	//移动QwtPlot控件到父窗口的(0,0)起始位
	plot->resize(widget->width(), widget->height());
	plot->move(0, 0);
	plot->setAutoFillBackground(true);
	Init_QwtPlot(plot);
	//plot->setAxisScale(QwtPlot::xBottom, data_x[0],
	//	data_x[sizeof(data_x) - 1], 100);
	//plot->axisAutoScale(true);
	plot->setAutoReplot(true);
	QFont font("msyh", 10);
	plot->setFont(font);
	plot->setAxisTitle(QwtPlot::yLeft, "a / mm^2");
    //计算曲线数据
    QVector<double> xs;
    QVector<double> ys;
	switch (axis)
	{
	case x_axis:
        plot->setAxisTitle(QwtPlot::xBottom,
                           "x direction /mm");
        for(auto item:vecDataTrim){
            xs.push_back(item.t);
            ys.push_back(item.x);
        }
		break;
	case y_axis:
        plot->setAxisTitle(QwtPlot::xBottom,
                           "y direction /mm");
        for(auto item:vecDataTrim){
            xs.push_back(item.t);
            ys.push_back(item.y);
        }
		break;
	case z_axis:
        plot->setAxisTitle(QwtPlot::xBottom,
                           "z direction /mm");
        for(auto item:vecDataTrim){
            xs.push_back(item.t);
            ys.push_back(item.z);
        }
		break;
	case o_axis:
        plot->setAxisTitle(QwtPlot::xBottom,
                           "o direction /mm");
        for(auto item:vecDataTrim){
            xs.push_back(item.t);
            ys.push_back(item.o);
        }
		break;
	default:
		break;
	}

	//构造曲线数据
	QwtPlotCurve *curve = new QwtPlotCurve("Signal");
	curve->attach(plot);
	curve->setSamples(xs, ys);
	//设置曲线上是点还是线，默认是线
	curve->setStyle(QwtPlotCurve::Lines); //Dots
	//使曲线更光滑，不加这句曲线会很硬朗，有折点
	curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
	//设置画笔
	curve->setPen(QPen(Qt::green));

	//画布纵横比
	//QwtPlotRescaler *rescaler = new QwtPlotRescaler(
	//	plot->canvas(), plot->xBottom, QwtPlotRescaler::Expanding);
	//rescaler->setExpandingDirection(QwtPlotRescaler::ExpandBoth);
	plot->replot();
}

void trim_signal::Init_QwtPlot(QwtPlot *plot)
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
	//使用鼠标左键平移
	//(void) new QwtPlotPanner(plot->canvas());
	//鼠标左键选择区域放大：（右键还原）
	QwtPlotZoomer *zoomer = new QwtPlotZoomer(plot->canvas());
	zoomer->setRubberBandPen(QColor(Qt::yellow));
	zoomer->setTrackerPen(QColor(Qt::blue));
	zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
		Qt::RightButton, Qt::ControlModifier);
	//zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
	//	Qt::RightButton);
	//QwtPlot重绘， 重要，否则不起作用，添加数据后需要重绘
	plot->replot();
}



//void offline_edit::slot_showRightMenu()
//{
//	QMenu *menu = new QMenu(ui->offline_edit_main);
//	QAction *zoom_action = new QAction("zoom", this);
//	QAction *edit_action = new QAction("edit", this);
//	QAction *close_action = new QAction("close", this);
//	menu->addAction(zoom_action);
//	menu->addAction(edit_action);
//	menu->addAction(close_action);
//	menu->exec(QCursor::pos());
//}
