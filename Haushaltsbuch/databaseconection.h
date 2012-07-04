#ifndef DATABASECONECTION_H
#define DATABASECONECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QtSql>
#include <QtSql/QSqlDriverPlugin>
#include "QString"
#include "posting.h"

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
                       "PRIMARY KEY (`id`),"
                       "KEY `category` (`category`)"
                       ") ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;");
        querry.exec();
        querry.prepare("ALTER TABLE `entrys`"
                       "ADD CONSTRAINT `entrys_ibfk_1` FOREIGN KEY (`category`) REFERENCES `category` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION;");
        querry.exec();
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
public slots:
    void sendBuchungsQuerry(Posting *post){
        m_database.open();
        m_database.transaction();

        QSqlQuery query;
        query.prepare("INSERT INTO `cpp`.`entrys` (`name`, `sum`, `category`, `art`, `description`) "
                      "VALUES (:name, :sum, :category, :art, :description)");
        query.bindValue(":name", post->name());
        query.bindValue(":sum", post->sum());
        query.bindValue(":category", post->categorie());
        query.bindValue(":art", post->earning());
        query.bindValue(":description", post->discription());
        query.exec();


        m_database.commit();
        m_database.close();
        query.lastError().text();
    }
};

#endif // DATABASECONECTION_H
