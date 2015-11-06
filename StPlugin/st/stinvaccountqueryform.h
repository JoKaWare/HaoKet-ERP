#ifndef STINVACCOUNTQUERYFORM_H
#define STINVACCOUNTQUERYFORM_H
#include <QWidget>
#include "widget/anyqueryform.h"
class StInvAccountQueryForm : public AnyQueryForm
{
    Q_OBJECT
public:
    explicit StInvAccountQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // STINVACCOUNTQUERYFORM_H
