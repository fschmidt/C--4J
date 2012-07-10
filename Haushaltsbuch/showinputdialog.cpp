#include "showinputdialog.h"
#include "ui_showinputdialog.h"

ShowInputDialog::ShowInputDialog(QWidget *parent, DatabaseConection *db) :
    QDialog(parent),
    ui(new Ui::ShowInputDialog),
    m_db(db) {
    ui->setupUi(this);

    m_model = new QSqlTableModel(parent, m_db->database());

    connect(ui->pushButton_OK, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButton_Show, SIGNAL(clicked()), this, SLOT(showInput()));

}

ShowInputDialog::~ShowInputDialog() {
    delete ui;
}

void ShowInputDialog::showInput() {
    if(m_db){
        m_model->database().open();
        m_model->setTable("entrys");
        m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        m_model->select();

        QSqlQuery query = m_model->query();
        query.prepare("SELECT * FROM `entrys` WHERE `date` >= :from AND `date` <= :to");
        query.bindValue(":from", ui->dateEdit_From->text());
        query.bindValue(":to", ui->dateEdit_To->text());
        query.exec();

        ui->tableView_input->setModel(m_model);
        ui->tableView_input->hideColumn(0); // don't show the ID
        ui->tableView_input->show();
        m_model->database().close();
    }
}
