#include "deletecategorydialog.h"
#include "ui_deletecategorydialog.h"
#include "iostream"

using namespace std;

deleteCategoryDialog::deleteCategoryDialog(QWidget *parent, DatabaseConection *db) :
    QDialog(parent),
    ui(new Ui::deleteCategoryDialog),
    m_db(db){
    ui->setupUi(this);

    m_model = new QSqlTableModel(parent, m_db->database());
    insertCategory();

    connect(ui->pushButton_Cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButton_Delete, SIGNAL(clicked()), this, SLOT(deleteCategory()));
}



deleteCategoryDialog::~deleteCategoryDialog() {
    delete ui;
}

void deleteCategoryDialog::insertCategory() {
    if(m_db){
        m_model->database().open();
        m_model->setTable("category");
        m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        m_model->select();

        ui->tableView_Category->setModel(m_model);
        ui->tableView_Category->hideColumn(0); // don't show the ID
        ui->tableView_Category->show();
        m_model->database().close();
    }
}

void deleteCategoryDialog::deleteCategory() {
    QModelIndexList indexList = ui->tableView_Category->selectionModel()->selection().indexes();
    QString index = indexList.value(0).data().toString();
    m_db->deleteCategory(index.toInt());
    this->close();
}
