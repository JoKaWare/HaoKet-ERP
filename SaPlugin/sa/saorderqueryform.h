#ifndef SAORDERQUERYFORM_H
#define SAORDERQUERYFORM_H

#include <QWidget>
#include "widget/queryform.h"

class SaOrderQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaOrderQueryForm(QWidget *parent = 0);
    
signals:

private slots:
    void sTableClicked(QString no);
    
};

#endif // SAORDERQUERYFORM_H
