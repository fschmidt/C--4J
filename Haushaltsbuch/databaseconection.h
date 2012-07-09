#ifndef DATABASECONECTION_H
#define DATABASECONECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDriverPlugin>
#include "QString"
#include "posting.h"
#include "category.h"

#include <iostream>
using namespace std;

class DatabaseConection{
private:
    QSqlDatabase m_database;
    QString m_hostName;
    QString m_databaseName;
    QString m_userName;
    QString m_password;
public:
    DatabaseConection(QString hostName = "localhost", QString databaseName = "cpp", QString userName = "cpp", QString password = "cpp"):
        m_hostName(hostName),
        m_databaseName(databaseName),
        m_userName(userName),
        m_password(password){
        m_database = QSqlDatabase::addDatabase("QMYSQL");
        m_database.setHostName(m_hostName);
        m_database.setUserName(m_userName);
        m_database.setPassword(m_password);
        m_database.setDatabaseName(m_databaseName);

        m_database.open();
        m_database.transaction();
        gerateTabel();
        m_database.commit();
        m_database.close();
    }
    ~DatabaseConection(){
        m_database.close();
    }

    QSqlDatabase database(){
        return m_database;
    }

    bool open(){
        return m_database.open();
    }

    void close(){
        return m_database.close();
    }

    QList<Category> giveCategorie(){
        QList<Category> result;
        m_database.open();

        QSqlQuery query;
        query.prepare("SELECT * FROM `cpp`.`category`");
        query.exec();
        int idfield = query.record().indexOf("id");
        int namefield = query.record().indexOf("name");
        while (query.next()) {
             Category category(query.value(idfield).toInt(), query.value(namefield).toString());
             result << category;
         }

        m_database.close();
        return result;
    }

    void addCategory(Category &category){
        m_database.open();

        QSqlQuery query;
        query.prepare("INSERT INTO `cpp`.`category` (`name`) "
                      "VALUES (:name);");
        query.bindValue(":name", category.name());
        query.exec();

        m_database.close();
    }

    void deleteCategory(Category &category){
        m_database.open();

        QSqlQuery query;
        query.prepare("DELETE FROM `cpp`.`category` WHERE `category`.`id` = :id ");
        query.bindValue(":id", category.id());
        query.exec();

        m_database.close();
    }

public slots:
    void sendBuchungsQuerry(Posting *post){
        m_database.open();
        m_database.transaction();

        QSqlQuery query;
        query.prepare("INSERT INTO `cpp`.`entrys` (`name`, `sum`, `category`, `art`, `description`, `date`) "
                      "VALUES (:name, :sum, :category, :art, :description, :date)");
        query.bindValue(":name", post->name());
        query.bindValue(":sum", post->sum());

        query.bindValue(":category", post->categorie());

        query.bindValue(":art", post->earning());
        query.bindValue(":description", post->discription());
        query.bindValue(":date", post->date());
        query.exec();


        m_database.commit();
        m_database.close();
        cout << endl << query.lastError().text().toStdString() << endl;
    }

private:
    void gerateTabel(){
        QSqlQuery querry;
        querry.prepare("CREATE TABLE IF NOT EXISTS `category` ("
                       "    `id` int(11) NOT NULL AUTO_INCREMENT,"
                       "    `name` varchar(255) NOT NULL,"
                       "    PRIMARY KEY (`id`)"
                       "  ) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;");
        querry.exec();
        querry.prepare("CREATE TABLE IF NOT EXISTS `entrys` ("
                       "`id` int(11) NOT NULL AUTO_INCREMENT,"
                       "`name` varchar(255) DEFAULT NULL,"
                       "`sum` double DEFAULT NULL,"
                       "`category` int(11) NOT NULL,"
                       "`art` tinyint(1) NOT NULL,"
                       "`description` text,"
                       "`date` date NOT NULL,"
                       "PRIMARY KEY (`id`),"
                       "KEY `category` (`category`)"
                       ") ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;");
        querry.exec();
        querry.prepare("ALTER TABLE `entrys`"
                       "ADD CONSTRAINT `entrys_ibfk_1` FOREIGN KEY (`category`) REFERENCES `category` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION;");
        querry.exec();
    }
};

#endif // DATABASECONECTION_H
