#ifndef SACONRETURNEDQUERYFORM_H
#define SACONRETURNEDQUERYFORM_H
#include "widget/queryform.h"
class SaConReturnedQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaConReturnedQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // SACONRETURNEDQUERYFORM_H
