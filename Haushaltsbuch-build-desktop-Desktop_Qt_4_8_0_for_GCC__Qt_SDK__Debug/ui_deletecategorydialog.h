/********************************************************************************
** Form generated from reading UI file 'deletecategorydialog.ui'
**
** Created: Tue Jul 10 12:52:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECATEGORYDIALOG_H
#define UI_DELETECATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteCategoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView_Category;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Delete;

    void setupUi(QDialog *deleteCategoryDialog)
    {
        if (deleteCategoryDialog->objectName().isEmpty())
            deleteCategoryDialog->setObjectName(QString::fromUtf8("deleteCategoryDialog"));
        deleteCategoryDialog->setEnabled(true);
        deleteCategoryDialog->resize(400, 229);
        verticalLayout = new QVBoxLayout(deleteCategoryDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView_Category = new QTableView(deleteCategoryDialog);
        tableView_Category->setObjectName(QString::fromUtf8("tableView_Category"));
        tableView_Category->setEnabled(true);
        tableView_Category->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_Category->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView_Category);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(deleteCategoryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Cancel = new QPushButton(widget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        pushButton_Delete = new QPushButton(widget);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));

        horizontalLayout->addWidget(pushButton_Delete);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(pushButton_Cancel, pushButton_Delete);

        retranslateUi(deleteCategoryDialog);

        QMetaObject::connectSlotsByName(deleteCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *deleteCategoryDialog)
    {
        deleteCategoryDialog->setWindowTitle(QApplication::translate("deleteCategoryDialog", "Delete Category", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("deleteCategoryDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_Delete->setText(QApplication::translate("deleteCategoryDialog", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class deleteCategoryDialog: public Ui_deleteCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECATEGORYDIALOG_H
