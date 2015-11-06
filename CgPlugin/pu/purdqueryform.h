#ifndef PURDQUERYFORM_H
#define PURDQUERYFORM_H
#include "widget/queryform.h"

class PuRdQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit PuRdQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // PURDQUERYFORM_H
