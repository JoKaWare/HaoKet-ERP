#ifndef SAORDEREXECQUERYFORM_H
#define SAORDEREXECQUERYFORM_H
#include "widget/singlequeryform.h"
class SaOrderExecQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit SaOrderExecQueryForm(QWidget *parent = 0);
    
signals:

private slots:
    void sTableClicked(QString no);
    
};

#endif // SAORDEREXECQUERYFORM_H
