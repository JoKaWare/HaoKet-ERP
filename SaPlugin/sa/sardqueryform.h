#ifndef SARDQUERYFORM_H
#define SARDQUERYFORM_H
#include <QWidget>
#include "widget/queryform.h"

class SaRdQueryForm : public QueryForm
{
    Q_OBJECT
public:
    explicit SaRdQueryForm(QWidget *parent = 0);
    
signals:
private slots:
    void sTableClicked(QString no);
    
};

#endif // SARDQUERYFORM_H
