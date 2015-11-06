#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include "common/common.h"

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit UserWidget(QWidget *parent = 0);
    ~UserWidget();
    
private slots:
    void on_cancelButton_clicked();
    void on_list_clicked(QListWidgetItem *item);

    void on_saveButton_clicked();

    void on_qksearcheditbox_buttonClicked();

    void on_addButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_passButton_clicked();

private:
    Ui::UserWidget *ui;
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
    void init();
    int AddUser();
    int m_id;
    int editStatus;
};

#endif // USERWIDGET_H
