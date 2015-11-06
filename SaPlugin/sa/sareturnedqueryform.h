#ifndef SARETURNEDQUERYFORM_H
#define SARETURNEDQUERYFORM_H
#include "widget/queryform.h"

class SaReturnedQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaReturnedQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // SARETURNEDQUERYFORM_H
