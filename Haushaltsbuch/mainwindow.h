#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include "databaseconection.h"
#include "posting.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    DatabaseConection *m_database;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addDatabase(DatabaseConection *db);
    bool databaseOpen();
    void databaseClose();

    void genrateCategorie();
public slots:
    void submit();
    void openCreateCategory();
    void openDeleteCategory();
    void openShowInput();
signals:
    void stausMassage(const QString &massage);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
