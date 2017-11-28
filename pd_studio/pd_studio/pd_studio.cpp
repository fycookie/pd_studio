#include "pd_studio.h"
#include "ui_pd_studio.h"
#include <string>
#include <qfileinfo.h>
#include <qfiledialog.h>
#include <fstream>
#include <qmessagebox.h>
#include <QDateTime>

using namespace std;

pd_studio::pd_studio(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tabWidget_main->tabsClosable();
    connect(ui.tabWidget_main, SIGNAL(tabCloseRequested(int)),
            this, SLOT(slot_CloseTab(int)));
    connect(ui.btn_import, SIGNAL(clicked(bool)),
            this, SLOT(slot_FileImport()));
    connect(ui.btn_trim_export, SIGNAL(clicked(bool)),
            this, SLOT(slot_Trim_Export()));
    connect(ui.btn_trim_reset, SIGNAL(clicked(bool)),
            this, SLOT(slot_Trim_Reset()));
    connect(ui.btn_trim_save, SIGNAL(clicked(bool)),
            this, SLOT(slot_Trim_Save()));
    connect(ui.btn_filter, SIGNAL(clicked(bool)),
            this, SLOT(slot_Filter()));
	connect(ui.btn_filter_update, SIGNAL(cliked(bool)),
		this, SLOT(slot_Filter_Update()));
}

void pd_studio::slot_FileImport()
{
	QString fileFull;
    QFileInfo fileInfo;
	fileFull = QFileDialog::getOpenFileName();
	fileInfo = QFileInfo(fileFull);
	string fileSuffix = fileInfo.suffix().toStdString();
	string filePath = fileInfo.absoluteFilePath().toStdString();

	if (fileSuffix == "csv") {
        trim = new trim_signal();
		trim->ReadFile(csv, filePath);
		QWidget *widget = trim->PlotSignal();
        ui.tabWidget_main->insertTab(11, widget, "Signal");
	}
}

void pd_studio::slot_CloseTab(int index)
{
	ui.tabWidget_main->removeTab(index);
}

void pd_studio::slot_Trim_Save()
{
    double begin=ui.lineEdit_beginwith->text().toDouble();
    double end = ui.lineEdit_endwith->text().toDouble();
    if( begin > end)
    {
        QMessageBox::information(NULL, "Warning",
                     "Begin number cannot be bigger than end number!",
                     QMessageBox::Yes);
        return;
    }

    slot_CloseTab(ui.tabWidget_main->currentIndex());
    QWidget *widget = trim->SlotTrimSave(resul_acc, begin, end);
    ui.tabWidget_main->insertTab(11, widget, "Signal");
    //trim->SlotTrimSave(begin, end);
}

void pd_studio::slot_Trim_Reset()
{
    slot_CloseTab(ui.tabWidget_main->currentIndex());
    QWidget *widget = trim->SlotTrimReset();
    ui.tabWidget_main->insertTab(11, widget, "Signal");
    //trim->SlotTrimReset();
}

void pd_studio::slot_Trim_Export()
{
	trim->SlotTrimExport();
}

void pd_studio::slot_Update()
{
    slot_CloseTab(ui.tabWidget_main->currentIndex());
    QWidget *widget = trim->SlotTrimUpdate();
    ui.tabWidget_main->insertTab(11, widget, "Signal");
//    if(ui.tabWidget_main->currentIndex()==11){
//        trim->SlotTrimUpdate(ui.tabWidget_main->currentWidget());
//    }
}

void pd_studio::slot_Filter()
{
	slot_CloseTab(21);

    if(resul_acc.size()<1){
        QMessageBox::information(NULL, "Warning",
                     "No data to filt!",
                     QMessageBox::Yes);
        return;
    }

	filter = new filter_bandpass(resul_acc);
	filter->FiltData(filter_acc);
    QWidget *widget = filter->ShowResult();
    ui.tabWidget_main->insertTab(21, widget, "Filter");
}

void pd_studio::slot_Filter_Update()
{
    slot_CloseTab(21); //21ÊÇÕë¶ÔÂË²¨µÄ±àºÅ
	if (filter_acc.size() < 1) {
		filter = new filter_bandpass(resul_acc);
		filter->FiltData(filter_acc);
	}

    QWidget *widget = filter->ShowResult();
    ui.tabWidget_main->insertTab(21, widget, "Filter");
}
 