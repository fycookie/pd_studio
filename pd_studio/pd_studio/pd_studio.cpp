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

	trim->SlotTrimSave(begin, end);
}

void pd_studio::slot_Trim_Reset()
{
	trim->SlotTrimReset();
}

void pd_studio::slot_Trim_Export()
{
	trim->SlotTrimExport();
}

void pd_studio::slot_Update()
{
    if(ui.tabWidget_main->currentIndex()==11){
        trim->SlotTrimUpdate(ui.tabWidget_main->currentWidget());
    }
}
