#include "posting.h"

Posting::Posting(){}
Posting::Posting(QString name, double sum, QString categorie, bool earning, QString discription) :
    m_name(name),
    m_sum(sum),
    m_categorie(categorie),
    m_earning(earning),
    m_discription(discription) {}

QString& Posting::name(){ return m_name; }
double& Posting::sum(){ return m_sum; }
QString& Posting::categorie(){ return m_categorie; }
bool& Posting::earning(){ return m_earning; }
QString& Posting::discription(){ return m_discription; }
