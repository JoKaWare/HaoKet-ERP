#ifndef INIMEIQUERYFORM_H
#define INIMEIQUERYFORM_H
#include "widget/singlequeryform.h"
class InImeiQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit InImeiQueryForm(QWidget *parent = 0);
    
signals:

private slots:
    void sTableClicked(QString no);
    
};

#endif // INIMEIQUERYFORM_H
