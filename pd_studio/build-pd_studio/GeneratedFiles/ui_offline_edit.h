/********************************************************************************
** Form generated from reading UI file 'offline_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFLINE_EDIT_H
#define UI_OFFLINE_EDIT_H

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

class Ui_offline_edit
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *offline_edit_main;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QWidget *widget_z;
    QWidget *widget_x;
    QWidget *widget_y;
    QWidget *widget;

    void setupUi(QWidget *offline_edit)
    {
        if (offline_edit->objectName().isEmpty())
            offline_edit->setObjectName(QStringLiteral("offline_edit"));
        offline_edit->resize(834, 468);
        horizontalLayout = new QHBoxLayout(offline_edit);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        offline_edit_main = new QWidget(offline_edit);
        offline_edit_main->setObjectName(QStringLiteral("offline_edit_main"));
        offline_edit_main->setMinimumSize(QSize(800, 450));
        offline_edit_main->setLayoutDirection(Qt::LeftToRight);
        offline_edit_main->setAutoFillBackground(false);
        offline_edit_main->setStyleSheet(QStringLiteral("background-color: rgb(200, 233, 168);"));
        verticalLayout = new QVBoxLayout(offline_edit_main);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_z = new QWidget(offline_edit_main);
        widget_z->setObjectName(QStringLiteral("widget_z"));
        widget_z->setMinimumSize(QSize(400, 170));
        widget_z->setMaximumSize(QSize(500, 16777215));
        widget_z->setMouseTracking(true);
        widget_z->setLayoutDirection(Qt::LeftToRight);
        widget_z->setAutoFillBackground(false);

        gridLayout->addWidget(widget_z, 2, 0, 1, 1);

        widget_x = new QWidget(offline_edit_main);
        widget_x->setObjectName(QStringLiteral("widget_x"));
        widget_x->setMinimumSize(QSize(400, 170));
        widget_x->setMaximumSize(QSize(500, 16777215));
        widget_x->setMouseTracking(true);
        widget_x->setLayoutDirection(Qt::LeftToRight);
        widget_x->setAutoFillBackground(false);

        gridLayout->addWidget(widget_x, 0, 0, 1, 1);

        widget_y = new QWidget(offline_edit_main);
        widget_y->setObjectName(QStringLiteral("widget_y"));
        widget_y->setMinimumSize(QSize(400, 170));
        widget_y->setMaximumSize(QSize(500, 16777215));
        widget_y->setMouseTracking(true);
        widget_y->setLayoutDirection(Qt::LeftToRight);
        widget_y->setAutoFillBackground(false);

        gridLayout->addWidget(widget_y, 1, 0, 1, 1);

        widget = new QWidget(offline_edit_main);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 0, 1, 3, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addWidget(offline_edit_main);


        retranslateUi(offline_edit);
        QObject::connect(offline_edit_main, SIGNAL(customContextMenuRequested(QPoint)), offline_edit, SLOT(slot_showRightMenu()));

        QMetaObject::connectSlotsByName(offline_edit);
    } // setupUi

    void retranslateUi(QWidget *offline_edit)
    {
        offline_edit->setWindowTitle(QApplication::translate("offline_edit", "offline_edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class offline_edit: public Ui_offline_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFLINE_EDIT_H
