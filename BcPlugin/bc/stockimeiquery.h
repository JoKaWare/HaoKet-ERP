#ifndef STOCKIMEIQUERY_H
#define STOCKIMEIQUERY_H
#include "widget/singlequeryform.h"
class StockImeiQuery : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit StockImeiQuery(QWidget *parent = 0);
    
signals:
    

private slots:
    void sTableClicked(QString no);
    
};

#endif // STOCKIMEIQUERY_H
