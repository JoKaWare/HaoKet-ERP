/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include "EditFldDlg.h"
#include "ui_EditFldDlg.h"

EditFldDlg::EditFldDlg(QWidget *parent) :  QDialog(parent), ui(new Ui::EditFldDlg) {
    ui->setupUi(this);

    this->setStyleSheet("/**/");
    QObject::connect(ui->btnLoadImage, SIGNAL(clicked()), this, SLOT(loadImage()));
    QObject::connect(ui->btnAddVariable, SIGNAL(clicked()), this, SLOT(openProperty()));
    QObject::connect(ui->rdPrinting, SIGNAL(toggled(bool)), this, SLOT(conditionalToggled(bool)));
    QObject::connect(ui->rdTransparent, SIGNAL(toggled(bool)), this, SLOT(backGroundToggled(bool)));
    QObject::connect(ui->edtCondition, SIGNAL(textEdited(const QString&)), this, SLOT(conditionChanged(const QString&)));
    QObject::connect(ui->btnColorB, SIGNAL(clicked()), this, SLOT(chooseColor()));
    QObject::connect(ui->btnColorF, SIGNAL(clicked()), this, SLOT(chooseColor()));
    QObject::connect(ui->chkBold, SIGNAL(clicked()), this, SLOT(encodeHighLightingString()));
    QObject::connect(ui->chkItalic, SIGNAL(clicked()), this, SLOT(encodeHighLightingString()));
    QObject::connect(ui->chkUnderline, SIGNAL(clicked()), this, SLOT(encodeHighLightingString()));
}

void EditFldDlg::chooseColor() {
    QColor color;
    if (sender() == ui->btnColorF)
        m_cont->colorFromString(color,ui->lblColorF->styleSheet());
    if (sender() == ui->btnColorB)
        m_cont->colorFromString(color,ui->lblColorB->styleSheet());
    QColorDialog *dlg = new QColorDialog(color, this);
    if (dlg->exec() == QDialog::Accepted) {
        color = dlg->selectedColor();
    } else return;

    QString strColor = TContainerField::colorToString(color);
    if (sender() == ui->btnColorB)
        ui->lblColorB->setStyleSheet("QLabel {background-color: "+strColor+"}");
    if (sender() == ui->btnColorF)
        ui->lblColorF->setStyleSheet("QLabel {background-color: "+strColor+"}");

    encodeHighLightingString();
}

void EditFldDlg::conditionChanged(const QString &text) {
    if (ui->rdPrinting->isChecked())
        m_cond_printing = text;
    if (ui->rdHighlighting->isChecked())
        encodeHighLightingString();
}

//Switching between Printing and Highlighting
void EditFldDlg::conditionalToggled(bool value) {
    ui->grpBackground->setEnabled(!value);
    ui->grpFont->setEnabled(!value);

    if (value) { //Show printting condition
        encodeHighLightingString();
        ui->edtCondition->setText(m_cond_printing);
    } else {  //Show highlighting condtion
        m_cond_printing = ui->edtCondition->text();
        decodeHighLightingString();
        ui->edtCondition->setText(m_cond_higlighting.section(";",0,0));
    }

    backGroundToggled(!false);
}

void EditFldDlg::decodeHighLightingString() {
    QStringList list = m_cond_higlighting.split(";");
    for (int i=0; i<list.count(); i++) {
        if (list.at(i).contains("bold")) ui->chkBold->setChecked(true);
        if (list.at(i).contains("italic")) ui->chkItalic->setChecked(true);
        if (list.at(i).contains("underline")) ui->chkUnderline->setChecked(true);
        if (list.at(i).contains("fontColor")) {
            int start = list.at(i).indexOf("rgba(",0,Qt::CaseInsensitive);
            ui->lblColorF->setStyleSheet("QLabel {background-color: "+list.at(i).mid(start)+"}");
        }
        if (list.at(i).contains("backgroundColor")) {
            int start = list.at(i).indexOf("rgba(",0,Qt::CaseInsensitive);
            ui->lblColorB->setStyleSheet("QLabel {background-color: "+list.at(i).mid(start)+"}");
        }
    }
}

void EditFldDlg::encodeHighLightingString() {
    m_cond_higlighting.clear();
    if (ui->edtCondition->text().isEmpty()) return;

    QString tmpStr = ui->edtCondition->text();
    m_cond_higlighting = tmpStr+";"; //First item in section is always a condition

    if (ui->chkBold->isChecked())
        m_cond_higlighting  += "bold=?1:0;";
    if (ui->chkItalic->isChecked())
        m_cond_higlighting += "italic=?1:0;";
    if (ui->chkUnderline->isChecked())
        m_cond_higlighting += "underline=?1:0;";

    int startF = ui->lblColorF->styleSheet().indexOf("rgba(",0,Qt::CaseInsensitive);
    int endF = ui->lblColorF->styleSheet().indexOf(")",Qt::CaseInsensitive)+1;
    int startB = ui->lblColorB->styleSheet().indexOf("rgba(",0,Qt::CaseInsensitive);
    int endB = ui->lblColorB->styleSheet().indexOf(")",Qt::CaseInsensitive)+1;

    QString strColorF = ui->lblColorF->styleSheet().mid(startF,endF-startF);
    QString strColorB = ui->lblColorB->styleSheet().mid(startB,endB-startB);

    if (!strColorF.isEmpty() && strColorF != "255,255,255,255" && strColorF != "255,255,255,0") {
        m_cond_higlighting += "fontColor=?"+strColorF+";";
    }
    if (ui->rdOther->isChecked()) {
        if (!strColorB.isEmpty() && strColorB != "255,255,255,255" && strColorB != "255,255,255,0") {
            m_cond_higlighting += "backgroundColor=?"+strColorB+";";
        }
    }
}

void EditFldDlg::backGroundToggled(bool value) {
    ui->lblColorB->setEnabled(!value);
    ui->btnColorB->setEnabled(!value);
}

void EditFldDlg::openProperty() {
    FldPropertyDlg *dlg = new FldPropertyDlg(this);
    if (sender() == ui->btnAddVariable) {
        QString str = dlg->showThis(0);
        ui->textEdit->insertPlainText(str);
    }
    delete dlg;
}

int EditFldDlg::showText(TContainerField *cont) {
    ui->textEdit->setPlainText(cont->getText());
    ui->stackedWidget->setCurrentIndex(0);
    ui->textEdit->setFocus();
    m_cont = cont;

    boolImage = cont->type == TextImage ? true : false;
    ui->chkImage->setChecked(boolImage);
    ui->lblAttention->setVisible(boolImage);
    ui->rdPrinting->setChecked(true);

    if (cont->printing.size() > 1) {
        m_cond_printing = cont->printing.replace("?1:0","");
        ui->edtCondition->setText(m_cond_printing);
    }
    if (cont->highlighting.size() > 0) {
        m_cond_higlighting = cont->highlighting;
        decodeHighLightingString();
    }

    if (this->exec()) {
        if (ui->chkImage->isChecked()) cont->type = TextImage;
        else cont->type = Text;

        cont->setText(ui->textEdit->toPlainText());

        if (m_cond_printing.size() > 0)
            cont->printing = m_cond_printing+"?1:0";
        else {
            if (cont->printing.size() > 1)  //If previous was a Formula, now just a Visible
                cont->printing = "1";
        }
        if (m_cond_higlighting.size() > 0) {
            cont->highlighting = m_cond_higlighting;
        } else
            cont->highlighting = "";

        return QDialog::Accepted;
    } else return QDialog::Rejected;
}

int EditFldDlg::showImage(TContainerField *cont) {
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setPixmap(cont->getImage());
    if (this->exec()) {
        cont->setImage(*ui->label->pixmap());

        return QDialog::Accepted;
    } else return QDialog::Rejected;
}

void EditFldDlg::loadImage() {
    QString fileName = QFileDialog::getOpenFileName(this);
    const int w = this->width();
    const int h = this->height();
    if (!fileName.isEmpty()) {
        QPixmap p;
        p.load(fileName);        
        ui->label->setPixmap(p);
        ui->label->setScaledContents(true);
        //ui->label->pixmap()->scaled(w,h,Qt::KeepAspectRatio);
        //ui->label->adjustSize();
        //ui->label->resize(ui->label->pixmap()->size());
       // ui->label->updateGeometry();
    }
}

EditFldDlg::~EditFldDlg() {
    delete ui;
}

