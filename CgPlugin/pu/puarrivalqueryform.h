#ifndef PUARRIVALQUERYFORM_H
#define PUARRIVALQUERYFORM_H
#include "widget/queryform.h"
#include <QWidget>
class PuArrivalQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit PuArrivalQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // PUARRIVALQUERYFORM_H
