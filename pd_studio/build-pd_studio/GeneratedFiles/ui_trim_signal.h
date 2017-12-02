/********************************************************************************
** Form generated from reading UI file 'trim_signal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIM_SIGNAL_H
#define UI_TRIM_SIGNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trim_signal
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *trim_signal_main;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QWidget *widget_z;
    QWidget *widget_x;
    QWidget *widget_y;
    QWidget *widget;

    void setupUi(QWidget *trim_signal)
    {
        if (trim_signal->objectName().isEmpty())
            trim_signal->setObjectName(QStringLiteral("trim_signal"));
        trim_signal->resize(570, 371);
        trim_signal->setMinimumSize(QSize(570, 270));
        horizontalLayout = new QHBoxLayout(trim_signal);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        trim_signal_main = new QWidget(trim_signal);
        trim_signal_main->setObjectName(QStringLiteral("trim_signal_main"));
        trim_signal_main->setMinimumSize(QSize(570, 300));
        trim_signal_main->setLayoutDirection(Qt::LeftToRight);
        trim_signal_main->setAutoFillBackground(false);
        trim_signal_main->setStyleSheet(QStringLiteral("background-color: rgb(200, 233, 168);"));
        verticalLayout = new QVBoxLayout(trim_signal_main);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_z = new QWidget(trim_signal_main);
        widget_z->setObjectName(QStringLiteral("widget_z"));
        widget_z->setMinimumSize(QSize(200, 100));
        widget_z->setMaximumSize(QSize(500, 16777215));
        widget_z->setMouseTracking(true);
        widget_z->setLayoutDirection(Qt::LeftToRight);
        widget_z->setAutoFillBackground(false);

        gridLayout->addWidget(widget_z, 2, 0, 1, 1);

        widget_x = new QWidget(trim_signal_main);
        widget_x->setObjectName(QStringLiteral("widget_x"));
        widget_x->setMinimumSize(QSize(200, 100));
        widget_x->setMaximumSize(QSize(500, 16777215));
        widget_x->setMouseTracking(true);
        widget_x->setLayoutDirection(Qt::LeftToRight);
        widget_x->setAutoFillBackground(false);

        gridLayout->addWidget(widget_x, 0, 0, 1, 1);

        widget_y = new QWidget(trim_signal_main);
        widget_y->setObjectName(QStringLiteral("widget_y"));
        widget_y->setMinimumSize(QSize(200, 100));
        widget_y->setMaximumSize(QSize(500, 16777215));
        widget_y->setMouseTracking(true);
        widget_y->setLayoutDirection(Qt::LeftToRight);
        widget_y->setAutoFillBackground(false);

        gridLayout->addWidget(widget_y, 1, 0, 1, 1);

        widget = new QWidget(trim_signal_main);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(150, 300));

        gridLayout->addWidget(widget, 0, 1, 3, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addWidget(trim_signal_main);


        retranslateUi(trim_signal);
        QObject::connect(trim_signal_main, SIGNAL(customContextMenuRequested(QPoint)), trim_signal, SLOT(slot_showRightMenu()));

        QMetaObject::connectSlotsByName(trim_signal);
    } // setupUi

    void retranslateUi(QWidget *trim_signal)
    {
        trim_signal->setWindowTitle(QApplication::translate("trim_signal", "offline_edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trim_signal: public Ui_trim_signal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIM_SIGNAL_H
