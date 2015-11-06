#ifndef RDQUERYFORM_H
#define RDQUERYFORM_H

#include <QWidget>

namespace Ui {
class RdQueryForm;
}

class RdQueryForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit RdQueryForm(QWidget *parent = 0);
    ~RdQueryForm();
    
private slots:
    void on_toolButton_clicked();

private:
    Ui::RdQueryForm *ui;
};

#endif // RDQUERYFORM_H
