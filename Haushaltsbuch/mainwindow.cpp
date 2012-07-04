#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseconection.h"
#include "posting.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->pushButton_close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->pushButton_submit, SIGNAL(clicked()), this, SLOT(submit()));
    connect(this, SIGNAL(stausMassage(QString)), ui->statusBar, SLOT(showMessage(QString)));
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

void MainWindow::submit(){
    Posting *post = new Posting();
    post->name() = ui->lineEdit_name->text();
    post->sum() = ui->lineEdit_summe->text().toDouble();
    post->categorie() = 1;
    post->earning() = true;
    post->discription() = ui->textEdit_discription->toPlainText();


    m_database->sendBuchungsQuerry(post);
    ui->lineEdit_name->clear();
    ui->textEdit_discription->clear();
    ui->lineEdit_summe->clear();
}
