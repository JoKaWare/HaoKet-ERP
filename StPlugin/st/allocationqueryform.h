#ifndef ALLOCATIONQUERYFORM_H
#define ALLOCATIONQUERYFORM_H
#include <QWidget>
#include "widget/queryform.h"
class AllocationQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit AllocationQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // ALLOCATIONQUERYFORM_H
