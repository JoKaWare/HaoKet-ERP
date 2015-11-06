#ifndef RDOUTIMEIQUERY_H
#define RDOUTIMEIQUERY_H
#include "widget/singlequeryform.h"
class RdOutImeiQuery : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit RdOutImeiQuery(QWidget *parent = 0);
    RdOutImeiQuery(QString vouch_type, QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // RDOUTIMEIQUERY_H
