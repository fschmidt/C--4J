/********************************************************************************
** Form generated from reading UI file 'deletecategorydialog.ui'
**
** Created: Mon Jul 9 15:53:04 2012
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
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteCategoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView_Category;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *deleteCategoryDialog)
    {
        if (deleteCategoryDialog->objectName().isEmpty())
            deleteCategoryDialog->setObjectName(QString::fromUtf8("deleteCategoryDialog"));
        deleteCategoryDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(deleteCategoryDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView_Category = new QListView(deleteCategoryDialog);
        listView_Category->setObjectName(QString::fromUtf8("listView_Category"));

        verticalLayout->addWidget(listView_Category);

        widget = new QWidget(deleteCategoryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Delete = new QPushButton(widget);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));

        horizontalLayout->addWidget(pushButton_Delete);

        pushButton_OK = new QPushButton(widget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);


        verticalLayout->addWidget(widget);


        retranslateUi(deleteCategoryDialog);

        QMetaObject::connectSlotsByName(deleteCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *deleteCategoryDialog)
    {
        deleteCategoryDialog->setWindowTitle(QApplication::translate("deleteCategoryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_Delete->setText(QApplication::translate("deleteCategoryDialog", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("deleteCategoryDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class deleteCategoryDialog: public Ui_deleteCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECATEGORYDIALOG_H
