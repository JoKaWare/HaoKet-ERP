#ifndef QKGRIDVIEW_H
#define QKGRIDVIEW_H

#include <QtGui>
#include "kWidget_global.h"

class QkButton{
public:
    QString name() { return mName; }
    void setName(QString name) { mName = name ;}
    QString id() { return mId;}
    void setId(QString id) { mId = id ;}
    QString no() { return mNo;}
    void setNo(QString no){ mNo = no;}
    QString caption(){ return mCaption;}
    void setCaption(QString s) { mCaption = s;}
    int getX() { return mX; }
    void setX(int x) { mX = x; }
    int getY() { return mY; }
    void setY(int y) { mY = y; }
    int index() { return mIndex; }
    void setIndex(int index) { mIndex = index; }
    int top() { return mTop; }
    void setTop(int top) { mTop = top; }
    int left() { return mLeft; }
    void setLeft(int left) { mLeft = left; }
    int right() { return mRight; }
    void setRight(int right) { mRight = right; }
    int bottom() { return mBottom; }
    void setBottom(int bottom ){ mBottom = bottom; }
    int width() { return mWidth; }
    void setWidth(int width) { mWidth = width; }
    int height() { return mHeight; }
    void setHeight(int height) { mHeight = height; }
    QColor color() { return mColor; }
    void setColor(QColor c) { mColor = c; }
    QBrush brush() { return mBrush; }
    void setBrush(QBrush b) { mBrush = b; }
    int buttonStatus() { return mButtonStatus; }
    void setButtonStatus(int status) { mButtonStatus = status; }
    QPixmap pixmap() { return mPixmap;}
    void setPixmap(QPixmap m) { mPixmap = m;}
private:
    QString mName;
    QString mId;
    QString mNo;
    QString mCaption;
    int mIndex;
    int mX;
    int mY;
    int mTop;
    int mLeft;
    int mRight;
    int mBottom;
    int mWidth;
    int mHeight;
    QColor mColor;
    QBrush mBrush;
    QPixmap mPixmap;
    int mButtonStatus;
};
class QkGridWidget : public QWidget
{
    Q_OBJECT
public:

    explicit QkGridWidget(int rowCount , int columnCount ,QWidget *parent = 0);
    explicit QkGridWidget(QWidget *parent =0);
    enum QkButtonFlag {
        openFlag = 0x1,
        reservationFlag = 0x2,
        useFlag = 0x3,
        waitClearFlag = 0x4,
        invalidFlag= 0x5,
        closeFlag= 0x6
    };
    void setGridSize(int rowCount, int columnCount);
    void setButtonInvalid(int x,int y);
    void setName(int x,int y,QString id,QString name);
    void switchOn(int x,int y, const QColor& color);
    void switchOff(int x, int y);

    void selectOn(int x,int y);
    void selectOff(int x,int y);
    void clear();
    void clearSelection();
    void setCellSize(int size);
    QkButton getButton(int index);
    QkButton getButton(int x,int y);
    QkButton getButtonById(QString id);
    void setButtonStatus(QString id,int status,QColor color);
    void setButton(QString id,int status,QString no,QString name);
    void setButtonStatus(int x,int y,int status,QColor color);
    QPixmap * snap() ;
    QList<int> mCellSelected;
protected:
    void drawGrid(QPaintDevice * device);
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);

protected:
    void createGrid();
    QHash<int, QkButton >mButtons;


signals:
    void cellClicked(QPoint pos);


private:
    int mCellSize;
    int mHeight;
    int mWidth;
    int mRowCount;
    int mColumnCount;
    int mSpaceing;
    QPixmap mGridPix;


};
class KWIDGETSHARED_EXPORT QkGridView : public QScrollArea
{
    Q_OBJECT
public:
    explicit QkGridView(int row , int column,QWidget *parent = 0);
    explicit QkGridView(QWidget *parent = 0);
    ~QkGridView();
    void setName(int x,int y,QString id,QString name){
        mGridWidget->setName(x,y,id,name);
    }
    QList<int> getCellSelected(){
        return mGridWidget->mCellSelected;
    }
    void refresh(){
        mGridWidget->update();
    }
    void setGridSize(int rowCount, int columnCount){
        mGridWidget->setGridSize(rowCount,columnCount);
    }

    void switchOn(int x,int y, const QColor& color){
        mGridWidget->switchOn(x,y,color);
    }

    void switchOff(int x, int y){
        mGridWidget->switchOff(x,y);
    }

    void selectOn(int x,int y){
        mGridWidget->selectOn(x,y);
    }

    void selectOff(int x,int y){
        mGridWidget->selectOff(x,y);
    }

    void clear(){
        mGridWidget->clear();
    }

    void clearSelection(){
        mGridWidget->clearSelection();
    }

    void setCellSize(int size){
        mGridWidget->setCellSize(size);
    }
    QkButton getButton(int index){
        return mGridWidget->getButton(index);
    }
    void setButton(QString id,int status,QString no,QString name){
        mGridWidget->setButton(id,status,no,name);
    }
    void setButtonStatus(QString id,int status,QColor color){
        mGridWidget->setButtonStatus(id,status,color);
    }
    QkButton getButton(int x,int y){
        return mGridWidget->getButton(x,y);
    }
    QkButton getButtonById(QString id){
        return mGridWidget->getButtonById(id);
    }
    void setButtonStatus(int x,int y,int status,QColor color){
        mGridWidget->setButtonStatus(x,y,status,color);
    }
    QList<int> getCellSelecte(){
        return mGridWidget->mCellSelected;
    }
    QPixmap * snap() {
        return mGridWidget->snap();
    }
signals:
    void cellClicked(QPoint pos);

private:
    QkGridWidget * mGridWidget;
    
};

#endif // QKGRIDVIEW_H
