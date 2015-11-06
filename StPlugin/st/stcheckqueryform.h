#ifndef STCHECKQUERYFORM_H
#define STCHECKQUERYFORM_H
#include <QWidget>
#include "widget/queryform.h"

class StCheckQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit StCheckQueryForm(QWidget *parent = 0);
    
signals:
    

private slots:
    void sTableClicked(QString no);
    
};

#endif // STCHECKQUERYFORM_H
