/********************************************************************************
** Form generated from reading UI file 'puorderlistform.ui'
**
** Created: Wed Jul 16 11:03:28 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUORDERLISTFORM_H
#define UI_PUORDERLISTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_PuOrderListForm
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QkSearchEditBox *dwNameQks;
    QLabel *dwTypeLabel;
    QLabel *Label;
    QLabel *startLabel;
    QkSearchEditBox *proTypeQks;
    QLabel *proNameLabel;
    QLabel *proTypeLabel;
    QLabel *endLabel;
    QkSearchEditBox *proNameQks;
    QDateEdit *eDateEdit;
    QkSearchEditBox *dwTypeQks;
    QLabel *dwNameLabel;
    QDateEdit *sDateEdit1;
    QLabel *idLabel;
    QLineEdit *noEdit;
    QRadioButton *rBnt2;
    QRadioButton *rBnt1;
    QRadioButton *rBnt3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QToolButton *queryButton;
    QToolButton *cancelButton;
    QToolButton *printButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *exportButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_2;

    void setupUi(QWidget *PuOrderListForm)
    {
        if (PuOrderListForm->objectName().isEmpty())
            PuOrderListForm->setObjectName(QString::fromUtf8("PuOrderListForm"));
        PuOrderListForm->resize(1276, 670);
        verticalLayout = new QVBoxLayout(PuOrderListForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(PuOrderListForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(7, -1, -1, -1);
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(12);
        gridLayout->setVerticalSpacing(6);
        dwNameQks = new QkSearchEditBox(frame);
        dwNameQks->setObjectName(QString::fromUtf8("dwNameQks"));

        gridLayout->addWidget(dwNameQks, 2, 5, 1, 3);

        dwTypeLabel = new QLabel(frame);
        dwTypeLabel->setObjectName(QString::fromUtf8("dwTypeLabel"));

        gridLayout->addWidget(dwTypeLabel, 2, 0, 1, 1);

        Label = new QLabel(frame);
        Label->setObjectName(QString::fromUtf8("Label"));

        gridLayout->addWidget(Label, 1, 8, 1, 1);

        startLabel = new QLabel(frame);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));

        gridLayout->addWidget(startLabel, 1, 0, 1, 1);

        proTypeQks = new QkSearchEditBox(frame);
        proTypeQks->setObjectName(QString::fromUtf8("proTypeQks"));

        gridLayout->addWidget(proTypeQks, 3, 1, 1, 3);

        proNameLabel = new QLabel(frame);
        proNameLabel->setObjectName(QString::fromUtf8("proNameLabel"));

        gridLayout->addWidget(proNameLabel, 3, 4, 1, 1);

        proTypeLabel = new QLabel(frame);
        proTypeLabel->setObjectName(QString::fromUtf8("proTypeLabel"));

        gridLayout->addWidget(proTypeLabel, 3, 0, 1, 1);

        endLabel = new QLabel(frame);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        endLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(endLabel, 1, 4, 1, 1);

        proNameQks = new QkSearchEditBox(frame);
        proNameQks->setObjectName(QString::fromUtf8("proNameQks"));

        gridLayout->addWidget(proNameQks, 3, 5, 1, 3);

        eDateEdit = new QDateEdit(frame);
        eDateEdit->setObjectName(QString::fromUtf8("eDateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eDateEdit->sizePolicy().hasHeightForWidth());
        eDateEdit->setSizePolicy(sizePolicy);
        eDateEdit->setCalendarPopup(true);

        gridLayout->addWidget(eDateEdit, 1, 5, 1, 1);

        dwTypeQks = new QkSearchEditBox(frame);
        dwTypeQks->setObjectName(QString::fromUtf8("dwTypeQks"));

        gridLayout->addWidget(dwTypeQks, 2, 1, 1, 3);

        dwNameLabel = new QLabel(frame);
        dwNameLabel->setObjectName(QString::fromUtf8("dwNameLabel"));

        gridLayout->addWidget(dwNameLabel, 2, 4, 1, 1);

        sDateEdit1 = new QDateEdit(frame);
        sDateEdit1->setObjectName(QString::fromUtf8("sDateEdit1"));
        sizePolicy.setHeightForWidth(sDateEdit1->sizePolicy().hasHeightForWidth());
        sDateEdit1->setSizePolicy(sizePolicy);
        sDateEdit1->setCalendarPopup(true);

        gridLayout->addWidget(sDateEdit1, 1, 1, 1, 1);

        idLabel = new QLabel(frame);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        gridLayout->addWidget(idLabel, 1, 6, 1, 1);

        noEdit = new QLineEdit(frame);
        noEdit->setObjectName(QString::fromUtf8("noEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noEdit->sizePolicy().hasHeightForWidth());
        noEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(noEdit, 1, 7, 1, 1);

        rBnt2 = new QRadioButton(frame);
        rBnt2->setObjectName(QString::fromUtf8("rBnt2"));

        gridLayout->addWidget(rBnt2, 1, 10, 1, 1);

        rBnt1 = new QRadioButton(frame);
        rBnt1->setObjectName(QString::fromUtf8("rBnt1"));
        rBnt1->setChecked(true);

        gridLayout->addWidget(rBnt1, 1, 9, 1, 1);

        rBnt3 = new QRadioButton(frame);
        rBnt3->setObjectName(QString::fromUtf8("rBnt3"));

        gridLayout->addWidget(rBnt3, 1, 11, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer, 1, 5, 1, 1);

        queryButton = new QToolButton(frame);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/search_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        queryButton->setIcon(icon);
        queryButton->setIconSize(QSize(32, 32));
        queryButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(queryButton, 0, 1, 1, 1);

        cancelButton = new QToolButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/cancel_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon1);
        cancelButton->setIconSize(QSize(32, 32));
        cancelButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(cancelButton, 0, 5, 1, 1);

        printButton = new QToolButton(frame);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        printButton->setIcon(icon2);
        printButton->setIconSize(QSize(32, 32));
        printButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(printButton, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        exportButton = new QToolButton(frame);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("export48.png")));
        exportButton->setIcon(icon3);
        exportButton->setIconSize(QSize(32, 32));
        exportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(exportButton, 0, 4, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout->addWidget(frame);

        tabWidget = new QTabWidget(PuOrderListForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout_3->addWidget(tableView_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(PuOrderListForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PuOrderListForm);
    } // setupUi

    void retranslateUi(QWidget *PuOrderListForm)
    {
        PuOrderListForm->setWindowTitle(QApplication::translate("PuOrderListForm", "Form", 0, QApplication::UnicodeUTF8));
        dwTypeLabel->setText(QApplication::translate("PuOrderListForm", "\345\215\225\344\275\215\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        Label->setText(QApplication::translate("PuOrderListForm", "\346\230\257\345\220\246\345\256\241\346\240\270:", 0, QApplication::UnicodeUTF8));
        startLabel->setText(QApplication::translate("PuOrderListForm", "\345\274\200\345\247\213\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        proNameLabel->setText(QApplication::translate("PuOrderListForm", "\345\225\206\345\223\201\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        proTypeLabel->setText(QApplication::translate("PuOrderListForm", "\345\225\206\345\223\201\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        endLabel->setText(QApplication::translate("PuOrderListForm", "\347\273\223\346\235\237\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        dwNameLabel->setText(QApplication::translate("PuOrderListForm", "\345\215\225\344\275\215\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("PuOrderListForm", "\345\215\225\346\215\256\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        rBnt2->setText(QApplication::translate("PuOrderListForm", "\346\234\252\345\256\241", 0, QApplication::UnicodeUTF8));
        rBnt1->setText(QApplication::translate("PuOrderListForm", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        rBnt3->setText(QApplication::translate("PuOrderListForm", "\345\267\262\345\256\241", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("PuOrderListForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("PuOrderListForm", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("PuOrderListForm", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        exportButton->setText(QApplication::translate("PuOrderListForm", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PuOrderListForm", "\351\207\207\350\264\255\350\256\242\345\215\225\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PuOrderListForm", "\351\207\207\350\264\255\350\256\242\345\215\225\346\230\216\347\273\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PuOrderListForm: public Ui_PuOrderListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUORDERLISTFORM_H
