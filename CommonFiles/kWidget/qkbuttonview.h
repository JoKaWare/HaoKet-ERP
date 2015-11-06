#ifndef QKBUTTONVIEW_H
#define QKBUTTONVIEW_H
#include <QScrollArea>
#include <QToolButton>
#include <QPainter>
#include "kWidget_global.h"
#include "qkgridview.h"
class QkButtonViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit  QkButtonViewWidget(QWidget *parent = 0);
    explicit  QkButtonViewWidget(QHash<int, QkButton > buttonList,QWidget *parent = 0);
protected:
    void drawGrid(QPaintDevice * device);
    virtual void paintEvent(QPaintEvent *);
private:
    QPixmap mGridPix;
    static const int mX = 3;
    static const int mY = 3;

    static const int mSpacing = 3;
    static const int mIconSize = 48;
    static const int mWidth = 90;
    static const int mHeight = 90;
signals:
    void buttonClicked(int id);
};

class KWIDGETSHARED_EXPORT QkButtonView :public QScrollArea
{
    Q_OBJECT
public:
    explicit QkButtonView(QWidget *parent = 0);
    explicit QkButtonView(QHash<int, QkButton > buttonList,QWidget *parent = 0);
    ~QkButtonView();
private:
    QkButtonViewWidget *mButtonViewWidget;
signals:
    void buttonClicked(int id);
};

#endif // QKBUTTONVIEW_H
