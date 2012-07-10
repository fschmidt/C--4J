/********************************************************************************
** Form generated from reading UI file 'showinputdialog.ui'
**
** Created: Tue Jul 10 13:05:55 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINPUTDIALOG_H
#define UI_SHOWINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowInputDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *dateEdit_From;
    QLabel *label_3;
    QDateEdit *dateEdit_To;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Show;
    QTableView *tableView_input;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *ShowInputDialog)
    {
        if (ShowInputDialog->objectName().isEmpty())
            ShowInputDialog->setObjectName(QString::fromUtf8("ShowInputDialog"));
        ShowInputDialog->resize(681, 312);
        verticalLayout = new QVBoxLayout(ShowInputDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new QWidget(ShowInputDialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit_From = new QDateEdit(widget_2);
        dateEdit_From->setObjectName(QString::fromUtf8("dateEdit_From"));
        dateEdit_From->setDateTime(QDateTime(QDate(2012, 1, 1), QTime(2, 0, 0)));
        dateEdit_From->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_From);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateEdit_To = new QDateEdit(widget_2);
        dateEdit_To->setObjectName(QString::fromUtf8("dateEdit_To"));
        dateEdit_To->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        dateEdit_To->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_To);


        horizontalLayout_4->addWidget(widget_2);

        horizontalSpacer_3 = new QSpacerItem(226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_Show = new QPushButton(widget_4);
        pushButton_Show->setObjectName(QString::fromUtf8("pushButton_Show"));

        horizontalLayout_4->addWidget(pushButton_Show);


        verticalLayout->addWidget(widget_4);

        tableView_input = new QTableView(ShowInputDialog);
        tableView_input->setObjectName(QString::fromUtf8("tableView_input"));
        tableView_input->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_input->setSortingEnabled(true);

        verticalLayout->addWidget(tableView_input);

        widget_5 = new QWidget(ShowInputDialog);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(273, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        doubleSpinBox = new QDoubleSpinBox(widget_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimumSize(QSize(300, 0));
        doubleSpinBox->setReadOnly(true);

        horizontalLayout_3->addWidget(doubleSpinBox);


        horizontalLayout_5->addWidget(widget_3);


        verticalLayout->addWidget(widget_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(ShowInputDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_OK = new QPushButton(widget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);


        verticalLayout->addWidget(widget);


        retranslateUi(ShowInputDialog);

        QMetaObject::connectSlotsByName(ShowInputDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowInputDialog)
    {
        ShowInputDialog->setWindowTitle(QApplication::translate("ShowInputDialog", "Input Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ShowInputDialog", "Date:   ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ShowInputDialog", "Between", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ShowInputDialog", "and", 0, QApplication::UnicodeUTF8));
        pushButton_Show->setText(QApplication::translate("ShowInputDialog", "show", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ShowInputDialog", "Summe: ", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("ShowInputDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShowInputDialog: public Ui_ShowInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINPUTDIALOG_H
