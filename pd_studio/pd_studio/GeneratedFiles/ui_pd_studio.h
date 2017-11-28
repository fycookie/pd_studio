/********************************************************************************
** Form generated from reading UI file 'pd_studio.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PD_STUDIO_H
#define UI_PD_STUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pd_studio
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_menu;
    QWidget *tab_file;
    QWidget *tab_data_collect;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QSpacerItem *data_collect_horizontalSpacer;
    QWidget *tab_data_deal;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *gbox_data;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn_import;
    QPushButton *btn_update;
    QGroupBox *gbox_dataCut;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *glt_dataTrim_beginWith;
    QLineEdit *lineEdit_beginwith;
    QLabel *label_beginwith;
    QGridLayout *glt_dataTrim_endWith;
    QLineEdit *lineEdit_endwith;
    QLabel *label_endwith;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_trim_reset;
    QPushButton *btn_trim_save;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_trim_export;
    QGroupBox *gbox_trans;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_filter;
    QPushButton *btn_filter_update;
    QVBoxLayout *vlt_freq;
    QRadioButton *rbtn_fft;
    QRadioButton *rbtn_wavelet;
    QSpacerItem *data_deal_horizontalSpacer;
    QTabWidget *tabWidget_main;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pd_studio)
    {
        if (pd_studio->objectName().isEmpty())
            pd_studio->setObjectName(QStringLiteral("pd_studio"));
        pd_studio->resize(800, 600);
        pd_studio->setMinimumSize(QSize(800, 600));
        pd_studio->setStyleSheet(QStringLiteral("background-color: rgb(177, 203, 210);"));
        centralWidget = new QWidget(pd_studio);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget_menu = new QTabWidget(centralWidget);
        tabWidget_menu->setObjectName(QStringLiteral("tabWidget_menu"));
        tabWidget_menu->setEnabled(true);
        tabWidget_menu->setMinimumSize(QSize(630, 100));
        tabWidget_menu->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        tabWidget_menu->setFont(font);
        tabWidget_menu->setToolTipDuration(0);
        tabWidget_menu->setStyleSheet(QStringLiteral(""));
        tab_file = new QWidget();
        tab_file->setObjectName(QStringLiteral("tab_file"));
        tab_file->setStyleSheet(QStringLiteral("border-color: rgb(64, 64, 64);"));
        tabWidget_menu->addTab(tab_file, QString());
        tab_data_collect = new QWidget();
        tab_data_collect->setObjectName(QStringLiteral("tab_data_collect"));
        tab_data_collect->setEnabled(true);
        tab_data_collect->setMaximumSize(QSize(16777215, 100));
        tab_data_collect->setLayoutDirection(Qt::LeftToRight);
        tab_data_collect->setAutoFillBackground(false);
        tab_data_collect->setStyleSheet(QLatin1String("border-color: rgb(64, 64, 64);\n"
"background-color: rgb(170, 255, 255);"));
        layoutWidget = new QWidget(tab_data_collect);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 671, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(70, 70));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(70, 70));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(70, 70));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(70, 70));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(70, 70));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(70, 70));
        pushButton_6->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(70, 70));
        pushButton_7->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(70, 70));
        pushButton_8->setStyleSheet(QStringLiteral("background-color: rgb(235, 255, 160);"));

        horizontalLayout->addWidget(pushButton_8);

        data_collect_horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(data_collect_horizontalSpacer);

        tabWidget_menu->addTab(tab_data_collect, QString());
        tab_data_deal = new QWidget();
        tab_data_deal->setObjectName(QStringLiteral("tab_data_deal"));
        layoutWidget1 = new QWidget(tab_data_deal);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1, 6, 547, 76));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gbox_data = new QGroupBox(layoutWidget1);
        gbox_data->setObjectName(QStringLiteral("gbox_data"));
        gbox_data->setMinimumSize(QSize(45, 0));
        gbox_data->setMaximumSize(QSize(120, 16777215));
        horizontalLayout_4 = new QHBoxLayout(gbox_data);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        btn_import = new QPushButton(gbox_data);
        btn_import->setObjectName(QStringLiteral("btn_import"));

        verticalLayout_5->addWidget(btn_import);

        btn_update = new QPushButton(gbox_data);
        btn_update->setObjectName(QStringLiteral("btn_update"));

        verticalLayout_5->addWidget(btn_update);


        horizontalLayout_4->addLayout(verticalLayout_5);


        horizontalLayout_3->addWidget(gbox_data);

        gbox_dataCut = new QGroupBox(layoutWidget1);
        gbox_dataCut->setObjectName(QStringLiteral("gbox_dataCut"));
        gbox_dataCut->setMinimumSize(QSize(200, 44));
        gbox_dataCut->setMaximumSize(QSize(240, 100));
        horizontalLayout_2 = new QHBoxLayout(gbox_dataCut);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        glt_dataTrim_beginWith = new QGridLayout();
        glt_dataTrim_beginWith->setSpacing(6);
        glt_dataTrim_beginWith->setObjectName(QStringLiteral("glt_dataTrim_beginWith"));
        lineEdit_beginwith = new QLineEdit(gbox_dataCut);
        lineEdit_beginwith->setObjectName(QStringLiteral("lineEdit_beginwith"));
        lineEdit_beginwith->setMinimumSize(QSize(0, 20));

        glt_dataTrim_beginWith->addWidget(lineEdit_beginwith, 1, 0, 1, 1);

        label_beginwith = new QLabel(gbox_dataCut);
        label_beginwith->setObjectName(QStringLiteral("label_beginwith"));
        label_beginwith->setMaximumSize(QSize(16777215, 15));

        glt_dataTrim_beginWith->addWidget(label_beginwith, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(glt_dataTrim_beginWith);

        glt_dataTrim_endWith = new QGridLayout();
        glt_dataTrim_endWith->setSpacing(6);
        glt_dataTrim_endWith->setObjectName(QStringLiteral("glt_dataTrim_endWith"));
        lineEdit_endwith = new QLineEdit(gbox_dataCut);
        lineEdit_endwith->setObjectName(QStringLiteral("lineEdit_endwith"));
        lineEdit_endwith->setMinimumSize(QSize(0, 20));

        glt_dataTrim_endWith->addWidget(lineEdit_endwith, 1, 0, 1, 1);

        label_endwith = new QLabel(gbox_dataCut);
        label_endwith->setObjectName(QStringLiteral("label_endwith"));
        label_endwith->setMaximumSize(QSize(16777215, 15));

        glt_dataTrim_endWith->addWidget(label_endwith, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(glt_dataTrim_endWith);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_trim_reset = new QPushButton(gbox_dataCut);
        btn_trim_reset->setObjectName(QStringLiteral("btn_trim_reset"));
        btn_trim_reset->setMaximumSize(QSize(50, 20));

        verticalLayout_2->addWidget(btn_trim_reset);

        btn_trim_save = new QPushButton(gbox_dataCut);
        btn_trim_save->setObjectName(QStringLiteral("btn_trim_save"));
        btn_trim_save->setMaximumSize(QSize(50, 20));

        verticalLayout_2->addWidget(btn_trim_save);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btn_trim_export = new QPushButton(gbox_dataCut);
        btn_trim_export->setObjectName(QStringLiteral("btn_trim_export"));

        verticalLayout_3->addWidget(btn_trim_export);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_3->addWidget(gbox_dataCut);

        gbox_trans = new QGroupBox(layoutWidget1);
        gbox_trans->setObjectName(QStringLiteral("gbox_trans"));
        gbox_trans->setMinimumSize(QSize(150, 0));
        gbox_trans->setMaximumSize(QSize(150, 16777215));
        horizontalLayout_5 = new QHBoxLayout(gbox_trans);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btn_filter = new QPushButton(gbox_trans);
        btn_filter->setObjectName(QStringLiteral("btn_filter"));

        verticalLayout_6->addWidget(btn_filter);

        btn_filter_update = new QPushButton(gbox_trans);
        btn_filter_update->setObjectName(QStringLiteral("btn_filter_update"));

        verticalLayout_6->addWidget(btn_filter_update);


        horizontalLayout_5->addLayout(verticalLayout_6);

        vlt_freq = new QVBoxLayout();
        vlt_freq->setSpacing(6);
        vlt_freq->setObjectName(QStringLiteral("vlt_freq"));
        rbtn_fft = new QRadioButton(gbox_trans);
        rbtn_fft->setObjectName(QStringLiteral("rbtn_fft"));

        vlt_freq->addWidget(rbtn_fft);

        rbtn_wavelet = new QRadioButton(gbox_trans);
        rbtn_wavelet->setObjectName(QStringLiteral("rbtn_wavelet"));

        vlt_freq->addWidget(rbtn_wavelet);


        horizontalLayout_5->addLayout(vlt_freq);


        horizontalLayout_3->addWidget(gbox_trans);

        data_deal_horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(data_deal_horizontalSpacer);

        tabWidget_menu->addTab(tab_data_deal, QString());

        verticalLayout->addWidget(tabWidget_menu);

        tabWidget_main = new QTabWidget(centralWidget);
        tabWidget_main->setObjectName(QStringLiteral("tabWidget_main"));
        tabWidget_main->setMinimumSize(QSize(600, 270));
        tabWidget_main->setMouseTracking(true);
        tabWidget_main->setAcceptDrops(true);
        tabWidget_main->setAutoFillBackground(false);
        tabWidget_main->setStyleSheet(QStringLiteral(""));
        tabWidget_main->setTabsClosable(true);

        verticalLayout->addWidget(tabWidget_main);


        verticalLayout_4->addLayout(verticalLayout);

        pd_studio->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(pd_studio);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        pd_studio->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pd_studio);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pd_studio->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(pd_studio);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pd_studio->setStatusBar(statusBar);

        retranslateUi(pd_studio);
        QObject::connect(tabWidget_main, SIGNAL(tabCloseRequested(int)), pd_studio, SLOT(slot_closeTab()));
        QObject::connect(btn_import, SIGNAL(clicked()), pd_studio, SLOT(slot_fileOpen()));

        tabWidget_menu->setCurrentIndex(2);
        tabWidget_main->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(pd_studio);
    } // setupUi

    void retranslateUi(QMainWindow *pd_studio)
    {
        pd_studio->setWindowTitle(QApplication::translate("pd_studio", "pd_studio", Q_NULLPTR));
        tabWidget_menu->setTabText(tabWidget_menu->indexOf(tab_file), QApplication::translate("pd_studio", "file", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pd_studio", "Measure 1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pd_studio", "Measure 2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("pd_studio", "Measure 3", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pd_studio", "Measure 4", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pd_studio", "Measure 5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("pd_studio", "Measure 6", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("pd_studio", "Measure 7", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("pd_studio", "Measure 8", Q_NULLPTR));
        tabWidget_menu->setTabText(tabWidget_menu->indexOf(tab_data_collect), QApplication::translate("pd_studio", "data_collect", Q_NULLPTR));
        gbox_data->setTitle(QString());
        btn_import->setText(QApplication::translate("pd_studio", "import", Q_NULLPTR));
        btn_update->setText(QString());
        gbox_dataCut->setTitle(QString());
        label_beginwith->setText(QApplication::translate("pd_studio", "Begin with:", Q_NULLPTR));
        label_endwith->setText(QApplication::translate("pd_studio", "End with:", Q_NULLPTR));
        btn_trim_reset->setText(QApplication::translate("pd_studio", "Res", Q_NULLPTR));
        btn_trim_save->setText(QApplication::translate("pd_studio", "Save", Q_NULLPTR));
        btn_trim_export->setText(QApplication::translate("pd_studio", "export", Q_NULLPTR));
        gbox_trans->setTitle(QString());
        btn_filter->setText(QApplication::translate("pd_studio", "filter", Q_NULLPTR));
        btn_filter_update->setText(QApplication::translate("pd_studio", "update", Q_NULLPTR));
        rbtn_fft->setText(QApplication::translate("pd_studio", "fft", Q_NULLPTR));
        rbtn_wavelet->setText(QApplication::translate("pd_studio", "wavelet", Q_NULLPTR));
        tabWidget_menu->setTabText(tabWidget_menu->indexOf(tab_data_deal), QApplication::translate("pd_studio", "data_deal", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pd_studio: public Ui_pd_studio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PD_STUDIO_H
