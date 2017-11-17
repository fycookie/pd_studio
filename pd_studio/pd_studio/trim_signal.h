#pragma once
#include "ui_trim_signal.h"
#include <vector>
#include <qwidget.h>
#include "global_data.h"
#include "QWT\qwt_plot.h"

using namespace std;

namespace Ui {
	class trim_signal;
}

class trim_signal:public QWidget
{
	Q_OBJECT

public:
	trim_signal(QWidget *parent = Q_NULLPTR);
	~trim_signal();

private:
	Ui::trim_signal *ui;
    char buffer[256];
    SignalData signal;
    vector<SignalData> vecSignal;
    vector<SignalData> vecDataTrim;

//For slots
public:
    void SlotTrimSave(double begin, double end);
    void SlotTrimReset();
    void SlotTrimExport();
    void SlotTrimUpdate(QWidget *widget);

private:
    void ReadCSV(string fPath);
	void PlotOneByOne(SigTypeByAxis axis,
        QWidget *widget);
	void Init_QwtPlot(QwtPlot *plot);

public:
	void ReadFile(FileSuffixType fType,
		string fPath);
	QWidget* PlotSignal();
};
