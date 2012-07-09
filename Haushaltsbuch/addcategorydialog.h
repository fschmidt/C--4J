#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include <QDialog>
#include "databaseconection.h"

namespace Ui {
class AddCategoryDialog;
}

class AddCategoryDialog : public QDialog
{
    Q_OBJECT   

public:
    explicit AddCategoryDialog(QWidget *parent = 0, DatabaseConection *db = 0);
    ~AddCategoryDialog();

public slots:
    void accept();
    
private:
    Ui::AddCategoryDialog *ui;
    DatabaseConection *m_db;
};

#endif // ADDCATEGORYDIALOG_H
