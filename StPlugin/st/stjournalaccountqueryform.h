#ifndef STJOURNALACCOUNTQUERYFORM_H
#define STJOURNALACCOUNTQUERYFORM_H
#include <QWidget>
#include "widget/singlequeryform.h"
class StJournalAccountQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit StJournalAccountQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // STJOURNALACCOUNTQUERYFORM_H
