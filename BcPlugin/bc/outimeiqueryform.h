#ifndef OUTIMEIQUERYFORM_H
#define OUTIMEIQUERYFORM_H
#include "widget/singlequeryform.h"
class OutImeiQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit OutImeiQueryForm(QWidget *parent = 0);
    
signals:

private slots:
    void sTableClicked(QString no);
    
};

#endif // OUTIMEIQUERYFORM_H
