#ifndef SHOWINPUTDIALOG_H
#define SHOWINPUTDIALOG_H

#include <QDialog>
#include "databaseconection.h"

namespace Ui {
class ShowInputDialog;
}

class ShowInputDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ShowInputDialog(QWidget *parent = 0, DatabaseConection *db = 0);
    ~ShowInputDialog();
    
public slots:
    void showInput();
private:
    Ui::ShowInputDialog *ui;
    DatabaseConection *m_db;
    QSqlTableModel *m_model;
};

#endif // SHOWINPUTDIALOG_H
