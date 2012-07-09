#include "deletecategorydialog.h"
#include "ui_deletecategorydialog.h"

deleteCategoryDialog::deleteCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteCategoryDialog) {
    ui->setupUi(this);

    connect(ui->pushButton_OK, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButton_Delete, SIGNAL(clicked()), this, SLOT(close()));
}

deleteCategoryDialog::~deleteCategoryDialog() {
    delete ui;
}
