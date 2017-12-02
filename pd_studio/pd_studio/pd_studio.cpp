#include "pd_studio.h"
#include "ui_pd_studio.h"
#include <string>
#include <qfileinfo.h>
#include <qfiledialog.h>
#include <fstream>
#include <qmessagebox.h>
#include <QDateTime>
#include "qfft.h"
#include "qcomplex.h"
#include <qwidget.h>
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
    connect(ui.btn_filter_update, SIGNAL(clicked(bool)),
            this, SLOT(slot_Filter_Update()));
    connect(ui.rbtn_fft, SIGNAL(clicked(bool)),
            this, SLOT(slot_FFT_Trans()));
    connect(ui.btn_fTrans_update, SIGNAL(clicked(bool)),
            this, SLOT(slot_FFT_Update()));
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

	slot_CloseTab(1);
    QWidget *widget = trim->SlotTrimSave(resul_acc, begin, end);
    ui.tabWidget_main->insertTab(1, widget, "Signal");
}

void pd_studio::slot_Trim_Reset()
{
    slot_CloseTab(ui.tabWidget_main->currentIndex());
    QWidget *widget = trim->SlotTrimReset();
    ui.tabWidget_main->insertTab(1, widget, "Signal");
    //trim->SlotTrimReset();
}

void pd_studio::slot_Trim_Export()
{
	trim->SlotTrimExport();
}

void pd_studio::slot_Filter()
{
    if(resul_acc.size()<1){
        QMessageBox::information(NULL, "Warning",
                     "No data to filt!",
                     QMessageBox::Yes);
        return;
    }

	slot_CloseTab(2); //2是针对滤波的编号
	Filter_SetWidget();
	/*filter_bandpass* filter = new filter_bandpass(resul_acc);
	filter->FiltData(filter_acc);

	QWidget *widget = filter->ShowResult(ui.tabWidget_main->width(),
		ui.tabWidget_main->height());
	ui.tabWidget_main->insertTab(2, widget, "Filter");
	filter->~filter_bandpass();*/
	//Filter_SetWidget();
}

void pd_studio::Filter_SetWidget()
{
	filter_bandpass* filter = new filter_bandpass(resul_acc);
	if (filter_acc.size() != resul_acc.size()) {
		filter_acc.clear();
		for (auto item : resul_acc) {
			filter_acc.push_back(item);
		}
	}
	filter->FiltData(filter_acc);

	QWidget *widget_sign = new QWidget();
	QWidget *widget_filt = new QWidget();
	int w = ui.tabWidget_main->width() - 50;
	int h = ui.tabWidget_main->height() - 50;
	widget_sign->resize(w / 2 - 20, h);
	widget_filt->resize(w / 2 - 20, h);
	widget_sign->setMinimumSize(285, 240);
	widget_filt->setMinimumSize(285, 240);
	QString title_sign = "Signal Section";
	QString title_filt = "After Filted";
	filter->PlotFilted(widget_sign, title_sign, resul_acc);
	filter->PlotFilted(widget_filt, title_filt, filter_acc);
	filter->~filter_bandpass();

	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addWidget(widget_sign);
	hLayout->addWidget(widget_filt);
	QWidget *widget_main = new QWidget();
	//hLayout->addWidget(widget_main);
	//hLayout->addLayout(vLayout);
	widget_main->setLayout(hLayout);

	ui.tabWidget_main->insertTab(2, widget_main, "Filter");
}

void pd_studio::slot_Filter_Update()
{
	slot_Filter();
}
 
void pd_studio::slot_FFT_Trans()
{
	if (fft_acc.size() < 1)
		FFT_Trans();
	
	QWidget *widget = new QWidget();
	widget->setBaseSize(ui.tabWidget_main->width() - 60,
		ui.tabWidget_main->height() - 60);
	PlotFFT(widget, fft_acc, SAMPLE);
	ui.tabWidget_main->insertTab(3, widget, "FFT");
}

void pd_studio::FFT_Trans()
{
	if (filter_acc.size() < 1) {
		filter_bandpass* filter = new filter_bandpass(resul_acc);
		filter->FiltData(filter_acc);
		filter->~filter_bandpass();
	}

	vector<Complex> xs;
	vector<Complex> ys;
	for (auto item : filter_acc) {
		Complex temp(item.data, 0.0);
		xs.push_back(temp);
	}
	Complex temp(0.0, 0.0);
	for (int i = 0; i < SAMPLE; i++) {
		ys.push_back(temp);
	}

	FFT(&xs[0], &ys[0], SAMPLE);
	for (int i = 0; i < SAMPLE; i++) {
		fft_acc.push_back(ys[i].Abs());
	}
}

void pd_studio::slot_FFT_Update()
{
    slot_CloseTab(3); //31是针对FFT的编号

    if (fft_acc.size() < 1)
        FFT_Trans();

	QWidget *widget = new QWidget();
	PlotFFT(widget, fft_acc, SAMPLE);
    ui.tabWidget_main->insertTab(3, widget, "FFT");
}
