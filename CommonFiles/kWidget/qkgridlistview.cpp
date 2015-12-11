#include "qkgridlistview.h"

QkGridListViewWidget::QkGridListViewWidget(int rowCount, int columnCount, QWidget *parent):
    QWidget(parent)
{

  mCellSize = 64;
  if(rowCount == 0)
    mRowCount = 10;
  else mRowCount = rowCount;
  if(columnCount == 0)
    mColumnCount = 1;
  else mColumnCount = columnCount;


  setMinimumSize(500,450);
  //switchOn(1,0,Qt::green);
  /*
  switchOn(1,0,QColor("#fba919"));
  if(rowCount == 0 || columnCount == 0)
      for(int i=0;i<10;i++){
        setButtonInvalid(i,0);
      }
  */

}
QkGridListViewWidget::QkGridListViewWidget(QWidget *parent):
    QWidget(parent)
{

  mCellSize = 64;
  mRowCount = 10;
  mColumnCount = 5;
  setMinimumSize(480,480);


}
QkGridListViewWidget::QkGridListViewWidget(QHash<int, QkButton > buttonList,QWidget *parent):
    QWidget(parent)
{

  mCellSize = 64;
  mRowCount = 10;
  mColumnCount = 1;
  setMinimumSize(480,480);
  createGrid(buttonList);




}
void QkGridListViewWidget::setGridSize(int rowCount, int columnCount)
{
    mRowCount = rowCount;
    mColumnCount = columnCount;

}

void QkGridListViewWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    drawGrid(this);

    //update();
}

void QkGridListViewWidget::mousePressEvent(QMouseEvent * event)
{
    if(event->x()<=(mWidth-5) && event->y()<=(mHeight-5)){
        int X = event->x() / (mCellSize+5);
        int Y = event->y() / (mCellSize+5);

        qDebug()<<"press"<<X<<" "<<Y;

        //selectOn(X,Y);
        //switchOn(X,Y, QColor("#fba919"));
        //update(QRegion(X*mCellSize+5,Y*mCellSize+5,mCellSize,mCellSize));

        emit cellClicked(QPoint(X,Y));
        QWidget::mousePressEvent(event);
        update();
    }
}

void QkGridListViewWidget::switchOn(int x, int y, const QColor &color)
{

    int index =  mRowCount * y  + x;

    if(mButtons[index].buttonStatus() != QkGridWidget::invalidFlag){
        //QString str=QString::number(x)+","+QString::number(y)+" "+QString::number(index);
        //mButtons[index].setName(str);
        mButtons[index].setColor(color);
        mButtons[index].setButtonStatus(QkGridWidget::useFlag);
    }

    qDebug()<<"index: "<<index;

}

void QkGridListViewWidget::setButtonInvalid(int x, int y){
    int index =  mRowCount * y  + x;

    mButtons[index].setBrush(QBrush(Qt::Dense4Pattern));
    mButtons[index].setButtonStatus(QkGridWidget::invalidFlag);
}
void QkGridListViewWidget::setButtonStatus(QString id,int status,QColor color){
    foreach (int index , mButtons.keys()){

        if(mButtons[index].id() == id){
            mButtons[index].setButtonStatus(status);
            mButtons[index].setColor(color);
        }
    }
}
void QkGridListViewWidget::setName(int x,int y,QString id,QString name){
    int index =  mRowCount * y  + x;

    mButtons[index].setName(name);
    mButtons[index].setId(id);

}
void QkGridListViewWidget::switchOff(int x, int y)
{
    int index =  mRowCount * y  + x;
    mButtons[index].setButtonStatus(QkGridWidget::closeFlag);
}

void QkGridListViewWidget::selectOn(int x, int y)
{
    int index =  mRowCount * y  + x;
    bool selected=true;
    for(int i=0;i<mCellSelected.length();i++){
        if(mCellSelected.at(i) == index){
            selected=false;
             mCellSelected.removeOne(index);
            break;
        }
    }
    if(selected)
        mCellSelected.append(index);
}

void QkGridListViewWidget::selectOff(int x, int y)
{
    int index =  mRowCount * y  + x;
    mCellSelected.removeOne(index);
}

void QkGridListViewWidget::clear()
{
    mButtons.clear();
}

void QkGridListViewWidget::clearSelection()
{
    mCellSelected.clear();
}

void QkGridListViewWidget::setCellSize(int size)
{
    mCellSize = size;
}

QPixmap * QkGridListViewWidget::snap()
{
    QPixmap * pix = new QPixmap(size());
    drawGrid(pix);
    return pix;
}


void QkGridListViewWidget::drawGrid(QPaintDevice *device)
{

    QPainter paint;
    paint.begin(device);
    paint.drawPixmap(0,0,mGridPix);
    //Draw Square
    foreach (int index , mButtons.keys())
    {
        int y = qRound(index/mRowCount);
        int x = index % mRowCount;
        QPixmap pixmap;
        if(mButtons[index].id().trimmed().length()<1){
            mButtons[index].setBrush(QBrush(Qt::Dense4Pattern));
            mButtons[index].setButtonStatus(QkGridWidget::invalidFlag);
        }
        if(mButtons[index].buttonStatus() == QkGridWidget::invalidFlag ||
                mButtons[index].buttonStatus() == QkGridWidget::closeFlag ){
            paint.setBrush(mButtons[index].brush());
        }else if(mButtons[index].buttonStatus() == QkGridWidget::openFlag){
            //pixmap.load(":/images/chair_48.png");
            paint.setBrush(mButtons[index].color());
        }else if(mButtons[index].buttonStatus() == QkGridWidget::useFlag){
            mButtons[index].setColor(QColor("#fba919"));
            paint.setBrush(QColor("#fba919"));
            //pixmap.load(":/images/chair_48.png");

        }else if(mButtons[index].buttonStatus() == QkGridWidget::reservationFlag){
            mButtons[index].setColor(QColor("#ad82b1"));
            paint.setBrush(QColor("#ad82b1"));
        }else if(mButtons[index].buttonStatus() == QkGridWidget::waitClearFlag){
            mButtons[index].setColor(QColor("#d9522c"));
            paint.setBrush(QColor("#d9522c"));
        }
        int j=5;
        int h=5;

        QRect selector = QRect(x*mCellSize+(x+1)*j,y*mCellSize+(y+1)*h, mCellSize, mCellSize);
        //selector.adjust(5,5,0,0);
        paint.drawRect(selector);
        selector.adjust(7,7,3,3);
        paint.drawText(selector,mButtons[index].name());

        paint.drawPixmap(x*mCellSize+(x+1)*j+5,y*mCellSize+(y+1)*h+20,53,53,pixmap);
    }

    //Draw SquareSelector

    foreach (int index, mCellSelected)
    {
        int y = qRound(index/mRowCount);
        int x = index % mRowCount;

        int j=5;
        int h=5;
        if(mButtons[index].buttonStatus() == QkGridWidget::openFlag){
            paint.setBrush(QColor("#7dcd0c"));
            QRect selector = QRect(x*mCellSize+(x+1)*j,y*mCellSize+(y+1)*h, mCellSize, mCellSize);
            //selector.adjust(-2,-2,2,2);
            //selector.adjust(6,6,3,3);
            paint.drawRect(selector);
            selector.adjust(7,7,3,3);
            paint.drawText(selector,mButtons[index].name());
        }

    }

    paint.end();

}


void QkGridListViewWidget::createGrid(QHash<int, QkButton > buttonList)
{
    mWidth=mRowCount*mCellSize+5*(mRowCount+1);
    mHeight=mColumnCount*mCellSize+5*(mColumnCount+1);
    resize(mWidth, mHeight);
    setFixedSize(size());
    mGridPix = QPixmap(size());
    mGridPix.fill(Qt::white);
    QPainter paint(&mGridPix);
    paint.setPen(QPen(Qt::black));
    paint.setBrush(QColor("#ffffff"));

    int i = 0;
    foreach (int index , buttonList.keys())
    {
        int y = qRound(index/mRowCount);
        int x = index % mRowCount;
        QPixmap pixmap;
        buttonList[index].setColor(QColor("#7dcd0c"));
        mButtons[i] = buttonList[index];

        i++;
        if(buttonList[index].buttonStatus() == QkGridWidget::invalidFlag ||
                buttonList[index].buttonStatus() == QkGridWidget::closeFlag ){
            paint.setBrush(buttonList[index].brush());
        }else if(buttonList[index].buttonStatus() == QkGridWidget::openFlag){
            //pixmap.load(":/images/chair_48.png");
            paint.setBrush(buttonList[index].color());
        }else if(buttonList[index].buttonStatus() == QkGridWidget::useFlag){
            paint.setBrush(buttonList[index].color());
            pixmap.load(":/images/chair_48.png");

        }
        int j=5;
        int h=5;

        QRect selector = QRect(x*mCellSize+(x+1)*j,y*mCellSize+(y+1)*h, mCellSize, mCellSize);
        //selector.adjust(5,5,0,0);
        paint.drawRect(selector);
        selector.adjust(7,7,3,3);
        paint.drawText(selector,buttonList[index].name());

        paint.drawPixmap(x*mCellSize+(x+1)*j+5,y*mCellSize+(y+1)*h+20,53,53,pixmap);
    }

}

QKGridListView::QKGridListView(QWidget *parent) :
    QScrollArea(parent)
{
    mGridWidget = new QkGridListViewWidget(parent);
    setWidget(mGridWidget);
    connect(mGridWidget,SIGNAL(cellClicked(QPoint)),this,SIGNAL(cellClicked(QPoint)));
}

QKGridListView::QKGridListView(QHash<int, QkButton > buttonList,QWidget *parent) :
    QScrollArea(parent)
{
    mGridWidget = new QkGridListViewWidget(buttonList,parent);
    setWidget(mGridWidget);
    connect(mGridWidget,SIGNAL(cellClicked(QPoint)),this,SIGNAL(cellClicked(QPoint)));
}
QKGridListView::~QKGridListView(){
    delete mGridWidget;
}


