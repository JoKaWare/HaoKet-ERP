#ifndef QKSEARCHEDITBOX_P_H
#define QKSEARCHEDITBOX_P_H
#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QToolButton>
#include <QListView>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QtGui/private/qwidget_p.h>
#include "qksearcheditbox.h"

class QkSearchEditBoxPrivate : public QWidgetPrivate{
    Q_DECLARE_PUBLIC(QkSearchEditBox);
public:
    QkSearchEditBoxPrivate();
    QkSearchEditBoxPrivate(QkSearchEditBox *textsearch);
    ~QkSearchEditBoxPrivate(){
    }
    void init();
    void updateGeometry();

    QLineEdit *m_lineedit;
    QLineEdit *m_lineedit_sub;
    QToolButton *m_button;
    QStringListModel *m_stringListmodel;
    QSortFilterProxyModel *proxyModel;
    QListView *m_listview;
    QStringList m_stringList;
    bool m_bEditFocus;

};


#endif // QKSEARCHEDITBOX_P_H
