#include "posting.h"

Posting::Posting(){}
Posting::Posting(QString name, double sum, int categorie, bool earning, QString discription, QDateTime date) :
    m_name(name),
    m_sum(sum),
    m_categorie(categorie),
    m_earning(earning),
    m_discription(discription),
    m_date(date){}

QString& Posting::name(){ return m_name; }
double& Posting::sum(){ return m_sum; }
int& Posting::categorie(){ return m_categorie; }
bool& Posting::earning(){ return m_earning; }
QString& Posting::discription(){ return m_discription; }
QDateTime &Posting::date(){ return m_date; }
