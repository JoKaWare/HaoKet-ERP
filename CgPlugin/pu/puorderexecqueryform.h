#ifndef PUORDEREXECQUERYFORM_H
#define PUORDEREXECQUERYFORM_H
#include "widget/singlequeryform.h"
#include <QWidget>
class PuOrderExecQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit PuOrderExecQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // PUORDEREXECQUERYFORM_H
