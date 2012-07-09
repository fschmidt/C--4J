#include "category.h"

Category::Category(QString name):
    m_name(name){}

Category::Category(int id, QString name):
    m_id(id),
    m_name(name){}

int Category::id() { return m_id; }
QString& Category::name() { return m_name; }
