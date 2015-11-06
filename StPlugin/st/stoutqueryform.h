#ifndef STOUTQUERYFORM_H
#define STOUTQUERYFORM_H
#include <QWidget>
#include "widget/queryform.h"
class StOutQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit StOutQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // STOUTQUERYFORM_H
