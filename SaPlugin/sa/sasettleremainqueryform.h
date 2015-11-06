#ifndef SASETTLEREMAINQUERYFORM_H
#define SASETTLEREMAINQUERYFORM_H
#include "widget/singlequeryform.h"
class SaSettleRemainQueryForm: public SingleQueryForm
{
    Q_OBJECT
public:
    explicit SaSettleRemainQueryForm(QWidget *parent = 0);
    SaSettleRemainQueryForm(QString bus_type,QWidget *parent = 0);

};

#endif // SASETTLEREMAINQUERYFORM_H
