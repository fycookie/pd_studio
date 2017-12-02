/********************************************************************************
** Form generated from reading UI file 'filter_bandpass.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_BANDPASS_H
#define UI_FILTER_BANDPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filter_bandpass
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QWidget *wgt_main;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *wgt_signal;
    QWidget *wgt_filter;

    void setupUi(QWidget *filter_bandpass)
    {
        if (filter_bandpass->objectName().isEmpty())
            filter_bandpass->setObjectName(QStringLiteral("filter_bandpass"));
        filter_bandpass->resize(750, 450);
        filter_bandpass->setMinimumSize(QSize(750, 300));
        filter_bandpass->setStyleSheet(QStringLiteral("background-color: rgb(200, 233, 168);"));
        horizontalLayout_4 = new QHBoxLayout(filter_bandpass);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        wgt_main = new QWidget(filter_bandpass);
        wgt_main->setObjectName(QStringLiteral("wgt_main"));
        wgt_main->setMinimumSize(QSize(570, 300));
        horizontalLayout_3 = new QHBoxLayout(wgt_main);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        wgt_signal = new QWidget(wgt_main);
        wgt_signal->setObjectName(QStringLiteral("wgt_signal"));
        wgt_signal->setMinimumSize(QSize(280, 300));

        horizontalLayout_2->addWidget(wgt_signal);

        wgt_filter = new QWidget(wgt_main);
        wgt_filter->setObjectName(QStringLiteral("wgt_filter"));
        wgt_filter->setMinimumSize(QSize(280, 300));

        horizontalLayout_2->addWidget(wgt_filter);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(wgt_main);


        horizontalLayout_4->addLayout(horizontalLayout);


        retranslateUi(filter_bandpass);

        QMetaObject::connectSlotsByName(filter_bandpass);
    } // setupUi

    void retranslateUi(QWidget *filter_bandpass)
    {
        filter_bandpass->setWindowTitle(QApplication::translate("filter_bandpass", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class filter_bandpass: public Ui_filter_bandpass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_BANDPASS_H
