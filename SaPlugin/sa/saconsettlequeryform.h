#ifndef SACONSETTLEQUERYFORM_H
#define SACONSETTLEQUERYFORM_H
#include "widget/queryform.h"

class SaConSettleQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaConSettleQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // SACONSETTLEQUERYFORM_H
