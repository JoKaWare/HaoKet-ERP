/********************************************************************************
** Form generated from reading UI file 'EditFldDlg.ui'
**
** Created: Thu Jul 10 16:17:56 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFLDDLG_H
#define UI_EDITFLDDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditFldDlg
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnAddVariable;
    QToolButton *btnAddFunction;
    QToolButton *btnFormatting;
    QCheckBox *chkImage;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *textEdit;
    QLabel *lblAttention;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rdPrinting;
    QRadioButton *rdHighlighting;
    QGroupBox *grpCondition;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *edtCondition;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *grpFont;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *chkBold;
    QCheckBox *chkItalic;
    QCheckBox *chkUnderline;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblColorF;
    QPushButton *btnColorF;
    QGroupBox *grpBackground;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *rdTransparent;
    QRadioButton *rdOther;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblColorB;
    QPushButton *btnColorB;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnLoadImage;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *EditFldDlg)
    {
        if (EditFldDlg->objectName().isEmpty())
            EditFldDlg->setObjectName(QString::fromUtf8("EditFldDlg"));
        EditFldDlg->resize(400, 312);
        verticalLayout = new QVBoxLayout(EditFldDlg);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(6);
#endif
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(EditFldDlg);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 2, 0, 0);
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 3);
        btnAddVariable = new QToolButton(widget_2);
        btnAddVariable->setObjectName(QString::fromUtf8("btnAddVariable"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/variable.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddVariable->setIcon(icon);

        horizontalLayout_3->addWidget(btnAddVariable);

        btnAddFunction = new QToolButton(widget_2);
        btnAddFunction->setObjectName(QString::fromUtf8("btnAddFunction"));
        btnAddFunction->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/function.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddFunction->setIcon(icon1);

        horizontalLayout_3->addWidget(btnAddFunction);

        btnFormatting = new QToolButton(widget_2);
        btnFormatting->setObjectName(QString::fromUtf8("btnFormatting"));
        btnFormatting->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/formating.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFormatting->setIcon(icon2);

        horizontalLayout_3->addWidget(btnFormatting);

        chkImage = new QCheckBox(widget_2);
        chkImage->setObjectName(QString::fromUtf8("chkImage"));

        horizontalLayout_3->addWidget(chkImage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_5->addWidget(widget_2);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);

        lblAttention = new QLabel(tab);
        lblAttention->setObjectName(QString::fromUtf8("lblAttention"));
        lblAttention->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(lblAttention);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_9 = new QVBoxLayout(tab_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rdPrinting = new QRadioButton(tab_2);
        buttonGroup = new QButtonGroup(EditFldDlg);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(rdPrinting);
        rdPrinting->setObjectName(QString::fromUtf8("rdPrinting"));
        rdPrinting->setChecked(true);

        horizontalLayout_6->addWidget(rdPrinting);

        rdHighlighting = new QRadioButton(tab_2);
        buttonGroup->addButton(rdHighlighting);
        rdHighlighting->setObjectName(QString::fromUtf8("rdHighlighting"));

        horizontalLayout_6->addWidget(rdHighlighting);


        verticalLayout_9->addLayout(horizontalLayout_6);

        grpCondition = new QGroupBox(tab_2);
        grpCondition->setObjectName(QString::fromUtf8("grpCondition"));
        verticalLayout_6 = new QVBoxLayout(grpCondition);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        edtCondition = new QLineEdit(grpCondition);
        edtCondition->setObjectName(QString::fromUtf8("edtCondition"));

        verticalLayout_6->addWidget(edtCondition);


        verticalLayout_9->addWidget(grpCondition);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        grpFont = new QGroupBox(tab_2);
        grpFont->setObjectName(QString::fromUtf8("grpFont"));
        grpFont->setEnabled(false);
        verticalLayout_7 = new QVBoxLayout(grpFont);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        chkBold = new QCheckBox(grpFont);
        chkBold->setObjectName(QString::fromUtf8("chkBold"));

        verticalLayout_7->addWidget(chkBold);

        chkItalic = new QCheckBox(grpFont);
        chkItalic->setObjectName(QString::fromUtf8("chkItalic"));

        verticalLayout_7->addWidget(chkItalic);

        chkUnderline = new QCheckBox(grpFont);
        chkUnderline->setObjectName(QString::fromUtf8("chkUnderline"));

        verticalLayout_7->addWidget(chkUnderline);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblColorF = new QLabel(grpFont);
        lblColorF->setObjectName(QString::fromUtf8("lblColorF"));
        lblColorF->setFrameShape(QFrame::Box);
        lblColorF->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(lblColorF);

        btnColorF = new QPushButton(grpFont);
        btnColorF->setObjectName(QString::fromUtf8("btnColorF"));

        horizontalLayout_4->addWidget(btnColorF);


        verticalLayout_7->addLayout(horizontalLayout_4);


        horizontalLayout_7->addWidget(grpFont);

        grpBackground = new QGroupBox(tab_2);
        grpBackground->setObjectName(QString::fromUtf8("grpBackground"));
        grpBackground->setEnabled(false);
        verticalLayout_8 = new QVBoxLayout(grpBackground);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        rdTransparent = new QRadioButton(grpBackground);
        rdTransparent->setObjectName(QString::fromUtf8("rdTransparent"));
        rdTransparent->setChecked(true);

        verticalLayout_8->addWidget(rdTransparent);

        rdOther = new QRadioButton(grpBackground);
        rdOther->setObjectName(QString::fromUtf8("rdOther"));

        verticalLayout_8->addWidget(rdOther);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lblColorB = new QLabel(grpBackground);
        lblColorB->setObjectName(QString::fromUtf8("lblColorB"));
        lblColorB->setFrameShape(QFrame::Box);
        lblColorB->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(lblColorB);

        btnColorB = new QPushButton(grpBackground);
        btnColorB->setObjectName(QString::fromUtf8("btnColorB"));

        horizontalLayout_5->addWidget(btnColorB);


        verticalLayout_8->addLayout(horizontalLayout_5);


        horizontalLayout_7->addWidget(grpBackground);


        verticalLayout_9->addLayout(horizontalLayout_7);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
#ifndef Q_OS_MAC
        verticalLayout_3->setSpacing(6);
#endif
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(page_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnLoadImage = new QToolButton(widget);
        btnLoadImage->setObjectName(QString::fromUtf8("btnLoadImage"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadImage->setIcon(icon3);
        btnLoadImage->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnLoadImage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget);

        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/picture.png")));

        verticalLayout_4->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(EditFldDlg);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(EditFldDlg);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EditFldDlg);
        QObject::connect(btnOK, SIGNAL(clicked()), EditFldDlg, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), EditFldDlg, SLOT(reject()));
        QObject::connect(chkImage, SIGNAL(clicked(bool)), lblAttention, SLOT(setVisible(bool)));

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditFldDlg);
    } // setupUi

    void retranslateUi(QDialog *EditFldDlg)
    {
        EditFldDlg->setWindowTitle(QApplication::translate("EditFldDlg", "Field editor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnAddVariable->setToolTip(QApplication::translate("EditFldDlg", "Add variable", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAddVariable->setText(QApplication::translate("EditFldDlg", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnAddFunction->setToolTip(QApplication::translate("EditFldDlg", "Add function", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAddFunction->setText(QApplication::translate("EditFldDlg", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnFormatting->setToolTip(QApplication::translate("EditFldDlg", "Add formatting", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnFormatting->setText(QApplication::translate("EditFldDlg", "...", 0, QApplication::UnicodeUTF8));
        chkImage->setText(QApplication::translate("EditFldDlg", "Proccess as Image", 0, QApplication::UnicodeUTF8));
        lblAttention->setText(QApplication::translate("EditFldDlg", "Attention! You may enter just ONE varibale and not any text.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EditFldDlg", "Text", 0, QApplication::UnicodeUTF8));
        rdPrinting->setText(QApplication::translate("EditFldDlg", "Printing", 0, QApplication::UnicodeUTF8));
        rdHighlighting->setText(QApplication::translate("EditFldDlg", "Hightlighting", 0, QApplication::UnicodeUTF8));
        grpCondition->setTitle(QApplication::translate("EditFldDlg", "Condition", 0, QApplication::UnicodeUTF8));
        grpFont->setTitle(QApplication::translate("EditFldDlg", "Font", 0, QApplication::UnicodeUTF8));
        chkBold->setText(QApplication::translate("EditFldDlg", "Bold", 0, QApplication::UnicodeUTF8));
        chkItalic->setText(QApplication::translate("EditFldDlg", "Italic", 0, QApplication::UnicodeUTF8));
        chkUnderline->setText(QApplication::translate("EditFldDlg", "Underline", 0, QApplication::UnicodeUTF8));
        lblColorF->setText(QString());
        btnColorF->setText(QApplication::translate("EditFldDlg", "Color...", 0, QApplication::UnicodeUTF8));
        grpBackground->setTitle(QApplication::translate("EditFldDlg", "Background", 0, QApplication::UnicodeUTF8));
        rdTransparent->setText(QApplication::translate("EditFldDlg", "Transparent", 0, QApplication::UnicodeUTF8));
        rdOther->setText(QApplication::translate("EditFldDlg", "Other", 0, QApplication::UnicodeUTF8));
        lblColorB->setText(QString());
        btnColorB->setText(QApplication::translate("EditFldDlg", "Color...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("EditFldDlg", "Condtion", 0, QApplication::UnicodeUTF8));
        btnLoadImage->setText(QApplication::translate("EditFldDlg", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        btnOK->setText(QApplication::translate("EditFldDlg", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("EditFldDlg", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditFldDlg: public Ui_EditFldDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFLDDLG_H
