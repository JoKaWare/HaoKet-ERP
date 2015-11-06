#ifndef RDIMEIQUERY_H
#define RDIMEIQUERY_H
#include <QWidget>
#include "widget/singlequeryform.h"
class RdImeiQuery : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit RdImeiQuery(QWidget *parent = 0);
    RdImeiQuery(QString vouch_type, QWidget *parent = 0);
signals:
    

private slots:
    void sTableClicked(QString no);
    
};

#endif // RDIMEIQUERY_H
