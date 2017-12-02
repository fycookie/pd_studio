#pragma once
#include "ui_filter_bandpass.h"
#include "filter_bandpass.h"
#include "global_data.h"
#include <qwidget.h>
#include <vector>
#include "QWT\qwt_plot.h"
#include "QWT\qwt_plot_curve.h"
#include "QWT\qwt_plot_magnifier.h"
#include "QWT\qwt_plot_panner.h"
#include "QWT\qwt_plot_zoomer.h"
#include "QWT\qwt_legend.h"
#include "QWT\qwt_plot_grid.h"
#include "QWT\qwt_plot_rescaler.h"


using std::vector;

namespace Ui {
	class filter_bandpass;
}

class filter_bandpass:public QWidget
{
	Q_OBJECT

public:
	filter_bandpass(vector<ResultantAcc> acc,
		QWidget *parent = Q_NULLPTR);
	~filter_bandpass();

private:
	Ui::filter_bandpass *ui;
	vector<double> filter_sig;
	vector<double> filter_time;
    vector<double> filted;

public:
	int FiltData(vector<ResultantAcc> &v_ra);
	QWidget* ShowResult(int w, int h);
	void ShowOneByOne(QWidget *widget, bool flag,
        vector<double> ydata);
	void PlotFilted(QWidget *widget, QString title,
		vector<ResultantAcc> data);

private:
	void SigConv();
	void Convolution(vector<double> signal,
		vector<double> coefs);
	void Init_QwtPlot(QwtPlot *plot);
};

