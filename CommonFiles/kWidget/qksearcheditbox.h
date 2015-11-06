#ifndef QKSEARCHEDITBOX_H
#define QKSEARCHEDITBOX_H

#include <QWidget>
#include <QListView>
#include "kWidget_global.h"
class QkSearchEditBoxPrivate;
class KWIDGETSHARED_EXPORT QkSearchEditBox : public QWidget
{
    Q_OBJECT
public:
    QkSearchEditBox(QWidget *parent=0);
    ~QkSearchEditBox(){};
    void clear();
    void setText(const QString &text);
    void setListView(QListView *itemView);
    void setListModel(bool b);
    void setReadOnly(bool);
    QString text();
    QString subText();
    void setItems(const QStringList &sList);
    QStringList items();
signals:
    void buttonClicked();
    void validatorChanged(const QString&);
    void editChanged(const QString&);
protected:
    QkSearchEditBox (QkSearchEditBoxPrivate &priv, QWidget *parent);
    void resizeEvent (QResizeEvent *e);
    void paintEvent (QPaintEvent *e);
    bool eventFilter(QObject *target, QEvent *event);
public slots:
    void keytextChanged(const QString s);
    void clickedSlot(QModelIndex modelIndex);
    void returnPressed();
    void btnClick();
    void showList();
    void showPopup();
    void hidePopup();
    void setRegExp(const QString &);
    void setRegExp(const QRegExp &);
private:
    bool isHidePopup;
    bool m_listModel;
    Q_DECLARE_PRIVATE(QkSearchEditBox);
    Q_DISABLE_COPY(QkSearchEditBox);
    
};

#endif // QKSEARCHEDITBOX_H
