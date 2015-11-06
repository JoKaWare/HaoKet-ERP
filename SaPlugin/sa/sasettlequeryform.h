#ifndef SASETTLEQUERYFORM_H
#define SASETTLEQUERYFORM_H
#include "widget/queryform.h"

class SaSettleQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaSettleQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // SASETTLEQUERYFORM_H
