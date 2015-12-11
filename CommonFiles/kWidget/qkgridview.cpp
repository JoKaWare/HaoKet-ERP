#include "qkgridview.h"

QkGridWidget::QkGridWidget(int rowCount, int columnCount, QWidget *parent):
    QWidget(parent)
{

  mCellSize = 64;
  if(rowCount == 0)
    mRowCount = 10;
  else mRowCount = rowCount;
  if(columnCount == 0)
    mColumnCount = 1;
  else mColumnCount = columnCount;
  createGrid();

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

QkGridWidget::QkGridWidget(QWidget *parent):
    QWidget(parent)
{

  mCellSize = 64;
  mRowCount = 10;
  mColumnCount = 5;
  createGrid();

  setMinimumSize(500,500);
  for(int i=5;i<10;i++){
    setButtonInvalid(i,4);
  }

}
void QkGridWidget::setGridSize(int rowCount, int columnCount)
{
    mRowCount = rowCount;
    mColumnCount = columnCount;

    createGrid();
}

void QkGridWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    drawGrid(this);

    //update();
}

void QkGridWidget::mousePressEvent(QMouseEvent * event)
{
    if(event->x()<=(mWidth-5) && event->y()<=(mHeight-5)){
        int X = event->x() / (mCellSize+5);
        int Y = event->y() / (mCellSize+5);

        qDebug()<<"press"<<X<<" "<<Y;

        selectOn(X,Y);
        //switchOn(X,Y, QColor("#fba919"));
        //update(QRegion(X*mCellSize+5,Y*mCellSize+5,mCellSize,mCellSize));

        emit cellClicked(QPoint(X,Y));
        QWidget::mousePressEvent(event);
        update();
    }
}

void QkGridWidget::switchOn(int x, int y, const QColor &color)
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

void QkGridWidget::setButtonInvalid(int x, int y){
    int index =  mRowCount * y  + x;

    mButtons[index].setBrush(QBrush(Qt::Dense4Pattern));
    mButtons[index].setButtonStatus(QkGridWidget::invalidFlag);
}
void QkGridWidget::setButton(QString id,int status,QString no,QString name){
    foreach (int index , mButtons.keys()){

        if(mButtons[index].id().toInt() == id.toInt()){
            mButtons[index].setButtonStatus(status);
            mButtons[index].setNo(no);
            mButtons[index].setName(name);
        }
    }
}

void QkGridWidget::setButtonStatus(QString id,int status,QColor color){
    foreach (int index , mButtons.keys()){

        if(mButtons[index].id().toInt() == id.toInt()){
            mButtons[index].setButtonStatus(status);
            mButtons[index].setColor(color);
        }
    }
}

void QkGridWidget::setButtonStatus(int x,int y,int status,QColor color){
    int index =  mRowCount * y  + x;
    mButtons[index].setBrush(color);
    mButtons[index].setButtonStatus(status);
}
void QkGridWidget::setName(int x,int y,QString id,QString name){
    int index =  mRowCount * y  + x;

    mButtons[index].setName(name);
    mButtons[index].setCaption(name);
    mButtons[index].setId(id);
    mButtons[index].setX(x);
    mButtons[index].setY(y);

}

QkButton QkGridWidget::getButton(int index){
    return mButtons[index];
}

QkButton QkGridWidget::getButton(int x, int y){
    int index =  mRowCount * y  + x;
    return mButtons[index];
}

QkButton QkGridWidget::getButtonById(QString id){
    foreach (int index , mButtons.keys()){
        if(mButtons[index].id().toInt() == id.toInt()) return mButtons[index];

    }
    QkButton b;
    return b;
}
void QkGridWidget::switchOff(int x, int y)
{
    int index =  mRowCount * y  + x;
    mButtons[index].setButtonStatus(QkGridWidget::closeFlag);
}

void QkGridWidget::selectOn(int x, int y)
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

void QkGridWidget::selectOff(int x, int y)
{
    int index =  mRowCount * y  + x;
    mCellSelected.removeOne(index);
}

void QkGridWidget::clear()
{
    foreach (int index , mButtons.keys()){
         if(mButtons[index].buttonStatus() != QkGridWidget::invalidFlag){
             mButtons[index].setButtonStatus(QkGridWidget::openFlag);
             mButtons[index].setColor(Qt::white);
         }
    }
}

void QkGridWidget::clearSelection()
{
    mCellSelected.clear();
}

void QkGridWidget::setCellSize(int size)
{
    mCellSize = size;
}

QPixmap * QkGridWidget::snap()
{
    QPixmap * pix = new QPixmap(size());
    drawGrid(pix);
    return pix;
}


void QkGridWidget::drawGrid(QPaintDevice *device)
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
        QPixmap pixmap;
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
        }else if(mButtons[index].buttonStatus() == QkGridWidget::useFlag || mButtons[index].buttonStatus() == QkGridWidget::reservationFlag
                  || mButtons[index].buttonStatus() == QkGridWidget::waitClearFlag ){
            paint.setBrush(mButtons[index].color());
            QRect selector = QRect(x*mCellSize+(x+1)*j,y*mCellSize+(y+1)*h, mCellSize, mCellSize);
            //selector.adjust(-2,-2,2,2);
            //selector.adjust(6,6,3,3);
            paint.drawRect(selector);
            selector.adjust(7,7,3,3);
            paint.drawText(selector,mButtons[index].name());
            pixmap.load(":/images/right.png");
            paint.drawPixmap(x*mCellSize+(x+1)*j+48,y*mCellSize+(y+1)*h+48,16,16,pixmap);
        }

    }

    paint.end();

}


void QkGridWidget::createGrid()
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
    /*
    int i=0;

    for ( int y=5;y<height();y+=mCellSize+5 ){
        for ( int x=5;x<width();x+=mCellSize+5 ){
            QRect selector = QRect(x,y, mCellSize, mCellSize);
            //selector.adjust(6,6,3,3);
            paint.drawRect(selector);

            selector.adjust(7,7,3,3);
            paint.drawText(selector,"10"+QString::number(i)+"B ");
            i=i+1;
            //QPixmap pixmap = QPixmap(":/images/chair2_48.png");
            //paint.drawPixmap(x+10,y+10,53,53,pixmap);
        }
    }
    */
    int left=5;
    int top=5;
    for ( int y=0;y<mRowCount;y++ ){
        for ( int x=0;x<mColumnCount;x++ ){
            int index =  mColumnCount * y  + x;
            QkButton button;
            button.setX(x);
            button.setY(y);
            button.setLeft(left);
            button.setTop(top);
            button.setIndex(index);
            button.setColor(Qt::white);
            button.setButtonStatus(QkGridWidget::openFlag);
            mButtons[index] = button;
            QRect selector = QRect(left,top, mCellSize, mCellSize);
            //selector.adjust(6,6,3,3);
            paint.drawRect(selector);
            left+=mCellSize+5;
        }
        top+=mCellSize+5;
    }
}


QkGridView::QkGridView(int row, int column, QWidget *parent) :
    QScrollArea(parent)
{
    mGridWidget = new QkGridWidget(row,column,parent);
    setWidget(mGridWidget);
    connect(mGridWidget,SIGNAL(cellClicked(QPoint)),this,SIGNAL(cellClicked(QPoint)));
}
QkGridView::QkGridView(QWidget *parent) :
    QScrollArea(parent)
{
    mGridWidget = new QkGridWidget(parent);
    setWidget(mGridWidget);
    connect(mGridWidget,SIGNAL(cellClicked(QPoint)),this,SIGNAL(cellClicked(QPoint)));
}
QkGridView::~QkGridView(){
    delete mGridWidget;
}


