/********************************************************************************
** Form generated from reading UI file 'addcategoriedialog.ui'
**
** Created: Thu Jul 5 12:23:06 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCATEGORIEDIALOG_H
#define UI_ADDCATEGORIEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCategorieDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_newCategorie;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddCategorieDialog)
    {
        if (AddCategorieDialog->objectName().isEmpty())
            AddCategorieDialog->setObjectName(QString::fromUtf8("AddCategorieDialog"));
        AddCategorieDialog->resize(400, 90);
        verticalLayout = new QVBoxLayout(AddCategorieDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lineEdit_newCategorie = new QLineEdit(AddCategorieDialog);
        lineEdit_newCategorie->setObjectName(QString::fromUtf8("lineEdit_newCategorie"));

        verticalLayout->addWidget(lineEdit_newCategorie);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AddCategorieDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddCategorieDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddCategorieDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddCategorieDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddCategorieDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCategorieDialog)
    {
        AddCategorieDialog->setWindowTitle(QApplication::translate("AddCategorieDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddCategorieDialog: public Ui_AddCategorieDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCATEGORIEDIALOG_H
