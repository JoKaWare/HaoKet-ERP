#ifndef FASUBSIDIARYQUERYFORM_H
#define FASUBSIDIARYQUERYFORM_H
#include "widget/singlequeryform.h"
#include <QWidget>
class FaSubsidiaryQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit FaSubsidiaryQueryForm(QWidget *parent = 0);
    
signals:
    
private slots:
    void sTableClicked(QString no);
    
};

#endif // FASUBSIDIARYQUERYFORM_H
