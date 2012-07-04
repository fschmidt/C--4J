#include <QtGui/QApplication>
#include <QCoreApplication>
#include <QStringList>
#include <QtDebug>
#include "mainwindow.h"
#include "iostream"
#include "databaseconection.h"

using namespace std;

int main(int argc, char *argv[]){

    DatabaseConection db = DatabaseConection();

    QApplication a(argc, argv);
    MainWindow w;

    w.addDatabase(&db);
    w.show();

    return a.exec();
}
