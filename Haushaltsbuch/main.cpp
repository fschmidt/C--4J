#include <QtGui/QApplication>
#include <QCoreApplication>
#include <QStringList>
#include <QtDebug>
#include "mainwindow.h"
#include "iostream"
#include "databaseconection.h"
#include <config_reader.h>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]){

    map<string, string> config;
    ifstream f( "./config.ini");
    f >> config;
    f.close();

    QString host = QString::fromStdString(config["host"]);
    QString dbname = QString::fromStdString(config["db"]);
    QString name = QString::fromStdString(config["user"]);
    QString pw = QString::fromStdString(config["passwort"]);

    DatabaseConection db = DatabaseConection(host, dbname, name, pw);

    QApplication a(argc, argv);
    MainWindow w;

    w.addDatabase(&db);
    w.genrateCategorie();
    w.show();

    return a.exec();
}
