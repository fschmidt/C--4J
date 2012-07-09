#ifndef CATEGORY_H
#define CATEGORY_H
#include "QString"

class Category{
private:
    int m_id;
    QString m_name;
public:
    Category(QString name);
    Category(int id, QString name);

    int id();
    QString& name();
};

#endif // CATEGORY_H
