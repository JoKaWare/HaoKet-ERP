/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include "tcontainerfield.h"

TContainerField::TContainerField(QWidget *parent, QPoint p, QWidget *cWidget) : TContainer(parent,p,cWidget) {
    label = new QLabel("New Label", this);
    label->setVisible(true);
    label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    QString stl = "QLabel {;"
                  "border-width:1px;"
                  "border-style:solid;"
                  "border-color:rgba(0,0,0,255);"
                  "border-top-color:rgba(0,0,0,255);"
                  "border-left-color:rgba(0,0,0,255);"
                  "border-right-color:rgba(0,0,0,255);"
                  "border-bottom-color:rgba(0,0,0,255);"
                  "color:rgba(0,0,0,255);"
                  "background-color:rgba(255,255,255,0);"
            "}";
    this->setStyleSheet(stl);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->setChildWidget(label);
    this->resize(label->width()+40,label->height());
    label->releaseMouse();
    printing = "1";
    highlighting = "";

    menu = new QMenu(this);
}

void TContainerField::setMenu(QMenu *menu_) {
    QIcon icon;
    QAction *actContEdit = new QAction(tr("Edit"),this);
    actContEdit->setObjectName("actContEdit");
    QObject::connect(actContEdit, SIGNAL(triggered()), this, SLOT(edit()));

    QAction *actContDel = new QAction(tr("Delete"),this);
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/delete.png")), QIcon::Normal, QIcon::On);
    actContDel->setObjectName("actContDel");
    actContDel->setIcon(icon);
    QObject::connect(actContDel, SIGNAL(triggered()), this, SLOT(deleteLater()));

    menu->clear();
    menu->insertActions(0,menu_->actions());
    menu->addAction(actContEdit);
    menu->addAction(actContDel);
}

void TContainerField::allowEditing(bool value) {
    this->m_isEditing = value;
}

TContainerField *TContainerField::clone() {
    TContainerField *newContField  = new TContainerField(this->parentWidget(),QPoint(0,0),0);
    QPoint newPos(this->x(),this->y());
    newPos.setY(newPos.y()+5);
    newPos.setX(newPos.x()+5);

    newContField->setStyleSheet(this->styleSheet());
    newContField->setText(this->label->text());
    newContField->label->setFont(this->label->font());
    newContField->label->setAlignment(this->label->alignment());
    newContField->setGeometry(this->geometry());
    newContField->setVisible(true);
    newContField->move(newPos);
    return newContField;
}

//Получение значение цвета определенного параметра
QString TContainerField::getColorValue(Command param) {
    QString str1 = this->styleSheet();
    int start; int end;
    switch(param) {
        case FontColor: {
            start = str1.indexOf(";color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
        case BackgroundColor: {
            start = str1.indexOf(";background-color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
        case BorderColor: {
            start = str1.indexOf(";border-color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
        case FrameTop: {
            start = str1.indexOf(";border-top-color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
        case FrameBottom: {
            start = str1.indexOf(";border-bottom-color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
        case FrameLeft: {
            start = str1.indexOf(";border-left-color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
        case FrameRight: {
            start = str1.indexOf(";border-right-color:",0,Qt::CaseInsensitive);
            end = str1.indexOf(";",start+1,Qt::CaseInsensitive);
            break;
        }
    default: return "";
    }
    QString tmp = str1.mid(start+1,end-start-1);
    start = tmp.indexOf("rgba",0,Qt::CaseInsensitive);
    tmp = tmp.mid(start);
    if (start == -1) tmp = "";
    if (tmp == "#ffffff") tmp = "rgba(255,255,255,0)";
    return tmp;
}

void TContainerField::setBorder(Command command, QVariant values, bool yesFrame) {
    QColor color = values.value<QColor>();
    if (color.isValid()) { //Если цвет задается
        setSheetValue(BorderColor,TContainerField::colorToString(color));
    } else {  //иначе мы определяем цвет внесенный вначале
        colorFromString(color,getColorValue(BorderColor));
    }

    QString strColor = colorToString(color);

    QString stl = this->styleSheet();

    switch(command) {
        case None: {
            if (getColorValue(FrameTop) != "rgba(255,255,255,0)")
                setSheetValue(FrameTop,strColor);
            if (getColorValue(FrameBottom) != "rgba(255,255,255,0)")
                setSheetValue(FrameBottom,strColor);
            if (getColorValue(FrameLeft) != "rgba(255,255,255,0)")
                setSheetValue(FrameLeft,strColor);
            if (getColorValue(FrameRight) != "rgba(255,255,255,0)")
                setSheetValue(FrameRight,strColor);
            break;
        }
        case FrameNo: {
            setSheetValue(FrameTop,"rgba(255,255,255,0)");
            setSheetValue(FrameLeft,"rgba(255,255,255,0)");
            setSheetValue(FrameRight,"rgba(255,255,255,0)");
            setSheetValue(FrameBottom,"rgba(255,255,255,0)");
            break;
        }
        case FrameAll: {
            setSheetValue(FrameTop,strColor);
            setSheetValue(FrameLeft,strColor);
            setSheetValue(FrameRight,strColor);
            setSheetValue(FrameBottom,strColor);
            break;
        }
        case FrameTop:
        case FrameBottom:
        case FrameRight:
        case FrameLeft: {
            if (!yesFrame) strColor = "rgba(255,255,255,0)";
            setSheetValue(command,strColor);
            break;
        }
        case FrameStyle: {
            BorderStyle borderStyle = (BorderStyle)values.toInt();
            int start = stl.indexOf(";border-style:",0,Qt::CaseInsensitive);
            int end = stl.indexOf(";",start+1,Qt::CaseInsensitive);

            switch(borderStyle) {
                case Solid: {
                    stl.replace(start,end-start,";border-style:solid");
                    break;
                }
                case Dashed: {
                    stl.replace(start,end-start,";border-style:dashed");
                    break;
                }
                case Dotted: {
                    stl.replace(start,end-start,";border-style:dotted");
                    break;
                }
                case Dot_dash: {
                    stl.replace(start,end-start,";border-style:dot-dash");
                    break;
                }
                case Dot_dot_dash: {
                    stl.replace(start,end-start,";border-style:dot-dot-dash");
                    break;
                }
                case Double: {
                    stl.replace(start,end-start,";border-style:double");
                    break;
                }
                default: return;
            }
            setStyleSheet(stl);
            break;
        }
        case FrameWidth: {
            int start = stl.indexOf(";border-width:",0,Qt::CaseInsensitive);
            int end = stl.indexOf(";",start+1,Qt::CaseInsensitive);
            stl.replace(start,end-start,";border-width:"+values.toString()+"px");
            setStyleSheet(stl);
            break;
        }
        default: return;
    }
}

//Проверяем, есть ли та или иная сторона
bool TContainerField::borderIsCheck(Command command) {
    QString stl = this->styleSheet();
    int start; int end;
    if (command == FrameTop)
        start = stl.indexOf(";border-top-color:",0,Qt::CaseInsensitive);
    if (command == FrameLeft)
        start = stl.indexOf(";border-left-color:",0,Qt::CaseInsensitive);
    if (command == FrameRight)
        start = stl.indexOf(";border-right-color:",0,Qt::CaseInsensitive);
    if (command == FrameBottom)
        start = stl.indexOf(";border-bottom-color:",0,Qt::CaseInsensitive);

    end = stl.indexOf(";",start+1,Qt::CaseInsensitive);
    QString tmp = stl.mid(start+1,end-start-1);
    if (!tmp.contains("#ffffff") && !tmp.contains("rgba(255,255,255,0)"))  //Если не белый
        return true;
    else return false;
}

//Устанавливаем в СТИЛЕ значение определенного параметра
void TContainerField::setSheetValue(Command param, QString value) {
    QString str = this->styleSheet();
    int start; int end;
    if (value == "#ffffff") value = "rgba(255,255,255,0)";
    switch(param) {
        case FontColor: {
            start = str.indexOf(";color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";color:"+value);
            break;
        }
        case BackgroundColor: {
            start = str.indexOf(";background-color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";background-color:"+value);
            break;
        }
        case BorderColor: {
            start = str.indexOf(";border-color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-color:"+value);
            break;
        }
        case FrameTop: {
            start = str.indexOf(";border-top-color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-top-color:"+value);
            break;
        }
        case FrameBottom: {
            start = str.indexOf(";border-bottom-color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-bottom-color:"+value);
            break;
        }
        case FrameLeft: {
            start = str.indexOf(";border-left-color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-left-color:"+value);
            break;
        }
        case FrameRight: {
            start = str.indexOf(";border-right-color:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-right-color:"+value);
            break;
        }
        case FrameWidth: {
            start = str.indexOf(";border-width:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-width:"+value);
            break;
        }
        case FrameStyle: {
            start = str.indexOf(";border-style:",0,Qt::CaseInsensitive);
            end = str.indexOf(";",start+1,Qt::CaseInsensitive);
            str.replace(start,end-start,";border-style:"+value);
            break;
        }
        default: return;
    }
    setStyleSheet(str);
}

void TContainerField::setText(QString text) {
    label->setText(text);
}

QString TContainerField::getText() {
    return label->text();
}

void TContainerField::setImage(QPixmap p) {
    label->setPixmap(p);
    label->setScaledContents(true);
}

QPixmap TContainerField::getImage() {
    return *label->pixmap();
}

TContainerField::~TContainerField() {
    emit delCont(this->itemInTree);
}

void TContainerField::edit() {
    EditFldDlg *dlg = new EditFldDlg(this);
    if (type == Text || type == TextImage) {
        if (dlg->showText(this) == QDialog::Accepted)
            emit contChanged(true);
    }
    if (type == Image) {
        if (dlg->showImage(this) == QDialog::Accepted)
            emit contChanged(true);
    }
    delete dlg;
}

void TContainerField::mouseDoubleClickEvent (QMouseEvent * event) {
    edit();
}
