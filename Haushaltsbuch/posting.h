#ifndef POSTING_H
#define POSTING_H
#include <QString>
#include <QVariant>
#include <QDateTime>

class Posting{
private:
    int m_id;
    QString m_name;
    double m_sum;
    int m_categorie;
    bool m_earning;
    QString m_discription;
    QDateTime m_date;
public:
    Posting();
    Posting(QString m_name, double m_sum, int m_categorie, bool m_earning, QString m_discription, QDateTime date);

    QString& name();
    double& sum();
    int & categorie();
    bool& earning();
    QString& discription();
    QDateTime& date();
};

#endif // POSTING_H
