#ifndef POSTING_H
#define POSTING_H
#include <QString>

class Posting{
private:
    int m_id;
    QString m_name;
    double m_sum;
    QString m_categorie;
    bool m_earning;
    QString m_discription;
public:
    Posting();
    Posting(QString m_name, double m_sum, QString m_categorie, bool m_earning, QString m_discription);

    QString& name();
    double& sum();
    QString& categorie();
    bool& earning();
    QString& discription();
};

#endif // POSTING_H
