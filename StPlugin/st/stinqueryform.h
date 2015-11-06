#ifndef STINQUERYFORM_H
#define STINQUERYFORM_H

#include <QWidget>
#include "widget/queryform.h"

class StInQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit StInQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // STINQUERYFORM_H
