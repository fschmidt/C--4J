#ifndef DELETECATEGORYDIALOG_H
#define DELETECATEGORYDIALOG_H

#include <QDialog>
#include "databaseconection.h"

namespace Ui {
class deleteCategoryDialog;
}

class deleteCategoryDialog : public QDialog {
    Q_OBJECT
    
public:
    explicit deleteCategoryDialog(QWidget *parent = 0, DatabaseConection *db = 0);
    ~deleteCategoryDialog();
    
public slots:
    void deleteCategory();
private:
    Ui::deleteCategoryDialog *ui;
    DatabaseConection *m_db;
    QSqlTableModel *m_model;

    void insertCategory();
};

#endif // DELETECATEGORYDIALOG_H
