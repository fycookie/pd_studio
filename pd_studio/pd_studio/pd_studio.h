#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pd_studio.h"
#include "global_data.h"
#include "trim_signal.h"
#include <fstream>

using namespace std;

class pd_studio : public QMainWindow
{
	Q_OBJECT

public:
	pd_studio(QWidget *parent = Q_NULLPTR);
	~pd_studio() {}

private:
    Ui::pd_studio_qmainwindow ui;
	trim_signal *trim;

private slots:
    void slot_FileImport();
    void slot_CloseTab(int index);
    //Trim GroupBox
    void slot_Trim_Export();
    void slot_Trim_Reset();
    void slot_Trim_Save();
	void slot_Update();
};
