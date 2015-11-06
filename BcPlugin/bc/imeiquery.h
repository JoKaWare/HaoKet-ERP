#ifndef IMEIQUERY_H
#define IMEIQUERY_H
#include "widget/singlequeryform.h"
class ImeiQuery : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit ImeiQuery(QWidget *parent = 0);
    
signals:
    

private slots:
    void sTableClicked(QString no);
    
};

#endif // IMEIQUERY_H
