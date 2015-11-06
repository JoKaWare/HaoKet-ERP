/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef REPORTBAND_H
#define REPORTBAND_H

#include <QWidget>
#include <QtGui>
#include <QObject>
#include <QMouseEvent>
#include "CommonFiles/qlabelex.h"
#include "tcontainerfield.h"

namespace Ui {
    class ReportBand;
}

enum BandType {
    ReportTitle,
    PageHeader,
    MasterHeader,
    MasterData,
    MasterFooter,
    ReportSummary,
    PageFooter
};

class ReportBand : public QWidget
{
    Q_OBJECT
    
public:
    BandType bandType;
    int titleHeight;
    QTreeWidgetItem *itemInTree;
    explicit ReportBand(QWidget *parent = 0, BandType type = ReportTitle, QTreeWidgetItem *item = 0);
    QWidget *contWidget;
    void setMenu(QMenu *menu_);
    ~ReportBand();
    
private:
    int mode;
    bool m_infocus;
    void setCursorShape(const QPoint &e_pos);
    Ui::ReportBand *ui;

signals:
    void inFocus(bool mode);
    void endResizing(QRect rect);
    void delBand(QTreeWidgetItem *);

protected:
    QPoint position;
    bool eventFilter( QObject *obj, QEvent *evt );
    void resizeEvent (QResizeEvent *event);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
};

#endif // REPORTBAND_H
