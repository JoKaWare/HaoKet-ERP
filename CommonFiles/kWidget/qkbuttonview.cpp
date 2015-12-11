#include "qkbuttonview.h"

QkButtonView::QkButtonView(QWidget *parent):
    QScrollArea(parent)
{
    mButtonViewWidget = new QkButtonViewWidget(parent);
    connect(mButtonViewWidget,SIGNAL(buttonClicked(int)),this,SIGNAL(buttonClicked(int)));
    setWidget(mButtonViewWidget);

}

QkButtonView::QkButtonView(QHash<int, QkButton> buttonList, QWidget *parent){
    mButtonViewWidget = new QkButtonViewWidget(buttonList,parent);
    connect(mButtonViewWidget,SIGNAL(buttonClicked(int)),this,SIGNAL(buttonClicked(int)));
    setWidget(mButtonViewWidget);
}
QkButtonView::~QkButtonView(){
    delete mButtonViewWidget;
}

QkButtonViewWidget::QkButtonViewWidget(QWidget *parent):
    QWidget(parent)
{
    setMinimumSize(650,450);
    mGridPix = QPixmap(size());
    mGridPix.fill(Qt::white);
    QPainter paint(&mGridPix);
    paint.setPen(QPen(Qt::black));
    paint.setBrush(QColor("#ffffff"));
    int tCount = 650/mWidth;

    int x = mX;
    int y = mY;
    for(int i =0;i < tCount ;i++){
        QToolButton *toolButton = new QToolButton(this);
        toolButton->setObjectName(QString::fromUtf8("toolButton") + QString::number(i));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/empty1.png"), QSize(), QIcon::Normal, QIcon::Off);

        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(mIconSize,mIconSize));
        toolButton->setText("À±½·³´Èâ\n$:38");
        toolButton->setFont(QFont(""));
        toolButton->setGeometry(QRect(x, y, mWidth, mHeight));
        //toolButton->setStyleSheet("QToolButton{display: table; background-color: #d9522c;color: white;padding: 0px 0px 0px 0px; border: none;font-size: 13px; font-weight: bold; cursor: pointer; opacity: 0.9;}");
        x = x + mWidth + mSpacing;
    }
}

QkButtonViewWidget::QkButtonViewWidget(QHash<int, QkButton> buttonList, QWidget *parent):
    QWidget(parent)
{
    setMinimumSize(652,450);
    mGridPix = QPixmap(size());
    mGridPix.fill(Qt::white);
    QPainter paint(&mGridPix);
    paint.setPen(QPen(Qt::black));
    paint.setBrush(QColor("#ffffff"));
    int tCount = 652/mWidth;

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/empty1.png"), QSize(), QIcon::Normal, QIcon::Off);

    int y = mY;
    int x = mX;
    int j = 0;
    QButtonGroup *group = new QButtonGroup(this);
    for(int i = 0; i < buttonList.size(); i++){
        if(j >= tCount){
            j = 0;
            x = mX;
            y = y + mHeight + mSpacing;
        }
        QToolButton *toolButton = new QToolButton(this);
        toolButton->setObjectName(QString::fromUtf8("toolButton") + QString::number(i));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(mIconSize,mIconSize));
        toolButton->setText(buttonList[i].name());
        toolButton->setGeometry(QRect(x, y, mWidth, mHeight));
        group->addButton(toolButton,buttonList[i].id().toInt());
        if(j < tCount){
            x = x + mWidth + mSpacing;
            j = j + 1;
        }
    }
    connect(group,SIGNAL(buttonClicked(int)),this,SIGNAL(buttonClicked(int)));
}


void QkButtonViewWidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event)
    drawGrid(this);
}

void QkButtonViewWidget::drawGrid(QPaintDevice *device){

    QPainter paint;
    paint.begin(device);
    paint.drawPixmap(0,0,mGridPix);
    paint.end();

}
