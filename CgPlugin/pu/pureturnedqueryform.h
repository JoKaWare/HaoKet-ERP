#ifndef PURETURNEDQUERYFORM_H
#define PURETURNEDQUERYFORM_H
#include "widget/queryform.h"
#include <QWidget>
class PuReturnedQueryForm: public QueryForm
{
    Q_OBJECT
public:
    PuReturnedQueryForm(QWidget *parent);
private slots:
    void sTableClicked(QString no);
};

#endif // PURETURNEDQUERYFORM_H
