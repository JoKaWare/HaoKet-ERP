#ifndef TRANSIMEIQUERY_H
#define TRANSIMEIQUERY_H
#include "widget/singlequeryform.h"
class TransImeiQuery : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit TransImeiQuery(QWidget *parent = 0);
    
signals:
    

private slots:
    void sTableClicked(QString no);
    
};

#endif // TRANSIMEIQUERY_H
