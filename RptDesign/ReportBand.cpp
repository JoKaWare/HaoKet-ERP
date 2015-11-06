/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include "ReportBand.h"
#include "ui_ReportBand.h"

ReportBand::ReportBand(QWidget *parent, BandType type, QTreeWidgetItem *item) :  QWidget(parent), ui(new Ui::ReportBand) {
    ui->setupUi(this);
    bandType = type;
    m_infocus = false;
    setMouseTracking(true);
    setFocusPolicy(Qt::ClickFocus);
    //widget->releaseMouse();

    contWidget = ui->conWidget;
    itemInTree = item;

    ui->conWidget->setMouseTracking(true);
    ui->conWidget->installEventFilter(this);
    ui->lblBandType->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    titleHeight = 14;
    QObject::connect(ui->lblBandType, SIGNAL(clicked()), this, SLOT(setFocus()));
    mode = NONE;
    QString stl = "background: yellow;"
                  "border-top-left-radius: 10px;"
                  "border-top-right-radius: 10px;"
                  "border-right-width: 1px;"
                  "border-right-color: black;"
                  "border-right-style: solid;"
                  "border-top-width: 1px;"
                  "border-top-color: black;"
                  "border-top-style: solid;"
                  "border-left-width: 1px;"
                  "border-left-color: black;"
                  "border-left-style: solid;";
    if (type == ReportTitle) {
        this->setObjectName("RepTitleBand");
        ui->lblBandType->setText(tr("Report title"));
        ui->lblBandType->setStyleSheet(stl);
    }
    if (type == ReportSummary) {
        this->setObjectName("ReportSummaryBand");
        ui->lblBandType->setText(tr("Report summary"));
        ui->lblBandType->setStyleSheet(stl);
    }
    if (type == PageHeader) {
        this->setObjectName("PageHeaderBand");
        ui->lblBandType->setText(tr("Page header"));
        ui->lblBandType->setStyleSheet(stl);
    }
    if (type == PageFooter) {
        this->setObjectName("PageFooterBand");
        ui->lblBandType->setText(tr("Page footer"));
        ui->lblBandType->setStyleSheet(stl);
    }
    if (type == MasterData) {
        this->setObjectName("MasterDataBand");
        ui->lblBandType->setText(tr("Master band"));
        ui->lblBandType->setStyleSheet(stl);
    }
    if (type == MasterFooter) {
        this->setObjectName("MasterFooterBand");
        ui->lblBandType->setText(tr("Master footer"));
        ui->lblBandType->setStyleSheet(stl);
    }
    if (type == MasterHeader) {
        this->setObjectName("MasterHeaderBand");
        ui->lblBandType->setText(tr("Master header"));
        ui->lblBandType->setStyleSheet(stl);
    }
    ui->conWidget->setStyleSheet("#conWidget {border: 1px solid black}");
    this->show();
}

void ReportBand::setMenu(QMenu *menu_) {
    QIcon icon;
    QAction *actBandDel = new QAction(tr("Delete"),this);
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/delete.png")), QIcon::Normal, QIcon::On);
    actBandDel->setObjectName("actBandDel");
    actBandDel->setIcon(icon);
    QObject::connect(actBandDel, SIGNAL(triggered()), this, SLOT(deleteLater()));

    QAction *sep = new QAction(this);
    sep->setSeparator(true);
    this->addActions(menu_->actions());
    this->addAction(sep);
    this->addAction(actBandDel);
}

void ReportBand::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Delete) {
        this->deleteLater();
    }
    if (QApplication::keyboardModifiers() == Qt::ShiftModifier) {
        if (e->key() == Qt::Key_Up) resize(width(),height()-1);
        if (e->key() == Qt::Key_Down) resize(width(),height()+1);
    }
}

bool ReportBand::eventFilter( QObject *obj, QEvent *evt ) {
    if ((evt->type() == QMouseEvent::MouseButtonPress) ||
       (evt->type() == QMouseEvent::MouseMove)) {
        QMouseEvent *m = static_cast< QMouseEvent * >( evt );
        QWidget *w = QApplication::widgetAt( m->globalPos() );
        if( w ) {
          if (m->type()==QMouseEvent::MouseButtonPress) {
              mousePressEvent(m);
          }
          if (m->type()==QMouseEvent::MouseMove) {
              mouseMoveEvent(m);
          }
        }
    }
    return QWidget::eventFilter(obj, evt);
}

void ReportBand::focusInEvent(QFocusEvent *e) {
    m_infocus = true;
    ui->conWidget->setStyleSheet("#conWidget {border: 1px dot-dash blue}");
    emit inFocus(true);
}

void ReportBand::focusOutEvent(QFocusEvent *e) {
    m_infocus = false;
    ui->conWidget->setStyleSheet("#conWidget {border: 1px solid black}");
    emit inFocus(false);    
}

void ReportBand::mouseReleaseEvent(QMouseEvent *e) {
    QWidget::mouseReleaseEvent(e);
}

void ReportBand::mousePressEvent(QMouseEvent *e) {
    position = QPoint(e->globalX()-geometry().x(), e->globalY()-geometry().y());
    QWidget::mouseMoveEvent(e);

    //if (!m_infocus) return;

    if (!e->buttons() & Qt::LeftButton) {
        setCursorShape(e->pos());
        return;
    }

    /*if(e->button()==Qt::RightButton) {
        popupShow(e->pos());
        e->accept();
    }*/
}

void ReportBand::setCursorShape(const QPoint &e_pos) {
    const int diff = 4;
    if ( e_pos.y() > y() + height() - diff) {
        setCursor(QCursor(Qt::SizeVerCursor));
        mode = RESIZEB;
    } else {
        setCursor(QCursor(Qt::ArrowCursor));
        mode = NONE;
    }
}

void ReportBand::mouseMoveEvent(QMouseEvent *e) {
    QWidget::mouseMoveEvent(e);
    if (!m_infocus) return;

    if (/*mode = NONE &*/ !e->buttons() & Qt::LeftButton) {
        QPoint p = QPoint(e->x()+geometry().x(), e->y()+geometry().y());
        setCursorShape(p);
        return;
    }
    if ((mode == MOVE) && e->buttons() && Qt::LeftButton) {
        move(e->globalPos() - position);
    }
    if ((mode != MOVE) && e->buttons() && Qt::LeftButton) {
        switch (mode){
            case RESIZEB: {
                resize(width(),e->y());
                break;}
            case RESIZER:  {
                resize(e->x(),height());
                break;}
            case RESIZEBR: {
                resize(e->x(),e->y());
                break;}
        }
    }
}

void ReportBand::resizeEvent (QResizeEvent *event) {
    endResizing(this->geometry());
}

ReportBand::~ReportBand() {
    emit delBand(this->itemInTree);
    delete ui;
}
