#ifndef QKEDITDELEGATE_H
#define QKEDITDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QSize>
#include <QCompleter>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include "qksearcheditbox.h"
#include "qwwbuttonlineedit/qwwbuttonlineedit.h"
#include "lib_global.h"

class LIBSHARED_EXPORT QkEditDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit QkEditDelegate(QObject *parent = 0);
    explicit QkEditDelegate(QAbstractItemModel *model,QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
    

private slots:
    void sClicked();
signals:
  void btnClicked();
private:
    QAbstractItemModel *mModel;

    
};

#endif // QKEDITDELEGATE_H
