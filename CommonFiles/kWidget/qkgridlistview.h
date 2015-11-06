#ifndef QKGRIDLISTVIEW_H
#define QKGRIDLISTVIEW_H

#include <QtGui>
#include "kWidget_global.h"
#include "qkgridview.h"

class QkGridListViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QkGridListViewWidget(int rowCount , int columnCount ,QWidget *parent = 0);
    explicit QkGridListViewWidget(QWidget *parent =0);
    explicit QkGridListViewWidget(QHash<int, QkButton > buttonList,QWidget *parent =0);

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
    void setButtonStatus(QString id,int status,QColor color);
    void switchOn(int x,int y, const QColor& color);
    void switchOff(int x, int y);
    void selectOn(int x,int y);
    void selectOff(int x,int y);
    void clear();
    void clearSelection();
    void setCellSize(int size);
    QPixmap * snap() ;
    QList<int> mCellSelected;
protected:
    void drawGrid(QPaintDevice * device);
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);

protected:
    void createGrid(QHash<int, QkButton > buttonList);
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

class KWIDGETSHARED_EXPORT QKGridListView : public QScrollArea
{
    Q_OBJECT
public:
    explicit QKGridListView(QWidget *parent = 0);
    explicit QKGridListView(QHash<int, QkButton > buttonList,QWidget *parent = 0);
    ~QKGridListView();
    void setName(int x,int y,QString id,QString name){
        mGridWidget->setName(x,y,id,name);
    }
    QList<int> getCellSelected(){
        return mGridWidget->mCellSelected;
    }
    void refresh(){
        mGridWidget->update();
    }
    void setButtonStatus(QString id,int status,QColor color){
        mGridWidget->setButtonStatus(id,status,color);
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
    QPixmap * snap() {
        return mGridWidget->snap();
    }
signals:
    void cellClicked(QPoint pos);

private:
    QkGridListViewWidget * mGridWidget;
    
};

#endif // QKGRIDLISTVIEW_H
