#ifndef FOOTTABLEMODEL_H
#define FOOTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QStandardItemModel>
#include "lib_global.h"
#include "hierarchicalheaderview.h"

class LIBSHARED_EXPORT FootTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FootTableModel(int row,int column,QObject *parent = 0);
    explicit FootTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex& /*parent*/) const
    {
        return rows;
    }

    int columnCount(const QModelIndex& /*parent*/) const
    {
        return columns;
    }
    QVariant data(const QModelIndex& index, int role=Qt::DisplayRole) const;
    void setItem(int column,QStandardItem *aitem);
    QStandardItem *item(int column);

signals:
    
public slots:
private:
    int rows;
    int columns;
    QStandardItemModel _footModel;
};

#endif // FOOTTABLEMODEL_H
