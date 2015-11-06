/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <QWidget>
#include <QDialog>
#include <QtGui>

class AboutDlg : public QDialog {
    Q_OBJECT
public:
    explicit AboutDlg(QWidget *parent = 0);

signals:

private slots:
    void openLink(const QString url);
};

#endif // ABOUTDLG_H
