#ifndef TASTEBEAN_H
#define TASTEBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT TasteBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString tasteName READ tasteName WRITE setTasteName)
    Q_PROPERTY(QString tasteCaption READ tasteCaption WRITE setTasteCaption)
public:
    int id(){return m_id;}
    void setId(int id){ m_id = id;}
    QString tasteName(){return m_taste_name;}
    void setTasteName(QString name){ m_taste_name = name;}
    QString tasteCaption(){return m_taste_caption;}
    void setTasteCaption(QString caption){ m_taste_caption = caption;}

private:
    int m_id;
    QString m_taste_name;
    QString m_taste_caption;
};
#endif // TASTEBEAN_H
