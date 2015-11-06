/********************************************************************************
** Form generated from reading UI file 'sapricewin.ui'
**
** Created: Fri Nov 6 10:53:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAPRICEWIN_H
#define UI_SAPRICEWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaPriceWin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *titleLabel;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *headGridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SaPriceWin)
    {
        if (SaPriceWin->objectName().isEmpty())
            SaPriceWin->setObjectName(QString::fromUtf8("SaPriceWin"));
        SaPriceWin->resize(1109, 600);
        centralwidget = new QWidget(SaPriceWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        titleLabel = new QLabel(frame_4);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(titleLabel);


        verticalLayout_2->addWidget(frame_4);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headGridLayout = new QGridLayout();
        headGridLayout->setObjectName(QString::fromUtf8("headGridLayout"));
        headGridLayout->setHorizontalSpacing(10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(label_9, 1, 0, 1, 1);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        headGridLayout->addWidget(lineEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(headGridLayout);


        verticalLayout_2->addWidget(frame_2);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(5);

        verticalLayout_2->addWidget(tableWidget);

        SaPriceWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SaPriceWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SaPriceWin->setStatusBar(statusbar);
        toolBar = new QToolBar(SaPriceWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        SaPriceWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(SaPriceWin);

        QMetaObject::connectSlotsByName(SaPriceWin);
    } // setupUi

    void retranslateUi(QMainWindow *SaPriceWin)
    {
        SaPriceWin->setWindowTitle(QApplication::translate("SaPriceWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("SaPriceWin", "\351\224\200\345\224\256\346\212\245\344\273\267\350\241\250", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SaPriceWin", "\346\217\217    \350\277\260:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SaPriceWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaPriceWin: public Ui_SaPriceWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAPRICEWIN_H
