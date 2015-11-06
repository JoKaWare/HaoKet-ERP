/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef EDITFLDDLG_H
#define EDITFLDDLG_H

#include <QDialog>
#include <QtGui>
#include "FldPropertyDlg.h"
#include "tcontainerfield.h"
//#include "mainwindow.h"

namespace Ui {
    class EditFldDlg;
}

class TContainerField;
//class MainWindow;

class EditFldDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditFldDlg(QWidget *parent = 0);
    ~EditFldDlg();
    int showText(TContainerField *cont);
    int showImage(TContainerField *cont);

private:
    Ui::EditFldDlg *ui;
    bool boolImage;  //Proccess TextFiled as a Image
    TContainerField *m_cont;
    QString m_cond_printing;
    QString m_cond_higlighting;

private slots:
    void loadImage();
    void openProperty();
    void conditionalToggled(bool value);
    void backGroundToggled(bool value);
    void conditionChanged(const QString &text);
    void chooseColor();
    void encodeHighLightingString();
    void decodeHighLightingString();

};

#endif // EDITFLDDLG_H
