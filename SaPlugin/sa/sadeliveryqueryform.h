#ifndef SADELIVERYQUERYFORM_H
#define SADELIVERYQUERYFORM_H
#include "widget/queryform.h"
class SaDeliveryQueryForm: public QueryForm
{
    Q_OBJECT
public:
    explicit SaDeliveryQueryForm(QWidget *parent = 0);

signals:

private slots:
    void sTableClicked(QString no);
};

#endif // SADELIVERYQUERYFORM_H
