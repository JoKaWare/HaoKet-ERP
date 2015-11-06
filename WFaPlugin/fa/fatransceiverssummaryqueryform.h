#ifndef FATRANSCEIVERSSUMMARYQUERYFORM_H
#define FATRANSCEIVERSSUMMARYQUERYFORM_H
#include "widget/singlequeryform.h"
#include <QWidget>
class FaTransceiversSummaryQueryForm: public SingleQueryForm
{
public:
    FaTransceiversSummaryQueryForm(QWidget *parent = 0);

signals:

private slots:
    void sTableClicked(QString no);
};

#endif // FATRANSCEIVERSSUMMARYQUERYFORM_H
