#include "addcategorydialog.h"
#include "ui_addcategorydialog.h"
#include "QDialogButtonBox"
#include "databaseconection.h"
#include "category.h"

AddCategoryDialog::AddCategoryDialog(QWidget *parent, DatabaseConection *db) :
    QDialog(parent),
    ui(new Ui::AddCategoryDialog),
    m_db(db){
    ui->setupUi(this);
    connect(ui->pushButton_OK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->pushButton_Cancel, SIGNAL(clicked()), this, SLOT(close()));
}

AddCategoryDialog::~AddCategoryDialog(){
    delete ui;
}

void AddCategoryDialog::accept(){
    QString name = ui->lineEdit_newCategorie->text();
    if(name.isEmpty()){
        Category *category = new Category(name);
        m_db->addCategory(*category);
    }
    this->close();
}
