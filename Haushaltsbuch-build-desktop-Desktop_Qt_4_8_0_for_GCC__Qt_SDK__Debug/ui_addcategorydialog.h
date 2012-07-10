/********************************************************************************
** Form generated from reading UI file 'addcategorydialog.ui'
**
** Created: Tue Jul 10 12:52:07 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCATEGORYDIALOG_H
#define UI_ADDCATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCategoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_newCategorie;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *AddCategoryDialog)
    {
        if (AddCategoryDialog->objectName().isEmpty())
            AddCategoryDialog->setObjectName(QString::fromUtf8("AddCategoryDialog"));
        AddCategoryDialog->resize(400, 78);
        verticalLayout = new QVBoxLayout(AddCategoryDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_newCategorie = new QLineEdit(AddCategoryDialog);
        lineEdit_newCategorie->setObjectName(QString::fromUtf8("lineEdit_newCategorie"));

        verticalLayout->addWidget(lineEdit_newCategorie);

        widget = new QWidget(AddCategoryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Cancel = new QPushButton(widget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        pushButton_OK = new QPushButton(widget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(lineEdit_newCategorie, pushButton_OK);
        QWidget::setTabOrder(pushButton_OK, pushButton_Cancel);

        retranslateUi(AddCategoryDialog);

        QMetaObject::connectSlotsByName(AddCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCategoryDialog)
    {
        AddCategoryDialog->setWindowTitle(QApplication::translate("AddCategoryDialog", "Add Category", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("AddCategoryDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("AddCategoryDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddCategoryDialog: public Ui_AddCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCATEGORYDIALOG_H
