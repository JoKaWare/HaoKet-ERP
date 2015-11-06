#ifndef EDITORDELEGATE_H
#define EDITORDELEGATE_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtGui>
#include <QDomDocument>
#include "PageSettingDlg.h"
#include "ReportBand.h"
#include "tcontainerfield.h"
#include "aboutDlg.h"
#include "languagedlg.h"
#include "RepScrollArea.h"
class EditorDelegate: public QItemDelegate
{
    Q_OBJECT

public:
    EditorDelegate(QObject *parent);
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const {
        return QSize(50,20);
    }
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

private slots:
    void commitAndCloseEditor();
    void editorClose_(QWidget *editor, QAbstractItemDelegate::EndEditHint hint);

signals:
    void editorClose(QItemDelegate *item);
};

#endif // EDITORDELEGATE_H
