/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jul 9 15:44:10 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionAdd_Categorie;
    QAction *actionDelete_Categorie;
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_summe;
    QLabel *label_kategorie;
    QComboBox *comboBox_categorie;
    QLabel *label_art;
    QComboBox *comboBox_art;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_beschreibung;
    QTextEdit *textEdit_discription;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_close;
    QLabel *label_Date;
    QDoubleSpinBox *doubleSpinBox_summe;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuDatabase;
    QMenu *menuCategorie;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 339);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAdd_Categorie = new QAction(MainWindow);
        actionAdd_Categorie->setObjectName(QString::fromUtf8("actionAdd_Categorie"));
        actionDelete_Categorie = new QAction(MainWindow);
        actionDelete_Categorie->setObjectName(QString::fromUtf8("actionDelete_Categorie"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_name = new QLabel(centralWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(centralWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        label_summe = new QLabel(centralWidget);
        label_summe->setObjectName(QString::fromUtf8("label_summe"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_summe);

        label_kategorie = new QLabel(centralWidget);
        label_kategorie->setObjectName(QString::fromUtf8("label_kategorie"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_kategorie);

        comboBox_categorie = new QComboBox(centralWidget);
        comboBox_categorie->setObjectName(QString::fromUtf8("comboBox_categorie"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_categorie);

        label_art = new QLabel(centralWidget);
        label_art->setObjectName(QString::fromUtf8("label_art"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_art);

        comboBox_art = new QComboBox(centralWidget);
        comboBox_art->setObjectName(QString::fromUtf8("comboBox_art"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox_art);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, dateTimeEdit);

        label_beschreibung = new QLabel(centralWidget);
        label_beschreibung->setObjectName(QString::fromUtf8("label_beschreibung"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_beschreibung);

        textEdit_discription = new QTextEdit(centralWidget);
        textEdit_discription->setObjectName(QString::fromUtf8("textEdit_discription"));

        formLayout->setWidget(7, QFormLayout::FieldRole, textEdit_discription);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_submit = new QPushButton(widget);
        pushButton_submit->setObjectName(QString::fromUtf8("pushButton_submit"));

        horizontalLayout->addWidget(pushButton_submit);

        pushButton_close = new QPushButton(widget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        horizontalLayout->addWidget(pushButton_close);


        formLayout->setWidget(9, QFormLayout::FieldRole, widget);

        label_Date = new QLabel(centralWidget);
        label_Date->setObjectName(QString::fromUtf8("label_Date"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_Date);

        doubleSpinBox_summe = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_summe->setObjectName(QString::fromUtf8("doubleSpinBox_summe"));

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_summe);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        menuDatabase = new QMenu(menuBar);
        menuDatabase->setObjectName(QString::fromUtf8("menuDatabase"));
        menuCategorie = new QMenu(menuDatabase);
        menuCategorie->setObjectName(QString::fromUtf8("menuCategorie"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuDatabase->menuAction());
        menuDatei->addAction(actionClose);
        menuDatabase->addAction(menuCategorie->menuAction());
        menuCategorie->addAction(actionAdd_Categorie);
        menuCategorie->addAction(actionDelete_Categorie);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionAdd_Categorie->setText(QApplication::translate("MainWindow", "Add Categorie", 0, QApplication::UnicodeUTF8));
        actionDelete_Categorie->setText(QApplication::translate("MainWindow", "Delete Categorie", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_summe->setText(QApplication::translate("MainWindow", "Summe:", 0, QApplication::UnicodeUTF8));
        label_kategorie->setText(QApplication::translate("MainWindow", "Kategorie:", 0, QApplication::UnicodeUTF8));
        label_art->setText(QApplication::translate("MainWindow", "Art:", 0, QApplication::UnicodeUTF8));
        comboBox_art->clear();
        comboBox_art->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Eingaben", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ausgaben", 0, QApplication::UnicodeUTF8)
        );
        label_beschreibung->setText(QApplication::translate("MainWindow", "Beschreibung:", 0, QApplication::UnicodeUTF8));
        pushButton_submit->setText(QApplication::translate("MainWindow", "Submit", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("MainWindow", "close", 0, QApplication::UnicodeUTF8));
        label_Date->setText(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", 0, QApplication::UnicodeUTF8));
        menuDatabase->setTitle(QApplication::translate("MainWindow", "Database", 0, QApplication::UnicodeUTF8));
        menuCategorie->setTitle(QApplication::translate("MainWindow", "Categorie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
