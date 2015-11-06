/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef TCONTAINERFIELD_H
#define TCONTAINERFIELD_H

#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMenu>
#include "ReportBand.h"
#include "CommonFiles/tcontainer.h"
#include "EditFldDlg.h"


enum FieldType {
    Text,
    TextImage,
    Image
};

enum Command {
    None,
    Name,
    Bold,
    Italic,
    Underline,
    Font,   //5
    FontSize,
    FontColor,
    FontName,  //8
    Frame,        //9
    FrameLeft,    //
    FrameRight,   //9
    FrameTop,     //10
    FrameBottom,  //11
    FrameNo,
    FrameAll,
    FrameStyle,
    FrameWidth,
    AligmentH,
    AligmentV,
    Left,
    Top,
    Width,
    Height,
    BackgroundColor,
    BorderColor,
    Printing
};

enum BorderStyle {
    Dashed,
    Dot_dash,
    Dot_dot_dash,
    Dotted,
    Double,
    Groove,
    Inset,
    Outset,
    Ridge,
    Solid,
    BorderNone
};

Q_DECLARE_METATYPE(BorderStyle);

class TContainerField : public TContainer {
    Q_OBJECT
public:
    TContainerField(QWidget *parent, QPoint p, QWidget *cWidget = 0);
    ~TContainerField();
    QTreeWidgetItem *itemInTree;
    TContainerField *clone();
    FieldType type;
    QString printing;
    QString highlighting;
    void setText(QString text);
    QString getText();
    void setImage(QPixmap p);
    QPixmap getImage();
    void setMenu(QMenu *menu_);
    void allowEditing(bool value);
    QString getColorValue(Command param);
    void setBorder(Command command, QVariant values, bool yesFrame = false);
    void setSheetValue(Command param, QString value);
    bool borderIsCheck(Command command);

protected:
    void mouseDoubleClickEvent ( QMouseEvent * event );

private:
    QLabel *label;

signals:
    void delCont(QTreeWidgetItem *);
    void contChanged(bool);

public slots:
    void edit();

private slots:

};

#endif // TCONTAINERFIELD_H
