#ifndef SACONDELIVERYQUERYFORM_H
#define SACONDELIVERYQUERYFORM_H
#include "widget/queryform.h"
class SaConDeliveryQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaConDeliveryQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // SACONDELIVERYQUERYFORM_H
