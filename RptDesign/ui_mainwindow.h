/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jul 10 17:49:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actPageSettings;
    QAction *actSelect_tool;
    QAction *actAlignLeft;
    QAction *actAlignCenter;
    QAction *actAlignRight;
    QAction *actAlignJustify;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actLineTop;
    QAction *actLineBottom;
    QAction *actLineLeft;
    QAction *actLineRight;
    QAction *actLineAll;
    QAction *actLineNo;
    QAction *actionInsert_band;
    QAction *actAddField;
    QAction *actionNewReport;
    QAction *actionOpenReport;
    QAction *actSaveReport;
    QAction *actAlignTop;
    QAction *actAlignVCenter;
    QAction *actAlignBottom;
    QAction *actCopy;
    QAction *actCut;
    QAction *actPaste;
    QAction *actSaveAs;
    QAction *actFontColor;
    QAction *actBackgroundColor;
    QAction *actBorderColor;
    QAction *actAbout;
    QAction *actShowGrid;
    QAction *actAddPicture;
    QAction *actFrameStyle;
    QAction *actLanguage;
    QAction *actNewReportPage;
    QAction *actDeleteReportPage;
    QAction *actFieldLeft;
    QAction *actFieldMiddle;
    QAction *actFieldRight;
    QAction *actFieldTop;
    QAction *actFieldCenter;
    QAction *actFieldBottom;
    QAction *actFieldSameWidth;
    QAction *actFieldSameHeight;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QTreeWidget *treeWidget;
    QTreeWidget *treeParams;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuReport;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1664, 683);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actPageSettings = new QAction(MainWindow);
        actPageSettings->setObjectName(QString::fromUtf8("actPageSettings"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/pageSetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPageSettings->setIcon(icon);
        actSelect_tool = new QAction(MainWindow);
        actSelect_tool->setObjectName(QString::fromUtf8("actSelect_tool"));
        actSelect_tool->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/80-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSelect_tool->setIcon(icon1);
        actAlignLeft = new QAction(MainWindow);
        actAlignLeft->setObjectName(QString::fromUtf8("actAlignLeft"));
        actAlignLeft->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/textleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignLeft->setIcon(icon2);
        actAlignCenter = new QAction(MainWindow);
        actAlignCenter->setObjectName(QString::fromUtf8("actAlignCenter"));
        actAlignCenter->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/textcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignCenter->setIcon(icon3);
        actAlignRight = new QAction(MainWindow);
        actAlignRight->setObjectName(QString::fromUtf8("actAlignRight"));
        actAlignRight->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/textright.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignRight->setIcon(icon4);
        actAlignJustify = new QAction(MainWindow);
        actAlignJustify->setObjectName(QString::fromUtf8("actAlignJustify"));
        actAlignJustify->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/textjustify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignJustify->setIcon(icon5);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionBold->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon6);
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionItalic->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon7);
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName(QString::fromUtf8("actionUnderline"));
        actionUnderline->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/images/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon8);
        actLineTop = new QAction(MainWindow);
        actLineTop->setObjectName(QString::fromUtf8("actLineTop"));
        actLineTop->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/images/82-6.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLineTop->setIcon(icon9);
        actLineBottom = new QAction(MainWindow);
        actLineBottom->setObjectName(QString::fromUtf8("actLineBottom"));
        actLineBottom->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/images/82-7.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLineBottom->setIcon(icon10);
        actLineLeft = new QAction(MainWindow);
        actLineLeft->setObjectName(QString::fromUtf8("actLineLeft"));
        actLineLeft->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/images/82-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLineLeft->setIcon(icon11);
        actLineRight = new QAction(MainWindow);
        actLineRight->setObjectName(QString::fromUtf8("actLineRight"));
        actLineRight->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/images/82-5.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLineRight->setIcon(icon12);
        actLineAll = new QAction(MainWindow);
        actLineAll->setObjectName(QString::fromUtf8("actLineAll"));
        actLineAll->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/images/82-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLineAll->setIcon(icon13);
        actLineNo = new QAction(MainWindow);
        actLineNo->setObjectName(QString::fromUtf8("actLineNo"));
        actLineNo->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/images/82-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLineNo->setIcon(icon14);
        actionInsert_band = new QAction(MainWindow);
        actionInsert_band->setObjectName(QString::fromUtf8("actionInsert_band"));
        actionInsert_band->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/images/band.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert_band->setIcon(icon15);
        actAddField = new QAction(MainWindow);
        actAddField->setObjectName(QString::fromUtf8("actAddField"));
        actAddField->setCheckable(true);
        actAddField->setEnabled(false);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/images/field.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAddField->setIcon(icon16);
        actionNewReport = new QAction(MainWindow);
        actionNewReport->setObjectName(QString::fromUtf8("actionNewReport"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewReport->setIcon(icon17);
        actionNewReport->setVisible(false);
        actionOpenReport = new QAction(MainWindow);
        actionOpenReport->setObjectName(QString::fromUtf8("actionOpenReport"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenReport->setIcon(icon18);
        actionOpenReport->setVisible(false);
        actSaveReport = new QAction(MainWindow);
        actSaveReport->setObjectName(QString::fromUtf8("actSaveReport"));
        actSaveReport->setEnabled(false);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix1/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSaveReport->setIcon(icon19);
        actAlignTop = new QAction(MainWindow);
        actAlignTop->setObjectName(QString::fromUtf8("actAlignTop"));
        actAlignTop->setCheckable(true);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/prefix1/images/texttop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignTop->setIcon(icon20);
        actAlignVCenter = new QAction(MainWindow);
        actAlignVCenter->setObjectName(QString::fromUtf8("actAlignVCenter"));
        actAlignVCenter->setCheckable(true);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/prefix1/images/textVcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignVCenter->setIcon(icon21);
        actAlignBottom = new QAction(MainWindow);
        actAlignBottom->setObjectName(QString::fromUtf8("actAlignBottom"));
        actAlignBottom->setCheckable(true);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/new/prefix1/images/textbottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignBottom->setIcon(icon22);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QString::fromUtf8("actCopy"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/new/prefix1/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon23);
        actCut = new QAction(MainWindow);
        actCut->setObjectName(QString::fromUtf8("actCut"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/new/prefix1/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon24);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName(QString::fromUtf8("actPaste"));
        actPaste->setEnabled(false);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/new/prefix1/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon25);
        actSaveAs = new QAction(MainWindow);
        actSaveAs->setObjectName(QString::fromUtf8("actSaveAs"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/new/prefix1/images/saveAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSaveAs->setIcon(icon26);
        actFontColor = new QAction(MainWindow);
        actFontColor->setObjectName(QString::fromUtf8("actFontColor"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/new/prefix1/images/fontColor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFontColor->setIcon(icon27);
        actBackgroundColor = new QAction(MainWindow);
        actBackgroundColor->setObjectName(QString::fromUtf8("actBackgroundColor"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/new/prefix1/images/backgroundColor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actBackgroundColor->setIcon(icon28);
        actBorderColor = new QAction(MainWindow);
        actBorderColor->setObjectName(QString::fromUtf8("actBorderColor"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/new/prefix1/images/borderColor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actBorderColor->setIcon(icon29);
        actAbout = new QAction(MainWindow);
        actAbout->setObjectName(QString::fromUtf8("actAbout"));
        actShowGrid = new QAction(MainWindow);
        actShowGrid->setObjectName(QString::fromUtf8("actShowGrid"));
        actShowGrid->setCheckable(true);
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/new/prefix1/images/grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        actShowGrid->setIcon(icon30);
        actAddPicture = new QAction(MainWindow);
        actAddPicture->setObjectName(QString::fromUtf8("actAddPicture"));
        actAddPicture->setCheckable(true);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/new/prefix1/images/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAddPicture->setIcon(icon31);
        actFrameStyle = new QAction(MainWindow);
        actFrameStyle->setObjectName(QString::fromUtf8("actFrameStyle"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/new/prefix1/images/frameStyle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFrameStyle->setIcon(icon32);
        actLanguage = new QAction(MainWindow);
        actLanguage->setObjectName(QString::fromUtf8("actLanguage"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/new/prefix1/images/applications-education-language.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLanguage->setIcon(icon33);
        actNewReportPage = new QAction(MainWindow);
        actNewReportPage->setObjectName(QString::fromUtf8("actNewReportPage"));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/new/prefix1/images/newPageReport.png"), QSize(), QIcon::Normal, QIcon::Off);
        actNewReportPage->setIcon(icon34);
        actDeleteReportPage = new QAction(MainWindow);
        actDeleteReportPage->setObjectName(QString::fromUtf8("actDeleteReportPage"));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/new/prefix1/images/deletePage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDeleteReportPage->setIcon(icon35);
        actFieldLeft = new QAction(MainWindow);
        actFieldLeft->setObjectName(QString::fromUtf8("actFieldLeft"));
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/new/prefix1/images/fieldLeft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldLeft->setIcon(icon36);
        actFieldMiddle = new QAction(MainWindow);
        actFieldMiddle->setObjectName(QString::fromUtf8("actFieldMiddle"));
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/new/prefix1/images/fieldMiddle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldMiddle->setIcon(icon37);
        actFieldRight = new QAction(MainWindow);
        actFieldRight->setObjectName(QString::fromUtf8("actFieldRight"));
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/new/prefix1/images/fieldRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldRight->setIcon(icon38);
        actFieldTop = new QAction(MainWindow);
        actFieldTop->setObjectName(QString::fromUtf8("actFieldTop"));
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/new/prefix1/images/fieldTop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldTop->setIcon(icon39);
        actFieldCenter = new QAction(MainWindow);
        actFieldCenter->setObjectName(QString::fromUtf8("actFieldCenter"));
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/new/prefix1/images/fieldCenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldCenter->setIcon(icon40);
        actFieldBottom = new QAction(MainWindow);
        actFieldBottom->setObjectName(QString::fromUtf8("actFieldBottom"));
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/new/prefix1/images/fieldBottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldBottom->setIcon(icon41);
        actFieldSameWidth = new QAction(MainWindow);
        actFieldSameWidth->setObjectName(QString::fromUtf8("actFieldSameWidth"));
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/new/prefix1/images/fieldSameWidth.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldSameWidth->setIcon(icon42);
        actFieldSameHeight = new QAction(MainWindow);
        actFieldSameHeight->setObjectName(QString::fromUtf8("actFieldSameHeight"));
        QIcon icon43;
        icon43.addFile(QString::fromUtf8(":/new/prefix1/images/fieldSameHeight.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFieldSameHeight->setIcon(icon43);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setBaseSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_2 = new QSplitter(widget_2);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy1);
        splitter_2->setBaseSize(QSize(0, 0));
        splitter_2->setOrientation(Qt::Vertical);
        treeWidget = new QTreeWidget(splitter_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);
        treeWidget->setBaseSize(QSize(0, 0));
        splitter_2->addWidget(treeWidget);
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setDefaultSectionSize(50);
        treeParams = new QTreeWidget(splitter_2);
        treeParams->setObjectName(QString::fromUtf8("treeParams"));
        sizePolicy2.setHeightForWidth(treeParams->sizePolicy().hasHeightForWidth());
        treeParams->setSizePolicy(sizePolicy2);
        treeParams->setBaseSize(QSize(0, 0));
        treeParams->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        treeParams->setAlternatingRowColors(true);
        treeParams->setSelectionMode(QAbstractItemView::SingleSelection);
        treeParams->setIndentation(15);
        treeParams->setExpandsOnDoubleClick(false);
        splitter_2->addWidget(treeParams);
        treeParams->header()->setDefaultSectionSize(70);

        verticalLayout->addWidget(splitter_2);

        splitter->addWidget(widget_2);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        splitter->addWidget(tabWidget);

        verticalLayout_2->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1664, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuReport = new QMenu(menuBar);
        menuReport->setObjectName(QString::fromUtf8("menuReport"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        MainWindow->insertToolBarBreak(toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::RightToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_3);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuReport->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewReport);
        menuFile->addAction(actionOpenReport);
        menuFile->addAction(actSaveReport);
        menuFile->addAction(actSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actNewReportPage);
        menuFile->addAction(actDeleteReportPage);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuReport->addAction(actPageSettings);
        menuEdit->addAction(actCut);
        menuEdit->addAction(actCopy);
        menuEdit->addAction(actPaste);
        menuHelp->addAction(actLanguage);
        menuHelp->addAction(actAbout);
        mainToolBar->addAction(actionNewReport);
        mainToolBar->addAction(actionOpenReport);
        mainToolBar->addAction(actSaveReport);
        mainToolBar->addAction(actSaveAs);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actCut);
        mainToolBar->addAction(actCopy);
        mainToolBar->addAction(actPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actNewReportPage);
        mainToolBar->addAction(actDeleteReportPage);
        mainToolBar->addAction(actPageSettings);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actShowGrid);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actFieldLeft);
        mainToolBar->addAction(actFieldMiddle);
        mainToolBar->addAction(actFieldRight);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actFieldTop);
        mainToolBar->addAction(actFieldCenter);
        mainToolBar->addAction(actFieldBottom);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actFieldSameWidth);
        mainToolBar->addAction(actFieldSameHeight);
        mainToolBar->addSeparator();
        toolBar->addAction(actionBold);
        toolBar->addAction(actionItalic);
        toolBar->addAction(actionUnderline);
        toolBar->addSeparator();
        toolBar->addAction(actFontColor);
        toolBar->addSeparator();
        toolBar->addAction(actAlignLeft);
        toolBar->addAction(actAlignCenter);
        toolBar->addAction(actAlignRight);
        toolBar->addAction(actAlignJustify);
        toolBar->addSeparator();
        toolBar->addAction(actAlignTop);
        toolBar->addAction(actAlignVCenter);
        toolBar->addAction(actAlignBottom);
        toolBar->addSeparator();
        toolBar->addAction(actLineTop);
        toolBar->addAction(actLineBottom);
        toolBar->addAction(actLineLeft);
        toolBar->addAction(actLineRight);
        toolBar->addAction(actLineAll);
        toolBar->addAction(actLineNo);
        toolBar->addSeparator();
        toolBar->addAction(actBackgroundColor);
        toolBar->addAction(actBorderColor);
        toolBar->addAction(actFrameStyle);
        toolBar_3->addAction(actSelect_tool);
        toolBar_3->addAction(actionInsert_band);
        toolBar_3->addAction(actAddField);
        toolBar_3->addAction(actAddPicture);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RPT Design", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actPageSettings->setText(QApplication::translate("MainWindow", "Page settings", 0, QApplication::UnicodeUTF8));
        actSelect_tool->setText(QApplication::translate("MainWindow", "Select tool", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actSelect_tool->setToolTip(QApplication::translate("MainWindow", "Select tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAlignLeft->setText(QApplication::translate("MainWindow", "Align left", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignLeft->setToolTip(QApplication::translate("MainWindow", "Align left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAlignCenter->setText(QApplication::translate("MainWindow", "Align center", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignCenter->setToolTip(QApplication::translate("MainWindow", "Align center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAlignRight->setText(QApplication::translate("MainWindow", "Align right", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignRight->setToolTip(QApplication::translate("MainWindow", "Align right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAlignJustify->setText(QApplication::translate("MainWindow", "Justify", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignJustify->setToolTip(QApplication::translate("MainWindow", "Justify", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBold->setText(QApplication::translate("MainWindow", "Bold", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBold->setToolTip(QApplication::translate("MainWindow", "Bold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionItalic->setText(QApplication::translate("MainWindow", "Italic", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionItalic->setToolTip(QApplication::translate("MainWindow", "Italic", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionUnderline->setText(QApplication::translate("MainWindow", "Underline", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionUnderline->setToolTip(QApplication::translate("MainWindow", "Underline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLineTop->setText(QApplication::translate("MainWindow", "Top line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLineTop->setToolTip(QApplication::translate("MainWindow", "Top line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLineBottom->setText(QApplication::translate("MainWindow", "Bottom line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLineBottom->setToolTip(QApplication::translate("MainWindow", "Bottom line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLineLeft->setText(QApplication::translate("MainWindow", "Left line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLineLeft->setToolTip(QApplication::translate("MainWindow", "Left line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLineRight->setText(QApplication::translate("MainWindow", "Right line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLineRight->setToolTip(QApplication::translate("MainWindow", "Right line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLineAll->setText(QApplication::translate("MainWindow", "All frame line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLineAll->setToolTip(QApplication::translate("MainWindow", "All frame line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLineNo->setText(QApplication::translate("MainWindow", "No frame", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLineNo->setToolTip(QApplication::translate("MainWindow", "No frame", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionInsert_band->setText(QApplication::translate("MainWindow", "Insert band", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionInsert_band->setToolTip(QApplication::translate("MainWindow", "Insert band", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAddField->setText(QApplication::translate("MainWindow", "Add Filed", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAddField->setToolTip(QApplication::translate("MainWindow", "Add filed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewReport->setText(QApplication::translate("MainWindow", "New report", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewReport->setToolTip(QApplication::translate("MainWindow", "New report", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpenReport->setText(QApplication::translate("MainWindow", "Open report", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpenReport->setToolTip(QApplication::translate("MainWindow", "Open report", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpenReport->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actSaveReport->setText(QApplication::translate("MainWindow", "Save report", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actSaveReport->setToolTip(QApplication::translate("MainWindow", "Save report", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actSaveReport->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actAlignTop->setText(QApplication::translate("MainWindow", "Align top", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignTop->setToolTip(QApplication::translate("MainWindow", "Align top", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAlignVCenter->setText(QApplication::translate("MainWindow", "Align V center", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignVCenter->setToolTip(QApplication::translate("MainWindow", "Align V center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAlignBottom->setText(QApplication::translate("MainWindow", "Align bottom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actAlignBottom->setToolTip(QApplication::translate("MainWindow", "Align bottom", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actCopy->setToolTip(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actCut->setToolTip(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actPaste->setToolTip(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actSaveAs->setText(QApplication::translate("MainWindow", "Save as", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actSaveAs->setToolTip(QApplication::translate("MainWindow", "Save as", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFontColor->setText(QApplication::translate("MainWindow", "Font color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFontColor->setToolTip(QApplication::translate("MainWindow", "Font color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actBackgroundColor->setText(QApplication::translate("MainWindow", "Background color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actBackgroundColor->setToolTip(QApplication::translate("MainWindow", "Background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actBorderColor->setText(QApplication::translate("MainWindow", "Border color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actBorderColor->setToolTip(QApplication::translate("MainWindow", "Border color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAbout->setText(QApplication::translate("MainWindow", "About RptDesign", 0, QApplication::UnicodeUTF8));
        actShowGrid->setText(QApplication::translate("MainWindow", "Show Grid", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actShowGrid->setToolTip(QApplication::translate("MainWindow", "Show/Hide grid", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actAddPicture->setText(QApplication::translate("MainWindow", "Add picture", 0, QApplication::UnicodeUTF8));
        actFrameStyle->setText(QApplication::translate("MainWindow", "Frame style", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFrameStyle->setToolTip(QApplication::translate("MainWindow", "Frame style", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actLanguage->setText(QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actLanguage->setToolTip(QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actNewReportPage->setText(QApplication::translate("MainWindow", "New Report Page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actNewReportPage->setToolTip(QApplication::translate("MainWindow", "New Report Page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actDeleteReportPage->setText(QApplication::translate("MainWindow", "Delete Report Page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actDeleteReportPage->setToolTip(QApplication::translate("MainWindow", "Delete Report Page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldLeft->setText(QApplication::translate("MainWindow", "Align Field Left", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldLeft->setToolTip(QApplication::translate("MainWindow", "Align Field Left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldMiddle->setText(QApplication::translate("MainWindow", "Align Field Middle", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldMiddle->setToolTip(QApplication::translate("MainWindow", "Align Field Middle", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldRight->setText(QApplication::translate("MainWindow", "Align Field Right", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldRight->setToolTip(QApplication::translate("MainWindow", "Align Field Right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldTop->setText(QApplication::translate("MainWindow", "Align Field Top", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldTop->setToolTip(QApplication::translate("MainWindow", "Align Field Top", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldCenter->setText(QApplication::translate("MainWindow", "Align Field Center", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldCenter->setToolTip(QApplication::translate("MainWindow", "Align Field Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldBottom->setText(QApplication::translate("MainWindow", "Align Field Bottom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldBottom->setToolTip(QApplication::translate("MainWindow", "Align Field Bottom", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldSameWidth->setText(QApplication::translate("MainWindow", "Field Same Width", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldSameWidth->setToolTip(QApplication::translate("MainWindow", "Field Same Width", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actFieldSameHeight->setText(QApplication::translate("MainWindow", "Field Same Height", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actFieldSameHeight->setToolTip(QApplication::translate("MainWindow", "Field Same Height", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem = treeParams->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuReport->setTitle(QApplication::translate("MainWindow", "Report", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
