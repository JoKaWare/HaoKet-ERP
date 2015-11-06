#ifndef USERADD_H
#define USERADD_H

#include <QMainWindow>

namespace Ui {
class UserAdd;
}

class UserAdd : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit UserAdd(QWidget *parent = 0);
    ~UserAdd();
private:
    void clear();
    void initViewHead();
private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::UserAdd *ui;
};

#endif // USERADD_H
