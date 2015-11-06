/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef REPSCROLLAREA_H
#define REPSCROLLAREA_H

#include <QScrollArea>
#include "PageSettingDlg.h"
#include "ReportBand.h"

namespace Ui {
class RepScrollArea;
}

int compareBandType(ReportBand *p1, ReportBand *p2);

class RepScrollArea : public QScrollArea
{
    Q_OBJECT
    
public:
    explicit RepScrollArea(QWidget *parent = 0);
    QWidget *repWidget;
    ~RepScrollArea();
    void setPaperSize();
    void paintGrid();
    bool isShowGrid;
    ReportBand *m_addBand(QString bandName, BandType type, int m_height=0);
    PageSetting pageSetting;
    void correctBandGeom(QWidget *rep = 0);
    bool allowField();
    void clearReport();
    QList<QWidget *> getReportItems();
    QMenu *bandMenu;
    QTreeWidgetItem *rootItem;
    QIcon icon;
    QAction *actField;

protected:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    Ui::RepScrollArea *ui;
    void paintHorRuler();
    void paintVerRuler();
    QWidget *m_mainWindow;

public slots:
    void showGrid(bool value);

private slots:
    void bandResing(QRect rect);

signals:
    void bandResing(int);

};

#endif // REPSCROLLAREA_H
