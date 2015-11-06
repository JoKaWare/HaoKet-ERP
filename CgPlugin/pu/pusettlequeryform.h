#ifndef PUSETTLEQUERYFORM_H
#define PUSETTLEQUERYFORM_H
#include "widget/queryform.h"

class PuSettleQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit PuSettleQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // PUSETTLEQUERYFORM_H
