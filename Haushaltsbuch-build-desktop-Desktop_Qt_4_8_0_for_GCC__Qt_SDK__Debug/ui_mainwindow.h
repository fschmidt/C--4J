/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jul 10 12:54:48 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionAdd_Categorie;
    QAction *actionDelete_Categorie;
    QAction *actionShow_Input;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_name;
    QLabel *label_art;
    QTextEdit *textEdit_discription;
    QLabel *label_name;
    QLabel *label_summe;
    QDoubleSpinBox *doubleSpinBox_summe;
    QLabel *label_kategorie;
    QComboBox *comboBox_categorie;
    QLabel *label_Date;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *comboBox_art;
    QLabel *label_beschreibung;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_close;
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
        MainWindow->resize(433, 408);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAdd_Categorie = new QAction(MainWindow);
        actionAdd_Categorie->setObjectName(QString::fromUtf8("actionAdd_Categorie"));
        actionDelete_Categorie = new QAction(MainWindow);
        actionDelete_Categorie->setObjectName(QString::fromUtf8("actionDelete_Categorie"));
        actionShow_Input = new QAction(MainWindow);
        actionShow_Input->setObjectName(QString::fromUtf8("actionShow_Input"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        formLayout = new QFormLayout(widget_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit_name = new QLineEdit(widget_2);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_name);

        label_art = new QLabel(widget_2);
        label_art->setObjectName(QString::fromUtf8("label_art"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_art);

        textEdit_discription = new QTextEdit(widget_2);
        textEdit_discription->setObjectName(QString::fromUtf8("textEdit_discription"));

        formLayout->setWidget(11, QFormLayout::FieldRole, textEdit_discription);

        label_name = new QLabel(widget_2);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_name);

        label_summe = new QLabel(widget_2);
        label_summe->setObjectName(QString::fromUtf8("label_summe"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_summe);

        doubleSpinBox_summe = new QDoubleSpinBox(widget_2);
        doubleSpinBox_summe->setObjectName(QString::fromUtf8("doubleSpinBox_summe"));

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBox_summe);

        label_kategorie = new QLabel(widget_2);
        label_kategorie->setObjectName(QString::fromUtf8("label_kategorie"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_kategorie);

        comboBox_categorie = new QComboBox(widget_2);
        comboBox_categorie->setObjectName(QString::fromUtf8("comboBox_categorie"));

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBox_categorie);

        label_Date = new QLabel(widget_2);
        label_Date->setObjectName(QString::fromUtf8("label_Date"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_Date);

        dateTimeEdit = new QDateTimeEdit(widget_2);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2012, 7, 10), QTime(8, 0, 0)));
        dateTimeEdit->setDate(QDate(2012, 7, 10));
        dateTimeEdit->setCalendarPopup(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, dateTimeEdit);

        comboBox_art = new QComboBox(widget_2);
        comboBox_art->setObjectName(QString::fromUtf8("comboBox_art"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBox_art);

        label_beschreibung = new QLabel(widget_2);
        label_beschreibung->setObjectName(QString::fromUtf8("label_beschreibung"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_beschreibung);


        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

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


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 433, 25));
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
        QWidget::setTabOrder(lineEdit_name, doubleSpinBox_summe);
        QWidget::setTabOrder(doubleSpinBox_summe, comboBox_categorie);
        QWidget::setTabOrder(comboBox_categorie, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, comboBox_art);
        QWidget::setTabOrder(comboBox_art, textEdit_discription);
        QWidget::setTabOrder(textEdit_discription, pushButton_submit);
        QWidget::setTabOrder(pushButton_submit, pushButton_close);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuDatabase->menuAction());
        menuDatei->addAction(actionClose);
        menuDatabase->addAction(menuCategorie->menuAction());
        menuDatabase->addAction(actionShow_Input);
        menuCategorie->addAction(actionAdd_Categorie);
        menuCategorie->addAction(actionDelete_Categorie);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "book of household", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionAdd_Categorie->setText(QApplication::translate("MainWindow", "Add Categorie", 0, QApplication::UnicodeUTF8));
        actionDelete_Categorie->setText(QApplication::translate("MainWindow", "Delete Category", 0, QApplication::UnicodeUTF8));
        actionShow_Input->setText(QApplication::translate("MainWindow", "Show Input", 0, QApplication::UnicodeUTF8));
        label_art->setText(QApplication::translate("MainWindow", "Art:", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_summe->setText(QApplication::translate("MainWindow", "Summe:", 0, QApplication::UnicodeUTF8));
        label_kategorie->setText(QApplication::translate("MainWindow", "Kategorie:", 0, QApplication::UnicodeUTF8));
        label_Date->setText(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        comboBox_art->clear();
        comboBox_art->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Eingaben", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ausgaben", 0, QApplication::UnicodeUTF8)
        );
        label_beschreibung->setText(QApplication::translate("MainWindow", "Beschreibung:", 0, QApplication::UnicodeUTF8));
        pushButton_submit->setText(QApplication::translate("MainWindow", "Submit", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("MainWindow", "close", 0, QApplication::UnicodeUTF8));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", 0, QApplication::UnicodeUTF8));
        menuDatabase->setTitle(QApplication::translate("MainWindow", "Database", 0, QApplication::UnicodeUTF8));
        menuCategorie->setTitle(QApplication::translate("MainWindow", "Category", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
