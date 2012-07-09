#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseconection.h"
#include "posting.h"
#include "QVariant"
#include "addcategorydialog.h"
#include "deletecategorydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->pushButton_close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->pushButton_submit, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->actionAdd_Categorie, SIGNAL(triggered()), this, SLOT(openCreateCategory()));
    connect(ui->actionDelete_Categorie, SIGNAL(triggered()), this, SLOT(openDeleteCategory()));
//    connect(this, SIGNAL(stausMassage(QString)), ui->statusBar, SLOT(showMessage(QString)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addDatabase(DatabaseConection* db) {
    m_database = db;
}

bool MainWindow::databaseOpen(){
    return m_database->open();
}

void MainWindow::databaseClose(){
    m_database->close();
}

void MainWindow::genrateCategorie(){
    if(m_database){
        QList<Category> categorieListe = m_database->giveCategorie();

        for(int i = 0; i < categorieListe.size(); i++){
            int index = categorieListe[i].id();

            QString name = categorieListe[i].name();
            ui->comboBox_categorie->addItem(name, QVariant(index));
        }
    }
}

void MainWindow::submit(){
    Posting *post = new Posting();
    post->name() = ui->lineEdit_name->text();
    post->sum() = ui->doubleSpinBox_summe->value();
    post->categorie() = ui->comboBox_categorie->itemData(ui->comboBox_categorie->currentIndex()).toInt();
    post->earning() = ui->comboBox_art->currentIndex();
    post->discription() = ui->textEdit_discription->toPlainText();
    post->date() = ui->dateTimeEdit->dateTime();

    m_database->sendBuchungsQuerry(post);
    ui->lineEdit_name->clear();
    ui->textEdit_discription->clear();
    ui->doubleSpinBox_summe->clear();
    ui->dateTimeEdit->clear();
}

void MainWindow::openCreateCategory() {
    AddCategoryDialog dialog(this, m_database);
    dialog.exec();
    ui->comboBox_categorie->clear();
    this->genrateCategorie();
}

void MainWindow::openDeleteCategory(){
    deleteCategoryDialog dialog(this);
    dialog.exec();
}
