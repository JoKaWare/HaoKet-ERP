#include <QtGui>
#include <QBoxLayout>
#include <QStandardItemModel>
#include "qksearcheditbox.h"
#include "qksearcheditbox_p.h"

QkSearchEditBox::QkSearchEditBox(QWidget *parent) : QWidget(*new QkSearchEditBoxPrivate(),parent,0) {
    Q_D(QkSearchEditBox);
    d->init();

    d->m_lineedit->installEventFilter(this);
    setListView(new QListView(d->m_lineedit));
    this->setFocusProxy(d->m_lineedit);
    this->setFocusPolicy(Qt::StrongFocus);
    d->m_listview->installEventFilter(this);
    d->m_listview->setFocusProxy(d->m_lineedit);
    d->m_bEditFocus=true;
    QStringList s;
    this->setItems(s);
    connect(d->m_lineedit, SIGNAL(textEdited(const QString &)), this, SLOT(keytextChanged(const QString &)));
    connect(d->m_lineedit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
    connect(d->m_lineedit, SIGNAL(textChanged(QString)), this, SIGNAL(editChanged(QString)));
    //connect(d->m_button, SIGNAL(clicked()), this, SLOT(showList()));
    connect(d->m_button, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));

}

QkSearchEditBox::QkSearchEditBox(QkSearchEditBoxPrivate &priv, QWidget *parent) : QWidget(priv,parent,0) {
    Q_D(QkSearchEditBox);
    d->init();
    d->m_lineedit->installEventFilter(this);
    setListView(new QListView(this));
    this->setFocusProxy(d->m_lineedit);
    this->setFocusPolicy(Qt::StrongFocus);
    d->m_listview->setFocusProxy(d->m_listview);
    d->m_bEditFocus=true;
    QStringList s;
    this->setItems(s);
    connect(d->m_lineedit, SIGNAL(textEdited(const QString &)), this, SLOT(keytextChanged(const QString &)));
    connect(d->m_lineedit, SIGNAL(textChanged(QString)), this, SIGNAL(editChanged(QString)));
    connect(d->m_lineedit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
    //connect(d->m_button, SIGNAL(clicked()), this, SLOT(showPopup()));
    connect(d->m_button, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
}

void QkSearchEditBox::clear(){
    Q_D(QkSearchEditBox);
    d->m_lineedit->clear();
    d->m_lineedit_sub->clear();
}

void QkSearchEditBox::setListModel(bool b){
    Q_D(QkSearchEditBox);
    if(b){
        connect(d->m_button, SIGNAL(clicked()), this, SLOT(btnClick()));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/down1.png"), QSize(), QIcon::Normal, QIcon::Off);
        d->m_button->setIcon(icon);
        d->m_button->setIconSize(QSize(16,16));

        QFont serifFont("Times", 6.5);
        d->m_button->setFont(serifFont);
        //d->m_button->setAutoRaise(true);
        //d->m_button->setStyleSheet("QToolButton{background-color:white;border: none;}");
    }else{
        connect(d->m_button, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
    }
}
void QkSearchEditBox::setText(const QString &text){
    Q_D(QkSearchEditBox);
    QStringList strText=text.split(" - ");
    d->m_lineedit->setText(strText.at(0).trimmed());
    if(strText.length()>1){
        d->m_lineedit_sub->setText(strText.at(1).trimmed());
        //emit buttonClicked();
    }
}

QString QkSearchEditBox::text(){
    Q_D(QkSearchEditBox);
    return d->m_lineedit->text();
}

QString QkSearchEditBox::subText(){
    Q_D(QkSearchEditBox);
    return d->m_lineedit_sub->text();
}

void QkSearchEditBox::setReadOnly(bool readOnly){
    Q_D(QkSearchEditBox);
    d->m_lineedit->setReadOnly(readOnly);
    d->m_lineedit_sub->setReadOnly(readOnly);
    if(readOnly)
        d->m_button->setEnabled(false);
    else
        d->m_button->setEnabled(true);
}

bool QkSearchEditBox::eventFilter(QObject *target, QEvent *event){

    Q_D(QkSearchEditBox);
    switch (event->type()){
    case QEvent::KeyPress:{
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        QModelIndex curIndex = d->m_listview->currentIndex();
        QModelIndexList selList = d->m_listview->selectionModel()->selectedIndexes();
        const int key = ke->key();

        if ((key == Qt::Key_Up || key == Qt::Key_Down) && selList.isEmpty() && curIndex.isValid() )
        {
            d->m_listview->setCurrentIndex(curIndex);
            return true;
        }

        switch (key)
        {
        case Qt::Key_End:
        case Qt::Key_Home:
            if (ke->modifiers() & Qt::ControlModifier)
                return false;
            break;

        case Qt::Key_Up:
            if (!curIndex.isValid())
            {
                int rowCount = d->m_listview->model()->rowCount();
                QModelIndex lastIndex = d->m_listview->model()->index(rowCount - 1, d->m_listview->modelColumn());
                d->m_listview->setCurrentIndex(lastIndex);
                return true;
            }
            else if (curIndex.row() == 0)
            {
                return true;
            }
            return false;

        case Qt::Key_Down:
            if (!curIndex.isValid())
            {
                QModelIndex firstIndex = d->m_listview->model()->index(0, d->m_listview->modelColumn());
                d->m_listview->setCurrentIndex(firstIndex);
                return true;
            }
            else if (curIndex.row() == d->m_listview->model()->rowCount() - 1)
            {
                return true;
            }
            return false;
        case Qt::Key_Return:
        case Qt::Key_Enter:
        case Qt::Key_Tab:
            hidePopup();
            if (curIndex.isValid())
            {
                QString text = d->m_listview->currentIndex().data().toString();
                setText(text);
            }
            break;

        case Qt::Key_F4:
            if (ke->modifiers() & Qt::AltModifier)
                hidePopup();
            break;

        case Qt::Key_Backtab:
        case Qt::Key_Escape:
            hidePopup();
            break;

        default:
            break;
        }

        d->m_bEditFocus = false;
        (static_cast<QObject *>(d->m_lineedit))->event(ke);

        d->m_bEditFocus = true;
        if ( event->isAccepted() || !d->m_listview->isVisible()) {
            if (!d->m_lineedit->hasFocus() )
                hidePopup();
            if (event->isAccepted())
                return true;
        }
        return target->event(event);

    }
    case QEvent::MouseButtonPress:
        qDebug() << target->objectName() << event->type();
        qDebug() << d->m_listview->underMouse();
        if (!d->m_listview->underMouse())
        {
            hidePopup();
            return true;
        }else if(event->isAccepted() || !d->m_listview->isVisible()){
            hidePopup();
            return true;
        }
        return true;
    case QEvent::InputMethod:
    default:
        /*
        if ((target == d->m_listview || target == d->m_lineedit) && event->type() == QEvent::FocusOut) {

            if (d->m_listview && d->m_listview->isVisible() )
                return true;
        }
        */
        return false;
    }
    return false;


}

void QkSearchEditBox::resizeEvent(QResizeEvent *){
    Q_D(QkSearchEditBox);
    d->updateGeometry();
    //updateGeometry();


}

void QkSearchEditBox::paintEvent(QPaintEvent *e){
    //Q_D(QkSearchEditBox);
    //d->updateGeometry();
}
void QkSearchEditBox::hidePopup(){
    Q_D(QkSearchEditBox);
    d->m_listview->hide();
}

void QkSearchEditBox::btnClick(){
    Q_D(QkSearchEditBox);
    //过滤二级文字

    if(d->m_lineedit_sub->text().trimmed().length() > 0 && d->m_lineedit->text().trimmed().length() < 1 ){
        QRegExp::PatternSyntax syntax =
                QRegExp::PatternSyntax(QRegExp::Wildcard);
        Qt::CaseSensitivity caseSensitivity =Qt::CaseInsensitive;

        QRegExp regExp(d->m_lineedit_sub->text().trimmed(), caseSensitivity, syntax);
        d->proxyModel->setFilterRegExp(regExp);
    }else{
        QRegExp::PatternSyntax syntax =
                QRegExp::PatternSyntax(QRegExp::Wildcard);
        Qt::CaseSensitivity caseSensitivity =Qt::CaseInsensitive;

        QRegExp regExp("", caseSensitivity, syntax);
        d->proxyModel->setFilterRegExp(regExp);
    }

    showPopup();
}

void QkSearchEditBox::showPopup(){
    Q_D(QkSearchEditBox);

    QRect listRect=this->geometry();
    QPoint p=this->pos();
    QPoint above = mapToGlobal(p);
    listRect.moveTop(above.y()-p.y()+d->m_lineedit->height());
    listRect.moveLeft(above.x()-p.x());
    d->m_listview->setGeometry(listRect);
    d->m_listview->show();


}

void QkSearchEditBox::keytextChanged(const QString s){
    Q_D(QkSearchEditBox);

    /*
    bool sub_clear=true;
    foreach(QString word, d->m_stringList) {

        QStringList wordList = word.split("-");
        if(wordList.at(0).trimmed()==s)sub_clear=false;
    }

    if(sub_clear)d->m_lineedit_sub->setText("");
    */
    d->m_lineedit_sub->setText("");
    /*
    if (sl.size() == 0){
        hidePopup();
        return;
    }
    */
    QRegExp::PatternSyntax syntax =
            QRegExp::PatternSyntax(QRegExp::Wildcard);
    Qt::CaseSensitivity caseSensitivity =Qt::CaseInsensitive;

    QRegExp regExp(s, caseSensitivity, syntax);
    d->proxyModel->setFilterRegExp(regExp);
    showPopup();
}

void QkSearchEditBox::setItems(const QStringList &sList){
    Q_D(QkSearchEditBox);
    d->m_stringList=sList;

    d->m_stringListmodel->setStringList(sList);

    d->proxyModel = new QSortFilterProxyModel(this);
    d->proxyModel->setSourceModel(d->m_stringListmodel);
    d->proxyModel->setDynamicSortFilter(true);

    d->m_listview->setModel(d->proxyModel);

}

QStringList QkSearchEditBox::items(){
    Q_D(QkSearchEditBox);
    return d->m_stringList;
}

void QkSearchEditBox::clickedSlot(QModelIndex modelIndex)
{
    Q_D(QkSearchEditBox);
    setText(d->m_listview->model()->data(modelIndex).toString());
    hidePopup();
}

void QkSearchEditBox::returnPressed(){

}

void QkSearchEditBox::setListView(QListView *itemView){
    Q_D(QkSearchEditBox);
    itemView->setAttribute(Qt::WA_WindowPropagation);
    itemView->setAttribute(Qt::WA_X11NetWmWindowTypeMenu);
    itemView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    itemView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    itemView->setSelectionBehavior(QAbstractItemView::SelectRows);
    itemView->setSelectionMode(QAbstractItemView::SingleSelection);
    itemView->setFocusPolicy(Qt::NoFocus);
    itemView->setMinimumHeight(100);
    itemView->setParent(0,Qt::Popup);
    d->m_stringListmodel = new QStringListModel(this);
    itemView->setModel(d->m_stringListmodel);
    d->m_listview=itemView;

    QObject::connect(d->m_listview, SIGNAL(clicked(QModelIndex)),
        this, SLOT(clickedSlot(QModelIndex)));

}

void QkSearchEditBox::setRegExp(const QString &v) {
    Q_D(QkSearchEditBox);
    QValidator *valid = const_cast<QValidator*>(d->m_lineedit->validator());
    QRegExpValidator *rxvalid = qobject_cast<QRegExpValidator*>(valid);
    if (rxvalid && rxvalid->regExp().pattern()==v) {
        return;
    }
    QRegExp rx(v);
    if (v==".*" || v.isEmpty()) {
        d->m_lineedit->setValidator(0);
        emit validatorChanged(".*");
        return;
    }
    if (rxvalid) {
        rxvalid->setRegExp(rx);
    } else {
        d->m_lineedit->setValidator(new QRegExpValidator(rx, this));
    }
    emit validatorChanged(v);
}

void QkSearchEditBox::setRegExp(const QRegExp &rx) {
    Q_D(QkSearchEditBox);
    QValidator *valid = const_cast<QValidator*>(d->m_lineedit->validator());
    QRegExpValidator *rxvalid = qobject_cast<QRegExpValidator*>(valid);
    if (rxvalid && rxvalid->regExp()==rx) {
        return;
    }
    if (rx.pattern()==".*") {
        d->m_lineedit->setValidator(0);
        emit validatorChanged(".*");
        return;
    }
    if (rxvalid) {
        rxvalid->setRegExp(rx);
    } else {
        d->m_lineedit->setValidator(new QRegExpValidator(rx, this));
    }
    emit validatorChanged(rx.pattern());
}

QkSearchEditBoxPrivate::QkSearchEditBoxPrivate()
    : QWidgetPrivate(),
      m_lineedit(0),
      m_lineedit_sub(0),
      m_button(0)
{
}


QkSearchEditBoxPrivate::QkSearchEditBoxPrivate(QkSearchEditBox *searcheditbox)
    : QWidgetPrivate(),
      m_lineedit(0),
      m_lineedit_sub(0),
      m_button(0)
{
}

void QkSearchEditBoxPrivate::updateGeometry(){

    if (!m_lineedit)
        return;

    Q_Q(QkSearchEditBox);

    QRect wrect = q->rect();
    /*
    if(wrect.width()/2 > 120)
        m_lineedit->setGeometry(wrect.left(),wrect.top()+1,wrect.width()/3-20,wrect.height()-1);
    else
        m_lineedit->setGeometry(wrect.left(),wrect.top()+1,wrect.width()/2-20,wrect.height()-1);
    */
    if(wrect.width()/3 > 240)
        m_lineedit->setGeometry(wrect.left(),wrect.top()+1,240/3+20,wrect.height()-1);
    else
        m_lineedit->setGeometry(wrect.left(),wrect.top()+1,240/3-20,wrect.height()-1);

    m_lineedit_sub->setGeometry(wrect.left()+m_lineedit->width()+1,wrect.top()+1,wrect.width()-20-m_lineedit->width(),wrect.height()-1);

    m_button->setGeometry(m_lineedit->width()+m_lineedit_sub->width()+1,wrect.top()+1,20,20);
    if(q->m_listModel)
        m_button->setGeometry(m_lineedit->width()+m_lineedit_sub->width()+1,wrect.top()+2,20,wrect.height()-1);
    if(!m_listview->isHidden()){
        QRect listRect=q->geometry();
        QPoint p=q->pos();
        QPoint above = q->mapToGlobal(p);
        listRect.moveTop(above.y()-p.y()+m_lineedit->height());
        listRect.moveLeft(above.x()-p.x());
        m_listview->setGeometry(listRect);
    }

}

void QkSearchEditBox::showList(){

}

void QkSearchEditBoxPrivate::init(){
    Q_Q(QkSearchEditBox);
    m_lineedit=new QLineEdit(q);
    m_lineedit_sub=new QLineEdit(q);
    m_button=new QToolButton(q);
    m_lineedit->setFocusPolicy(Qt::WheelFocus);
    m_button->setText("..");

    q->setMinimumHeight(22);
    q->setMaximumHeight(22);
    q->setMinimumWidth(180);

    q->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    m_lineedit->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
}


