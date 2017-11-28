#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pd_studio.h"
#include "global_data.h"
#include "trim_signal.h"
#include "filter_bandpass.h"
#include <fstream>
#include <vector>

using std::vector;
namespace Ui {
	class pd_studio;
}

class pd_studio : public QMainWindow
{
	Q_OBJECT

public:
	pd_studio(QWidget *parent = Q_NULLPTR);
	~pd_studio() {}

private:
    Ui::pd_studio ui;
	trim_signal *trim;
	filter_bandpass *filter;
    vector<ResultantAcc> resul_acc;
	vector<ResultantAcc> filter_acc;

private slots:
    void slot_FileImport();
    void slot_CloseTab(int index);
    //Trim GroupBox
    void slot_Trim_Export();
    void slot_Trim_Reset();
    void slot_Trim_Save();
	void slot_Update();
    //Data Process
    void slot_Filter();
    void slot_Filter_Update();
};
