#ifndef PUORDERQUERYFORM_H
#define PUORDERQUERYFORM_H
#include "widget/queryform.h"

class PuOrderQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit PuOrderQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
private:

    
};

#endif // PUORDERQUERYFORM_H
