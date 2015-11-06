/*
Name: RptDesign
Version: 1.3.0
Programmer: jk liu
e-mail: vesaliu@163.com
2012-2013
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "haokeapp.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow) {
    widgetInFocus = 0;
    ui->setupUi(this);
    this->showMaximized();

    cloneCont = 0;
    ui->treeParams->setColumnWidth(0,70);
    ui->treeParams->setColumnWidth(1,70);
    ui->treeParams->setFocusPolicy(Qt::NoFocus);
    ui->treeWidget->setFocusPolicy(Qt::NoFocus);

    EditorDelegate *d = new EditorDelegate(this);
    QObject::connect(d, SIGNAL(editorClose(QItemDelegate *)), this,  SLOT(closeEditor()));
    ui->treeParams->setItemDelegate(d);

    cbFontName = new QFontComboBox(ui->toolBar);
    cbFontName->setEditable(true);
    cbFontName->setToolTip("Font name");
    cbFontSize = new QComboBox( ui->toolBar );
    cbFontSize->setEditable(true);
    cbFontSize->setToolTip("Font size");
    cbFontSize->addItem("6");
    cbFontSize->addItem("7");
    cbFontSize->addItem("8");
    cbFontSize->addItem("9");
    cbFontSize->addItem("10");
    cbFontSize->addItem("11");
    cbFontSize->addItem("12");
    cbFontSize->addItem("14");
    cbFontSize->addItem("16");
    cbFontSize->addItem("18");
    cbFontSize->addItem("20");
    cbFontSize->addItem("22");
    cbFontSize->addItem("24");
    cbFontSize->addItem("26");
    cbFontSize->addItem("28");
    cbFontSize->addItem("36");
    cbFontSize->addItem("48");
    cbFontSize->addItem("72");
    ui->toolBar->insertWidget(ui->actionBold,cbFontName);
    ui->toolBar->insertWidget(ui->actionBold,cbFontSize);

    cbFrameWidth = new QComboBox( ui->toolBar );
    cbFrameWidth->setToolTip(tr("Frame width"));
    cbFrameWidth->addItem("1");
    cbFrameWidth->addItem("1.5");
    cbFrameWidth->addItem("2");
    cbFrameWidth->addItem("3");
    cbFrameWidth->addItem("4");
    cbFrameWidth->addItem("5");
    ui->toolBar->addWidget(cbFrameWidth);
    QObject::connect(cbFrameWidth, SIGNAL(activated(int)), this, SLOT(changeFrameWidth()));
    QObject::connect(cbFontName, SIGNAL(activated(int)), this, SLOT(changeTextFont()));
    QObject::connect(cbFontSize, SIGNAL(activated(int)), this, SLOT(changeTextFont()));

    listFrameStyle = new QListWidget(this);
    listFrameStyle->setFixedHeight(116);
    listFrameStyle->setIconSize(QSize(85, 16));
    QObject::connect(listFrameStyle, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(setFrameStyle(QListWidgetItem *)));

    for (int i=1; i < 7; i++) {
        QListWidgetItem *item = new QListWidgetItem(listFrameStyle);
        QIcon icn;
        icn.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/fs%1.png").arg(i)), QIcon::Normal, QIcon::On);
        item->setIcon(icn);
        item->setData(Qt::UserRole,i);
        listFrameStyle->addItem(item);
    }

    this->setMouseTracking(true);
    newContMoving = false;

    rootItem = new QTreeWidgetItem(ui->treeWidget,0);
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/report.png")), QIcon::Normal, QIcon::On);
    rootItem->setIcon(0,icon);
    rootItem->setText(0,tr("Report"));
    rootItem->setExpanded(true);

    QList<int> lst;
    lst << 15 << 300;
    ui->splitter->setSizes(lst);

    QList<QWidget*> widgets = ui->toolBar->findChildren<QWidget*>();
    foreach (QWidget* widget, widgets)
        widget->installEventFilter(this);

    QActionGroup *alignmentHGroup = new QActionGroup(this);
    alignmentHGroup->addAction(ui->actAlignLeft);
    alignmentHGroup->addAction(ui->actAlignRight);
    alignmentHGroup->addAction(ui->actAlignJustify);
    alignmentHGroup->addAction(ui->actAlignCenter);

    QActionGroup *alignmentVGroup = new QActionGroup(this);
    alignmentVGroup->addAction(ui->actAlignTop);
    alignmentVGroup->addAction(ui->actAlignBottom);
    alignmentVGroup->addAction(ui->actAlignVCenter);

    QActionGroup *addGroup = new QActionGroup(this);
    addGroup->addAction(ui->actionInsert_band);
    addGroup->addAction(ui->actSelect_tool);
    addGroup->addAction(ui->actAddField);
    addGroup->addAction(ui->actAddPicture);

    ui->actSelect_tool->setChecked(true);

    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        ui->menuFile->insertAction(ui->actionExit,recentFileActs[i]);
        connect(recentFileActs[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }

    separatorAct = ui->menuFile->addSeparator();

    updateRecentFileActions();
    ui->menuFile->insertAction(ui->actionExit,separatorAct);

    QObject::connect(ui->actAddField, SIGNAL(triggered()), this, SLOT(addField()));
    QObject::connect(ui->actAddPicture, SIGNAL(triggered()), this, SLOT(AddPicture()));
    //QObject::connect(ui->actionOpenReport, SIGNAL(triggered()), this, SLOT(openFile()));
    QObject::connect(ui->actionNewReport, SIGNAL(triggered()), this, SLOT(newReport()));
    QObject::connect(ui->actSaveReport, SIGNAL(triggered()), this, SLOT(saveReport()));
    QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(closeProgram()));
    QObject::connect(ui->actSaveAs, SIGNAL(triggered()), this, SLOT(saveReport()));
    QObject::connect(ui->actAlignCenter, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actAlignLeft, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actAlignRight, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actAlignJustify, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actAlignTop, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actAlignVCenter, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actAlignBottom, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actionBold, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actionItalic, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actionUnderline, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actLineAll, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actLineBottom, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actLineLeft, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actLineNo, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actLineRight, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actLineTop, SIGNAL(triggered()), this, SLOT(changeTextFont()));
    QObject::connect(ui->actCut, SIGNAL(triggered()), this, SLOT(clipBoard()));
    QObject::connect(ui->actCopy, SIGNAL(triggered()), this, SLOT(clipBoard()));
    QObject::connect(ui->actPaste, SIGNAL(triggered()), this, SLOT(clipBoard()));
    QObject::connect(ui->actBackgroundColor, SIGNAL(triggered()), this, SLOT(chooseColor()));
    QObject::connect(ui->actBorderColor, SIGNAL(triggered()), this, SLOT(chooseColor()));
    QObject::connect(ui->actFontColor, SIGNAL(triggered()), this, SLOT(chooseColor()));    
    QObject::connect(ui->actLanguage, SIGNAL(triggered()), this, SLOT(showLanguage()));
    QObject::connect(ui->actAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    //QObject::connect(ui->actNewReportPage, SIGNAL(triggered()), this, SLOT(newReportPage()));
    QObject::connect(ui->actDeleteReportPage, SIGNAL(triggered()), this, SLOT(deleteReportPage()));
    //QObject::connect(ui->actFrameStyle, SIGNAL(triggered()), this, SLOT(showFrameStyle()));
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(selTree(QTreeWidgetItem *, int)));
    QObject::connect(ui->treeParams, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(itemChanged(QTreeWidgetItem *, int)));
    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(reportPageChanged(int)));
    QObject::connect(ui->actFieldBottom, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldCenter, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldLeft, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldMiddle, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldRight, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldTop, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldSameHeight, SIGNAL(triggered()), this, SLOT(alignFields()));
    QObject::connect(ui->actFieldSameWidth, SIGNAL(triggered()), this, SLOT(alignFields()));

    actRepTitle = new QAction(tr("Report Title"),this);
    actRepTitle->setObjectName("actRepTitle");
    QObject::connect(actRepTitle, SIGNAL(triggered()), this, SLOT(addBand()));
    //icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/882-2.png")), QIcon::Normal, QIcon::On);
    //createFldAgentAction->setIcon(icon);

    actReportSummary = new QAction(tr("Report Summary"),this);
    actReportSummary->setObjectName("actReportSummary");
    QObject::connect(actReportSummary, SIGNAL(triggered()), this, SLOT(addBand()));

    actPageHeader = new QAction(tr("Page Header"),this);
    actPageHeader->setObjectName("actPageHeader");
    QObject::connect(actPageHeader, SIGNAL(triggered()), this, SLOT(addBand()));

    actPageFooter = new QAction(tr("Page Footer"),this);
    actPageFooter->setObjectName("actPageFooter");
    QObject::connect(actPageFooter, SIGNAL(triggered()), this, SLOT(addBand()));

    actMasterData = new QAction(tr("Master Data"),this);
    actMasterData->setObjectName("actMasterData");
    QObject::connect(actMasterData, SIGNAL(triggered()), this, SLOT(addBand()));

    actMasterFooter = new QAction(tr("Master Footer"),this);
    actMasterFooter->setObjectName("actMasterFooter");
    QObject::connect(actMasterFooter, SIGNAL(triggered()), this, SLOT(addBand()));

    actMasterHeader = new QAction(tr("Master Header"),this);
    actMasterHeader->setObjectName("actMasterHeader");
    QObject::connect(actMasterHeader, SIGNAL(triggered()), this, SLOT(addBand()));

    QMenu *subBand = new QMenu(this);
    subBand->setObjectName("subBand");
    subBand->addAction(actRepTitle);
    subBand->addAction(actPageHeader);
    subBand->addAction(actMasterHeader);
    subBand->addAction(actMasterData);
    subBand->addAction(actMasterFooter);
    subBand->addAction(actPageFooter);
    subBand->addAction(actReportSummary);

    ui->actionInsert_band->setMenu(subBand);
    QToolButton * btn = qobject_cast<QToolButton *>(ui->toolBar_3->widgetForAction(ui->actionInsert_band));
    btn->setPopupMode(QToolButton::InstantPopup);

    QObject::connect(subBand, SIGNAL(aboutToShow()), this, SLOT(clickOnTBtn()));
    QObject::connect(ui->actPageSettings, SIGNAL(triggered()), this, SLOT(showPageSetting()));

    //Menu for container
    contMenu = new QMenu(this);
    contMenu->addAction(ui->actCut);
    contMenu->addAction(ui->actCopy);
    contMenu->addAction(ui->actPaste);
    contMenu->setFocusPolicy(Qt::NoFocus);
    contMenu->addSeparator();

    newReportPage();

    xmlDoc = new QDomDocument("Report");
    //openFile();
}

void MainWindow::updateRecentFileActions() {
    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) { //QFileInfo(fullFileName).fileName()
        QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(files[i]).fileName());
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);

    separatorAct->setVisible(numRecentFiles > 0);
}

void MainWindow::openRecentFile() {
    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        fileName = action->data().toString();
        openFile();
    }
}

void MainWindow::setCurrentFile(const QString &fileName) {
    setWindowFilePath(fileName);

    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    settings.setValue("recentFileList", files);

    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin)
            mainWin->updateRecentFileActions();
    }
}

void MainWindow::bandResing(int value) {
    ui->actSaveReport->setEnabled(true);
    setParamTree(Height, value);
}

void MainWindow::changeFrameWidth() {
    listFrameStyle->close();

    if (widgetInFocus == 0) return;
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
    if (cont == 0) return;

    ui->actSaveReport->setEnabled(true);

    cont->setBorder(FrameWidth,this->cbFrameWidth->currentText());
    cont->setFocus();
}

void MainWindow::showLanguage() {
    LanguageDlg *ldlg = new LanguageDlg(this);
    ldlg->exec();
}

void MainWindow::showFrameStyle(QPoint pos) {
    pos.setY(pos.y()+81);
    pos.setX(pos.x());
    listFrameStyle->move(pos);
    listFrameStyle->show();
}

void MainWindow::setFrameStyle(QListWidgetItem * item) {
    listFrameStyle->close();

    if (widgetInFocus == 0) return;
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
    if (cont == 0) return;

    ui->actSaveReport->setEnabled(true);

    switch (item->data(Qt::UserRole).toInt()) {
        case 1: {
            cont->setBorder(FrameStyle,Solid);
            break;
        }
        case 2: {
            cont->setBorder(FrameStyle,Dashed);
            break;
        }
        case 3: {
            cont->setBorder(FrameStyle,Dotted);
            break;
        }
        case 4: {
            cont->setBorder(FrameStyle,Dot_dash);
            break;
        }
        case 5: {
            cont->setBorder(FrameStyle,Dot_dot_dash);
            break;
        }
        case 6: {
            cont->setBorder(FrameStyle,Double);
            break;
        }
    }

    cont->setFocus();
}

void MainWindow::showAbout() {
    AboutDlg *dlg = new AboutDlg(this);
    dlg->exec();
    delete dlg;
}

void MainWindow::reportPageChanged(int index) {
    //if (rootItem != 0 && rootItem->childCount() > 0)
    rootItem->takeChildren();
    widgetInFocus = 0;

    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->widget(index));
    QList<QWidget *> list = repPage->getReportItems();

    this->actRepTitle->setEnabled(true);
    this->actReportSummary->setEnabled(true);
    this->actPageHeader->setEnabled(true);
    this->actPageFooter->setEnabled(true);
    this->actMasterData->setEnabled(true);
    this->actMasterFooter->setEnabled(true);
    this->actMasterHeader->setEnabled(true);

    for (int i=0; i<list.count(); i++) {
        ReportBand *band = qobject_cast<ReportBand *>(list.at(i));
        if (band != 0) {
            rootItem->addChild(band->itemInTree);
            band->itemInTree->setExpanded(true);
            band->setFocus();
            //---
            if (band->bandType == ReportTitle) this->actRepTitle->setEnabled(false);
            if (band->bandType == ReportSummary) this->actReportSummary->setEnabled(false);
            if (band->bandType == PageHeader) this->actPageHeader->setEnabled(false);
            if (band->bandType == PageFooter) this->actPageFooter->setEnabled(false);
            if (band->bandType == MasterData) this->actMasterData->setEnabled(false);
            if (band->bandType == MasterFooter) this->actMasterFooter->setEnabled(false);
            if (band->bandType == MasterHeader) this->actMasterHeader->setEnabled(false);
        }
    }
}

void MainWindow::newReportPage() {
    RepScrollArea *repScrollArea = new RepScrollArea(this);
    repScrollArea->bandMenu->addAction(ui->actPaste);
    repScrollArea->bandMenu->addSeparator();
    repScrollArea->rootItem = rootItem;
    repScrollArea->icon = icon;
    repScrollArea->isShowGrid = ui->actShowGrid->isChecked();
    QObject::connect(ui->actShowGrid, SIGNAL(triggered(bool)), repScrollArea, SLOT(showGrid(bool)));
    QObject::connect(repScrollArea, SIGNAL(bandResing(int)), this, SLOT(bandResing(int)));
    repScrollArea->actField = ui->actAddField;

    ui->tabWidget->addTab(repScrollArea,tr("Page %1").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    ui->actShowGrid->setChecked(settings.value("ShowGrid",true).toBool());
    repScrollArea->showGrid(settings.value("ShowGrid",true).toBool());
}

void MainWindow::deleteReportPage() {
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::generateName(TContainerField *cont) {
    QList<TContainerField *> lst = this->findChildren<TContainerField *>();
    bool good = false;

    int cf = 1;
    while (!good) {
        bool fnd = false;
        for (int j=0; j != lst.count(); j++) {
            if (lst.at(j)->objectName() == QString("field%1").arg(cf)) {
                fnd = true;
                break;
            }
        }
        if (fnd)
            cf += 1;
        else {
            cont->setObjectName(QString("field%1").arg(cf));
            return;
        }
    }
}

void MainWindow::clickOnTBtn() {
    if (sender()->objectName() == "subBand") {
        ui->actionInsert_band->setChecked(true);
    }
}

void MainWindow::showPageSetting() {
    PageSettingDlg *dialog = new PageSettingDlg(this);
    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->widget(0));
    dialog->showThis(repPage->pageSetting);
    if (dialog->result() == QDialog::Accepted) {
        for (int i=0; i<ui->tabWidget->count(); i++) {
            repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->widget(i));
            repPage->pageSetting = dialog->pageSetting;
            repPage->setPaperSize();
        }
        ui->actSaveReport->setEnabled(true);
    }
    delete dialog;
}

void MainWindow::delItemInTree(QTreeWidgetItem *item) {
    if (item == 0) return;
    QTreeWidgetItem *itemAbove = ui->treeWidget->itemAbove(item);
    if (itemAbove == 0) return;
    QTreeWidgetItem *parent = item->parent();
    while (item->childCount() > 0) {
        QTreeWidgetItem *tmp = item->takeChild(0);
        tmp = 0;
        delete tmp;
    }
    int index = parent->indexOfChild(item);
    delete parent->takeChild(index);
    ui->treeWidget->setCurrentItem(itemAbove);
    ui->actSaveReport->setEnabled(true);

    //Корректируем расположение бэндов
    ReportBand *reportBand = qobject_cast<ReportBand *>(sender());
    if (reportBand == 0) return;

    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
    if (repPage != 0) repPage->correctBandGeom(reportBand);

    if (reportBand->bandType == ReportTitle) actRepTitle->setEnabled(true);
    if (reportBand->bandType == ReportSummary) actReportSummary->setEnabled(true);
    if (reportBand->bandType == PageHeader) actPageHeader->setEnabled(true);
    if (reportBand->bandType == PageFooter) actPageFooter->setEnabled(true);
    if (reportBand->bandType == MasterData) actMasterData->setEnabled(true);
}

//Insert into tree new field
void MainWindow::newFeildTreeItem(TContainerField *contField, ReportBand *widget) {
    ui->treeWidget->clearSelection();
    QTreeWidgetItem *item = new QTreeWidgetItem(widget->itemInTree);
    contField->itemInTree = item;
    if (contField->type == Text || contField->type == TextImage)
        icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/field.png")), QIcon::Normal, QIcon::On);
    if (contField->type == Image)
        icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/picture.png")), QIcon::Normal, QIcon::On);
    item->setIcon(0,icon);
    item->setText(0,contField->objectName());
    item->setSelected(true);
    widget->itemInTree->addChild(item);
    widget->itemInTree->setExpanded(true);
}

void MainWindow::closeProgram() {
    if (ui->actSaveReport->isEnabled()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Saving"),tr("The report was changed.\nSave the report?"),
                                         QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
            saveReport();
    }
    this->close();
}

void MainWindow::openFile() {
    /*
    if (ui->actSaveReport->isEnabled()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Saving"),tr("The report was changed.\nSave the report?"),
                                         QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
            saveReport();
    }
    ui->actSaveReport->setEnabled(false);
    //fileName = "mydocument.xml";

    if (sender() != 0 && sender() == ui->actionOpenReport) {
        QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
        settings.setIniCodec("UTF-8");

        QString folderPath = QApplication::applicationDirPath();
        if (settings.value("recentFileList").toStringList().count() > 0)
            folderPath = QFileInfo(settings.value("recentFileList").toStringList().at(0)).path();
        fileName = QFileDialog::getOpenFileName(this, tr("Select File"), folderPath, "XML (*.xml)");
        if (!fileName.isEmpty())
            newReport();
        else return;
    }
    QFile file(fileName);
    setCurrentFile(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!xmlDoc->setContent(&file)) {
        file.close();
        return;
    }
    file.close();
    */
    xmlDoc->setContent(mFormatData);
    QDomElement docElem = xmlDoc->documentElement();  //get root element
    QDomElement repElem;

    while (ui->tabWidget->count() > 1) {
        ui->tabWidget->removeTab(ui->tabWidget->count()-1);
    }

    for (int t=0; t<docElem.childNodes().count(); t++) {
        if (docElem.tagName() == "Reports" )  //Делаем проверку для совместимости со старыми версиями
            repElem = docElem.childNodes().at(t).toElement();
        else
            repElem = docElem;

        if (t != 0) newReportPage();

        RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->widget(t));
        repPage->pageSetting.marginsLeft     = repElem.attribute("marginsLeft").toInt();
        repPage->pageSetting.marginsRight    = repElem.attribute("marginsRight").toInt();
        repPage->pageSetting.marginsTop      = repElem.attribute("marginsTop").toInt();
        repPage->pageSetting.marginsBottom   = repElem.attribute("marginsBottom").toInt();
        repPage->pageSetting.pageWidth       = repElem.attribute("pageWidth").toInt();
        repPage->pageSetting.pageHeight      = repElem.attribute("pageHeight").toInt();
        repPage->pageSetting.pageOrientation = repElem.attribute("orientation").toInt();
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tr("Page %1").arg(ui->tabWidget->currentIndex()+1));
        repPage->setPaperSize();
        //гуляем во всем элементам, родителем которых является корневой
        QDomNode n = repElem.firstChild();
        while(!n.isNull()) {
            QDomElement e = n.toElement(); // try to convert the node to an element.
            if ((!e.isNull()) && (e.tagName() == "ReportBand")) {
                BandType type;
                if (e.attribute("type") == "ReportTitle")
                    type = ReportTitle;
                if (e.attribute("type") == "PageHeader")
                    type = PageHeader;
                if (e.attribute("type") == "MasterHeader")
                    type = MasterHeader;
                if (e.attribute("type") == "MasterData")
                    type = MasterData;
                if (e.attribute("type") == "MasterFooter")
                    type = MasterFooter;
                if (e.attribute("type") == "PageFooter")
                    type = PageFooter;
                if (e.attribute("type") == "ReportSummary")
                    type = ReportSummary;

                RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
                ReportBand *reportBand = repPage->m_addBand(e.attribute("name"),type,e.attribute("height").toInt());
                QDomNode c = n.firstChild();
                while(!c.isNull()) {
                    QDomElement e = c.toElement(); // try to convert the node to an element.
                    if ((!e.isNull()) && (e.tagName() == "TContainerField")) {
                        QPoint p(e.attribute("left").toInt(),e.attribute("top").toInt());
                        TContainerField *contField  = new TContainerField(reportBand->contWidget,p);
                        QRect r = contField->geometry();
                        r.setHeight(e.attribute("height").toInt());
                        r.setWidth(e.attribute("width").toInt());
                        contField->setGeometry(r);
                        contField->setObjectName(e.attribute("name"));
                        contField->setText(e.attribute("value"));
                        contField->setMenu(contMenu);

                        contField->setSheetValue(BackgroundColor,e.attribute("backgroundColor","rgba(255,255,255,0)"));
                        contField->setSheetValue(FontColor,e.attribute("fontColor","rgba(0,0,0,255)"));
                        contField->setSheetValue(BorderColor,e.attribute("borderColor","rgba(0,0,0,255)"));
                        contField->setSheetValue(FrameTop,e.attribute("borderTop","rgba(0,0,0,255)"));
                        contField->setSheetValue(FrameBottom,e.attribute("borderBottom","rgba(0,0,0,255)"));
                        contField->setSheetValue(FrameLeft,e.attribute("borderLeft","rgba(0,0,0,255)"));
                        contField->setSheetValue(FrameRight,e.attribute("borderRight","rgba(0,0,0,255)"));
                        contField->setSheetValue(FrameWidth,e.attribute("borderWidth","1px"));
                        contField->setSheetValue(FrameStyle,e.attribute("borderStyle","solid"));

                        QFont fnt = contField->childWidget->font();
                        fnt.setBold(e.attribute("fontBold").toInt());
                        fnt.setItalic(e.attribute("fontItalic").toInt());
                        fnt.setUnderline(e.attribute("fontUnderline").toInt());
                        fnt.setFamily(e.attribute("fontFamily"));
                        fnt.setPointSize(e.attribute("fontSize").toInt());
                        contField->childWidget->setFont(fnt);
                        contField->setVisible(true);
                        contField->setSelected(false);
                        contField->printing = e.attribute("printing","1");
                        contField->highlighting = e.attribute("highlighting","");

                        QLabel *label = qobject_cast<QLabel *>(contField->childWidget);
                        if (label != 0) {
                            Qt::Alignment hAl, vAl;
                            if (e.attribute("aligmentH")== "hLeft")
                                hAl = Qt::AlignLeft;
                            else if (e.attribute("aligmentH")== "hRight")
                                hAl = Qt::AlignRight;
                            else if (e.attribute("aligmentH")== "hCenter")
                                hAl = Qt::AlignHCenter;
                            else if (e.attribute("aligmentH") == "hJustify")
                                hAl = Qt::AlignJustify;
                            else
                                hAl = Qt::AlignLeft;

                            if (e.attribute("aligmentV") == "vTop")
                                vAl = Qt::AlignTop;
                            else if (e.attribute("aligmentV") == "vBottom")
                                vAl = Qt::AlignBottom;
                            else if (e.attribute("aligmentV") == "vCenter")
                                vAl = Qt::AlignVCenter;
                            else
                                vAl = Qt::AlignVCenter;

                            label->setAlignment(hAl | vAl);
                            if (e.attribute("type","label") == "label") {
                                contField->type = Text;
                            } else if (e.attribute("type","label") == "labelImage") {
                                contField->type = TextImage;
                            }
                            if (e.attribute("type","label") == "image" || e.attribute("picture","text") != "text") {
                                contField->type = Image;
                                //загружаем картинку в лейбу

                                QByteArray byteArray;
                                byteArray = QByteArray::fromBase64(e.attribute("picture","text").toAscii());
                                QPixmap pixmap = QPixmap::fromImage(QImage::fromData(byteArray, "PNG"));
                                label->setPixmap(pixmap);
                                label->setScaledContents(true);
                            }
                        }

                        QObject::connect(contField, SIGNAL(delCont(QTreeWidgetItem *)), this, SLOT(delItemInTree(QTreeWidgetItem *)));
                        QObject::connect(contField, SIGNAL(contChanged(bool)), ui->actSaveReport, SLOT(setEnabled(bool)));
                        QObject::connect(contField, SIGNAL(inFocus(bool)), this, SLOT(setWidgetInFocus(bool)));
                        QObject::connect(contField, SIGNAL(newGeometry(QRect, QRect)), this, SLOT(contPos(QRect, QRect)));
                        newFeildTreeItem(contField,reportBand);
                    }
                    c = c.nextSibling();
                }
            }
            n = n.nextSibling();
        }
    }

    ui->treeWidget->clearSelection();
    widgetInFocus = 0;
    this->setFocus();
    ui->tabWidget->setCurrentIndex(0);
}

//Выбираем цвет из диалога и устанавливаем  параметру
void MainWindow::chooseColor() {
    if (widgetInFocus == 0) return;
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
    if (cont == 0) return;
    QColor color;
    QColorDialog *dlg = new QColorDialog(color, this);
    if (dlg->exec() == QDialog::Accepted) {
        color = dlg->selectedColor();
        ui->actSaveReport->setEnabled(true);
    } else return;

    QString strColor = TContainerField::colorToString(color);
    if (sender() == ui->actFontColor)
        cont->setSheetValue(FontColor,strColor);
    if (sender() == ui->actBackgroundColor)
        cont->setSheetValue(BackgroundColor,strColor);
    if (sender() == ui->actBorderColor)
        cont->setBorder(None,color);

    delete dlg;
}

//Нажимаем на кнопочки
void MainWindow::changeTextFont() {
    if (widgetInFocus == 0) return;
    TContainerField *widget = qobject_cast<TContainerField *>(widgetInFocus);
    if (widget == 0) return;

    QAction *action = qobject_cast<QAction *>(sender());
    QComboBox *cmb = qobject_cast<QComboBox *>(sender());
    Command command = getCommand(sender());
    QVariant v;
    if (action != 0) {
        v = action->isChecked();
        if (action == ui->actAlignLeft) v=0;
        if (action == ui->actAlignRight) v=2;
        if (action == ui->actAlignCenter) v=1;
        if (action == ui->actAlignJustify) v=3;
        if (action == ui->actAlignTop) v=0;
        if (action == ui->actAlignVCenter) v=1;
        if (action == ui->actAlignBottom) v=2;
    }
    if (cmb != 0) {
        v = cmb->itemText(cmb->currentIndex());
    }

    execButtonCommand(command,v);
    ui->actSaveReport->setEnabled(true);
}

//Определяем, тип команды в зависимости от нажатой кнопки
Command MainWindow::getCommand(QObject *widget) {
    if (widget == 0) return None;
    QAction *action = qobject_cast<QAction *>(widget);
    QComboBox *cmb = qobject_cast<QComboBox *>(widget);
    if (action != 0) {
        if (action == ui->actionBold) return Bold;
        else if (action == ui->actionItalic) return Italic;
        else if (action == ui->actionUnderline) return Underline;
        else if (action == ui->actLineLeft) return FrameLeft;
        else if (action == ui->actLineRight) return FrameRight;
        else if (action == ui->actLineBottom) return FrameBottom;
        else if (action == ui->actLineTop) return FrameTop;
        else if (action == ui->actLineNo) return FrameNo;
        else if (action == ui->actLineAll) return FrameAll;
        else if (action == ui->actAlignLeft) return AligmentH;
        else if (action == ui->actAlignRight) return AligmentH;
        else if (action == ui->actAlignCenter) return AligmentH;
        else if (action == ui->actAlignJustify) return AligmentH;
        else if (action == ui->actAlignTop) return AligmentV;
        else if (action == ui->actAlignVCenter) return AligmentV;
        else if (action == ui->actAlignBottom) return AligmentV;
        else if (action == ui->actFrameStyle) return FrameStyle;
        else return None;
    }
    if (cmb != 0) {
        if (cmb == cbFontSize)
            return FontSize;
        if (cmb == cbFontName)
            return FontName;
        if (cmb == cbFrameWidth)
            return FrameWidth;
        return None;
    }
    return None;
}

//Получаем от контейнера сигнала об изменении геометрии
void MainWindow::contPos(QRect oldRect, QRect newRect) {
    setParamTree(Left, newRect.x());
    setParamTree(Top, newRect.y());
    setParamTree(Width, newRect.width());
    setParamTree(Height, newRect.height());
    ui->actSaveReport->setEnabled(true);

    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
    QList<TContainerField *> allContList = repPage->findChildren<TContainerField *>();
    for (int i=0; i<allContList.size(); i++) {
        if (allContList.at(i)->isSelected() && allContList.at(i) != sender()) {
            int delta;
            if (oldRect.x() != newRect.x()) {
                //двигаем по гор
                delta = newRect.x() - oldRect.x();

                QPoint newPos(allContList.at(i)->x(),allContList.at(i)->y());
                newPos.setX(newPos.x()+delta);
                allContList.at(i)->move(newPos);
            }
            if (oldRect.y() != newRect.y()) {
                //двигаем по верт
                delta = newRect.y() - oldRect.y();

                QPoint newPos(allContList.at(i)->x(),allContList.at(i)->y());
                newPos.setY(newPos.y()+delta);
                allContList.at(i)->move(newPos);
            }
            if (oldRect.width() != newRect.width()) {
                //изменяем ширину
                delta = newRect.width() - oldRect.width();
                allContList.at(i)->resize(allContList.at(i)->width()+delta, allContList.at(i)->height());
            }
            if (oldRect.height() != newRect.height()) {
                //изменяем высоту
                delta = newRect.height() - oldRect.height();
                allContList.at(i)->resize(allContList.at(i)->width(), allContList.at(i)->height()+delta);
            }

            allContList.at(i)->parentWidget()->repaint();
        }
    }
}

//При выборе виджета, показываем его параметры в дереве и на кнопках
void MainWindow::setWidgetInFocus(bool inFocus) {
    if (inFocus && sender() != 0) {
        if (QApplication::keyboardModifiers() != Qt::ShiftModifier) {
            widgetInFocus = qobject_cast<QWidget *>(sender());
            ui->treeParams->clear();
            showParamState();
        }

        //Un-select containters
        if (QApplication::keyboardModifiers() != Qt::ShiftModifier) {
            RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
            QList<TContainerField *> allContList = repPage->findChildren<TContainerField *>();
            for (int i=0; i<allContList.size(); i++) {
                if (allContList.at(i)->isSelected() && allContList.at(i) != sender()) {
                    allContList.at(i)->setSelected(false);
                }
            }
        }
    }
}

void MainWindow::alignFields() {
    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
    QList<TContainerField *> allContList = repPage->findChildren<TContainerField *>();
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
    for (int i=0; i<allContList.size(); i++) {
        if (allContList.at(i)->isSelected()) {
            QPoint newPos(allContList.at(i)->x(),allContList.at(i)->y());
            QRect rect1(cont->geometry());
            QRect rect2(allContList.at(i)->geometry());

            if (sender() == ui->actFieldRight) {
                newPos.setX(rect1.x()+rect1.width()-rect2.width());
                allContList.at(i)->move(newPos);
            }
            if (sender() == ui->actFieldLeft) {
                newPos.setX(cont->x());
                allContList.at(i)->move(newPos);
            }
            if (sender() == ui->actFieldMiddle) {
                newPos.setX(rect1.x()+rect1.width()/2-rect2.width()/2);
                allContList.at(i)->move(newPos);
            }
            if (sender() == ui->actFieldTop) {
                newPos.setY(cont->y());
                allContList.at(i)->move(newPos);
            }
            if (sender() == ui->actFieldBottom) {
                newPos.setY(rect1.y()+rect1.height()-rect2.height());
                allContList.at(i)->move(newPos);
            }
            if (sender() == ui->actFieldCenter) {
                newPos.setY(rect1.y()+rect1.height()/2-rect2.height()/2);
                allContList.at(i)->move(newPos);
            }
            if (sender() == ui->actFieldSameHeight) {
                allContList.at(i)->resize(allContList.at(i)->width(), rect1.height());
            }
            if (sender() == ui->actFieldSameWidth) {
                allContList.at(i)->resize(rect1.width(), allContList.at(i)->height());
            }

            allContList.at(i)->parentWidget()->repaint();
        }
    }
}

void MainWindow::saveReport() {
    xmlDoc->clear();
    QDomElement docElem = xmlDoc->createElement("Reports");
    docElem.setAttribute("lib","QtRPT");
    docElem.setAttribute("programmer","jk liu");
    docElem.setAttribute("email","vesaliu@163.com");
    xmlDoc->appendChild(docElem);

    //before saving, we are deleting all nodes

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        n.parentNode().removeChild(n);
        n = docElem.firstChild();
    }

    for (int rp=0; rp<ui->tabWidget->count(); rp++) {
        RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->widget(rp));
        QDomElement repElem = xmlDoc->createElement("Report");
        repElem.setAttribute("pageNo",QString::number(rp+1));
        repElem.setAttribute("pageHeight",repPage->pageSetting.pageHeight);
        repElem.setAttribute("pageWidth",repPage->pageSetting.pageWidth);
        repElem.setAttribute("marginsLeft",repPage->pageSetting.marginsLeft);
        repElem.setAttribute("marginsRight",repPage->pageSetting.marginsRight);
        repElem.setAttribute("marginsTop",repPage->pageSetting.marginsTop);
        repElem.setAttribute("marginsBottom",repPage->pageSetting.marginsBottom);
        repElem.setAttribute("orientation",repPage->pageSetting.pageOrientation);
        docElem.appendChild(repElem);

        QList<QWidget *> list = repPage->getReportItems();
        for (int i=0; i<list.count(); i++) {
            TContainerField *cont = qobject_cast<TContainerField *>(list.at(i));
            ReportBand *band = qobject_cast<ReportBand *>(list.at(i));
            if (cont == 0 && band == 0) {
                continue;
            } else {
                setXMLProperty(&repElem, list.at(i));
            }
        }
    }

    /*
    if (fileName.isEmpty() || fileName.isNull() || sender() == ui->actSaveAs)
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("XML Files (*.xml)"));
    if (fileName.isEmpty() || fileName.isNull() ) return;
    QFile file(fileName);
    setCurrentFile(fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    xmlDoc->save(stream, 5, QDomNode::EncodingFromTextStream);
    file.close();
    */
    int result = 0;
    if(mId > 0){
        ReportFormatBean *bean = ReportDAO::getRptById(QString::number(mId));
        bean->setReportFormat(xmlDoc->toString());
        result = ReportDAO::updateRpt(bean);
    }else{
        ReportFormatBean *bean = new ReportFormatBean;
        bean->setWinId(mWinId.toInt());
        bean->setReportTitle(mWinPrintTitle);
        bean->setReportFormat(xmlDoc->toString());
        bean->setCreated(QDateTime::currentDateTime());
        bean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        result = ReportDAO::createRpt(bean);
        if(result > 0){
            QList<ReportFormatBean *> rList = ReportDAO::queryRptBy(mWinId);
            mId = rList.at(rList.size() - 1)->id();
        }
    }
    if(result > 0)
        ui->actSaveReport->setEnabled(false);
}

void MainWindow::setPrintFotmatData(int id, QString winId, QString title,QString data){
    mId = id;
    mWinId = winId;
    mWinPrintTitle = title;
    mFormatData = data;
    this->setWindowTitle(this->windowTitle() + "  " +title);
    openFile();
}

bool MainWindow::setXMLProperty(QDomElement *repElem, QWidget *widget) {
    TContainerField *cont = qobject_cast<TContainerField *>(widget);
    ReportBand *band = qobject_cast<ReportBand *>(widget);
    QDomElement elem;
    if (band != 0) {
        QString type;
        if (band->bandType == ReportTitle)
            type = "ReportTitle";
        if (band->bandType == ReportSummary)
            type = "ReportSummary";
        if (band->bandType == PageHeader)
            type = "PageHeader";
        if (band->bandType == PageFooter)
            type = "PageFooter";
        if (band->bandType == MasterData)
            type = "MasterData";
        if (band->bandType == MasterFooter)
            type = "MasterFooter";
        if (band->bandType == MasterHeader)
            type = "MasterHeader";
        elem = xmlDoc->createElement(band->metaObject()->className());
        elem.setAttribute("name",band->objectName());
        elem.setAttribute("type",type);
        elem.setAttribute("top",widget->geometry().y());
        elem.setAttribute("left",widget->geometry().x());
        elem.setAttribute("width",widget->geometry().width());
        elem.setAttribute("height",band->contWidget->geometry().height()-1);
        //QMessageBox::information(this,"",QString::number(band->contWidget->geometry().height()));
        repElem->appendChild(elem);
    }
    if (cont != 0) {
        QString parent = cont->parent()->parent()->objectName();
        QDomNodeList nodelist = repElem->elementsByTagName("ReportBand");
        for (int i=0; i != nodelist.count(); i++) {
            QDomNode prn = nodelist.item(i).toElement();
            if (prn.toElement().attribute("name") == parent) {
                elem = xmlDoc->createElement(cont->metaObject()->className());
                QLabel *label = qobject_cast<QLabel *>(cont->childWidget);
                if (label != 0) {
                    elem.setAttribute("value",label->text());
                    if (cont->type == Text)
                        elem.setAttribute("type","label");
                    if (cont->type == TextImage)
                        elem.setAttribute("type","labelImage");
                    if (cont->type == Image)
                        elem.setAttribute("type","image");
                    QString hAl, vAl;
                    if (label->alignment() & Qt::AlignLeft)
                        hAl = "hLeft";
                    else if (label->alignment() & Qt::AlignRight)
                        hAl = "hRight";
                    else if (label->alignment() & Qt::AlignHCenter)
                        hAl = "hCenter";
                    else if (label->alignment() & Qt::AlignJustify)
                        hAl = "hJustify";
                    else
                        hAl = "hLeft";

                    if (label->alignment() & Qt::AlignTop)
                        vAl = "vTop";
                    else if (label->alignment() & Qt::AlignBottom)
                        vAl = "vBottom";
                    else if (label->alignment() & Qt::AlignVCenter)
                        vAl = "vCenter";
                    else
                        vAl = "vCenter";

                    elem.setAttribute("aligmentH",hAl);
                    elem.setAttribute("aligmentV",vAl);
                }
                elem.setAttribute("name",cont->objectName());
                elem.setAttribute("top",widget->geometry().y());
                elem.setAttribute("left",widget->geometry().x());
                elem.setAttribute("width",widget->geometry().width());
                elem.setAttribute("height",widget->geometry().height());
                elem.setAttribute("fontBold",label->font().bold());
                elem.setAttribute("fontItalic",label->font().italic());
                elem.setAttribute("fontUnderline",label->font().underline());
                if (label->font().family().isEmpty()) elem.setAttribute("fontFamily","Arial");
                else elem.setAttribute("fontFamily",label->font().family());
                elem.setAttribute("fontSize",label->font().pointSize());

                QString fontColor = cont->getColorValue(FontColor);
                QString backgroundColor = cont->getColorValue(BackgroundColor);
                QString borderColor = cont->getColorValue(BorderColor);
                QString top = cont->getColorValue(FrameTop);
                QString bottom = cont->getColorValue(FrameBottom);
                QString left = cont->getColorValue(FrameLeft);
                QString right = cont->getColorValue(FrameRight);

                elem.setAttribute("fontColor",fontColor);
                elem.setAttribute("backgroundColor",backgroundColor);
                elem.setAttribute("borderColor",borderColor);
                elem.setAttribute("borderTop",top);
                elem.setAttribute("borderBottom",bottom);
                elem.setAttribute("borderLeft",left);
                elem.setAttribute("borderRight",right);

                elem.setAttribute("printing",cont->printing);
                elem.setAttribute("highlighting",cont->highlighting);

                //Write a borderWidth
                int start = cont->styleSheet().indexOf(";border-width:",0,Qt::CaseInsensitive);
                int end = cont->styleSheet().indexOf(";",start+1,Qt::CaseInsensitive);
                QString tmp = cont->styleSheet().mid(start+1,end-start-1);
                start = tmp.indexOf(":",0,Qt::CaseInsensitive);
                tmp = tmp.mid(start+1);
                elem.setAttribute("borderWidth",tmp);

                //Write a borderStyle
                start = cont->styleSheet().indexOf(";border-style:",0,Qt::CaseInsensitive);
                end = cont->styleSheet().indexOf(";",start+1,Qt::CaseInsensitive);
                tmp = cont->styleSheet().mid(start+1,end-start-1);
                start = tmp.indexOf(":",0,Qt::CaseInsensitive);
                tmp = tmp.mid(start+1);
                elem.setAttribute("borderStyle",tmp);

                //qDebug()<<tmp;

                if (cont->type == Image) {
                    //Сохраняем картинку
                    QByteArray byteArray;
                    QBuffer buffer(&byteArray);
                    buffer.open(QIODevice::WriteOnly);

                    label->pixmap()->save(&buffer, "PNG");
                    QString s = byteArray.toBase64();
                    elem.setAttribute("picture",s);
                }

                prn.appendChild(elem);
            }
        }
    }
    return false;
}

//Показываем параметры в зависимости от объекта
void MainWindow::showParamState() {
    ui->treeParams->clear();
    ReportBand *rep = qobject_cast<ReportBand *>(widgetInFocus);
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);

    map.clear();
    if (rep != 0) {
        ui->actAlignBottom->setChecked(false);
        ui->actAlignCenter->setChecked(false);
        ui->actAlignJustify->setChecked(false);
        ui->actAlignLeft->setChecked(false);
        ui->actAlignRight->setChecked(false);
        ui->actAlignTop->setChecked(false);
        ui->actAlignVCenter->setChecked(false);
        ui->actionBold->setChecked(false);
        ui->actionItalic->setChecked(false);
        ui->actionUnderline->setChecked(false);
        ui->actLineAll->setChecked(false);
        ui->actLineNo->setChecked(false);
        ui->actLineBottom->setChecked(false);
        ui->actLineLeft->setChecked(false);
        ui->actLineRight->setChecked(false);
        ui->actLineTop->setChecked(false);

        ui->actAlignBottom->setEnabled(false);
        ui->actAlignCenter->setEnabled(false);
        ui->actAlignJustify->setEnabled(false);
        ui->actAlignLeft->setEnabled(false);
        ui->actAlignRight->setEnabled(false);
        ui->actAlignTop->setEnabled(false);
        ui->actAlignVCenter->setEnabled(false);
        ui->actionBold->setEnabled(false);
        ui->actionItalic->setEnabled(false);
        ui->actionUnderline->setEnabled(false);
        ui->actLineAll->setEnabled(false);
        ui->actLineNo->setEnabled(false);
        ui->actLineBottom->setEnabled(false);
        ui->actLineLeft->setEnabled(false);
        ui->actLineRight->setEnabled(false);
        ui->actLineTop->setEnabled(false);

        selectItemInTree(rep->itemInTree);
        setParamTree(Name, rep->objectName());
        setParamTree(Height, rep->geometry().height() - rep->titleHeight);

    } else {
        ui->actAlignBottom->setEnabled(true);
        ui->actAlignCenter->setEnabled(true);
        ui->actAlignJustify->setEnabled(true);
        ui->actAlignLeft->setEnabled(true);
        ui->actAlignRight->setEnabled(true);
        ui->actAlignTop->setEnabled(true);
        ui->actAlignVCenter->setEnabled(true);
        ui->actionBold->setEnabled(true);
        ui->actionItalic->setEnabled(true);
        ui->actionUnderline->setEnabled(true);
        ui->actLineAll->setEnabled(true);
        ui->actLineNo->setEnabled(true);
        ui->actLineBottom->setEnabled(true);
        ui->actLineLeft->setEnabled(true);
        ui->actLineRight->setEnabled(true);
        ui->actLineTop->setEnabled(true);

        QLabel *label = qobject_cast< QLabel * >(cont->childWidget);
        int al = 0;
        int alV = 0;
        if (label->alignment() & Qt::AlignLeft) al = 0;
        else if (label->alignment() & Qt::AlignHCenter) al = 1;
        else if (label->alignment() & Qt::AlignRight) al = 2;
        else if (label->alignment() & Qt::AlignJustify) al = 3;

        if (label->alignment() & Qt::AlignTop) alV = 0;
        else if (label->alignment() & Qt::AlignVCenter) alV = 1;
        else if (label->alignment() & Qt::AlignBottom) alV = 2;

        bool top = cont->borderIsCheck(FrameTop);
        bool bottom = cont->borderIsCheck(FrameBottom);
        bool left = cont->borderIsCheck(FrameLeft);
        bool right = cont->borderIsCheck(FrameRight);

        //Выставляем кнопки в соответствие с параметрами
        selectItemInTree(cont->itemInTree);
        setParamTree(AligmentH, al);
        setParamTree(AligmentV, alV);
        setParamTree(Name, cont->objectName());
        setParamTree(Height, cont->geometry().height());
        setParamTree(Width, cont->geometry().width());
        setParamTree(Left, cont->geometry().x());
        setParamTree(Top, cont->geometry().y());
        setParamTree(Font, "Font");
        setParamTree(FontName, label->font().family(), true);
        setParamTree(FontSize, label->font().pointSize(), true);
        setParamTree(Bold, label->font().bold(), true);
        setParamTree(Italic, label->font().italic(), true);
        setParamTree(Underline, label->font().underline(), true);
        setParamTree(Frame, "Frame");
        setParamTree(FrameLeft, left, true);
        setParamTree(FrameRight, right, true);
        setParamTree(FrameTop, top, true);
        setParamTree(FrameBottom, bottom, true);
        setParamTree(Printing, cont->printing);
    }
}

//Поиск ветки в дереве параметра
QTreeWidgetItem *MainWindow::findItemInTree(Command command) {
    QTreeWidgetItemIterator it(ui->treeParams);
    while (*it) {
        QTreeWidgetItem *item = (*it);
        if (item->data(1,Qt::UserRole) == command)
            return item;
        ++it;
    }
    return 0;
}

void MainWindow::newReport() {
    if (ui->actSaveReport->isEnabled()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Saving"),tr("The report was changed.\nSave the report?"),
                                         QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
            saveReport();
    }
    while (ui->tabWidget->count() > 1) {
        ui->tabWidget->removeTab(ui->tabWidget->count()-1);
    }

    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->widget(0));
    repPage->clearReport();
    qDeleteAll(rootItem->takeChildren());
    ui->actSaveReport->setEnabled(false);
    ui->actAddField->setEnabled(repPage->allowField());
}

void MainWindow::selectItemInTree(QTreeWidgetItem *item) {
    QTreeWidgetItemIterator it(rootItem);
    while (*it) {
        (*it)->setSelected(false);
        if ((*it) == item)
            (*it)->setSelected(true);

        ++it;
    }
}

void MainWindow::execButtonCommand(Command command, QVariant value) {
    if (command == None) return;
    if (widgetInFocus == 0) return;
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
    //ReportBand *rep = qobject_cast<ReportBand *>(widgetInFocus);

    QLabel *label;
    QFont fnt;
    if (cont != 0) {
        label = qobject_cast< QLabel * >(cont->childWidget);
        fnt = label->font();
    }

    switch(command) {
        case None: {
            return;
            break;
        }
        case Name: {
            widgetInFocus->setObjectName(value.toString());
            cont->itemInTree->setText(0,value.toString());
            break;
        }
        case Bold: {
            fnt.setBold(value.toBool());
            break;
        }
        case Italic: {
            fnt.setItalic(value.toBool());
            break;
        }
        case Underline: {
            fnt.setUnderline(value.toBool());
            break;
        }
        case FontSize: {
            fnt.setPointSize(value.toInt());
            break;
        }
        case FontName: {
            fnt.setFamily(value.toString());
            break;
        }
        case FrameLeft:
        case FrameRight:
        case FrameTop:
        case FrameBottom: {
            cont->setBorder(command,QColor(),value.toBool());
            break;
        }
        case FrameNo: {
            cont->setBorder(command,0);
            break;
        }
        case FrameAll: {
            cont->setBorder(command,0);
            break;
        }
        case AligmentH: {
            Qt::Alignment vAl;
            if (label->alignment() & Qt::AlignTop)
                vAl = Qt::AlignTop;
            else if (label->alignment() & Qt::AlignVCenter)
                vAl = Qt::AlignVCenter;
            else if (label->alignment() & Qt::AlignBottom)
                vAl = Qt::AlignBottom;
            else
                vAl = Qt::AlignVCenter;

            if (value.toInt() == 0)
                label->setAlignment(Qt::AlignLeft | vAl);
            if (value.toInt() == 1)
                label->setAlignment(Qt::AlignHCenter | vAl);
            if (value.toInt() == 2)
                label->setAlignment(Qt::AlignRight | vAl);
            if (value.toInt() == 3)
                label->setAlignment(Qt::AlignJustify | vAl);
            break;
        }
        case AligmentV: {
            Qt::Alignment hAl;
            if (label->alignment() & Qt::AlignLeft)
                hAl = Qt::AlignLeft;
            else if (label->alignment() & Qt::AlignRight)
                hAl = Qt::AlignRight;
            else if (label->alignment() & Qt::AlignHCenter)
                hAl = Qt::AlignHCenter;
            else if (label->alignment() & Qt::AlignJustify)
                hAl = Qt::AlignJustify;
            else
                hAl = Qt::AlignLeft;

            if (value.toInt() == 0)
                label->setAlignment(hAl | Qt::AlignTop);
            if (value.toInt() == 1)
                label->setAlignment(hAl | Qt::AlignVCenter);
            if (value.toInt() == 2)
                label->setAlignment(hAl | Qt::AlignBottom);
            break;
        }
        case Left: {
            QPoint r = cont->pos();
            r.setX(value.toInt());
            cont->move(r);
            break;
        }
        case Top: {
            QPoint r = cont->pos();
            r.setY(value.toInt());
            cont->move(r);
            break;
        }
        case Width: {
            QRect r = cont->geometry();
            r.setWidth(value.toInt());
            cont->setGeometry(r);
            break;
        }
        case Height: {
            QRect r = widgetInFocus->geometry();

            r.setHeight(value.toInt());
            widgetInFocus->setGeometry(r);
            break;
        }
        case Printing: {            
            cont->printing = value.toBool() == true ? "1" : "0";
            value = cont->printing;
            break;
        }
        default: break;
    }

    if (cont != 0) {
        label->setFont(fnt);
    }
    setParamTree(command,value);
    ui->actSaveReport->setEnabled(true);
}

//Устанавливаем параметры в дереве
void MainWindow::setParamTree(Command command, QVariant value, bool child) {
    if (command == None) return;
    TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
    QTreeWidgetItem *item = findItemInTree(command);
    QTreeWidgetItem *parentNode = 0;
    if (item == 0 && !child) {
        item = new QTreeWidgetItem(ui->treeParams);
    }

    switch (command) {
        case Name: {
            item->setText(0,"Name");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,value.toString());
            break;
        }
        case AligmentH: {
            item->setText(0,"Aligment hor");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            switch(value.toInt()) {
                case 0: {
                    item->setText(1,tr("Left"));
                    ui->actAlignLeft->setChecked(true);
                    break;
                }
                case 1: {
                    item->setText(1,tr("Center"));
                    ui->actAlignCenter->setChecked(true);
                    break;
                }
                case 2: {
                    item->setText(1,tr("Right"));
                    ui->actAlignRight->setChecked(true);
                    break;
                }
                case 3: {
                    item->setText(1,tr("Justify"));
                    ui->actAlignJustify->setChecked(true);
                    break;
                }
                default: item->setText(1,"");
            }

            map.insert(ui->actAlignLeft,item);
            break;
        }
        case AligmentV: {
            item->setText(0,"Aligment ver");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            switch(value.toInt()) {
                case 0: {
                    item->setText(1,"Top");
                    ui->actAlignTop->setChecked(true);
                    break;
                }
                case 1: {
                    item->setText(1,"Center");
                    ui->actAlignVCenter->setChecked(true);
                    break;
                }
                case 2: {
                    item->setText(1,"Bottom");
                    ui->actAlignBottom->setChecked(true);
                    break;
                }
                default: item->setText(1,"");
            }

            map.insert(ui->actAlignTop,item);
            break;
        }
        case Height: {
            item->setText(0,"Height");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,value.toString());
            break;
        }
        case Width: {
            item->setText(0,"Width");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,QString::number(value.toInt()-1));
            break;
        }
        case Left: {
            item->setText(0,"Left");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,value.toString());
            break;
        }
        case Top: {
            item->setText(0,"Top");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,value.toString());
            break;
        }
        case Frame:
        case Font: {
            item->setText(0,value.toString());
            item->setText(1,"");
            break;
        }
        case FrameLeft: {
            parentNode = findItemInTree(Frame);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Left");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actLineLeft->setChecked(value.toBool());

            map.insert(ui->actLineLeft,item);
            break;
        }
        case FrameRight: {
            parentNode = findItemInTree(Frame);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Right");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actLineRight->setChecked(value.toBool());

            map.insert(ui->actLineRight,item);
            break;
        }
        case FrameTop: {
            parentNode = findItemInTree(Frame);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Top");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actLineTop->setChecked(value.toBool());

            map.insert(ui->actLineTop,item);
            break;
        }
        case FrameBottom: {
            parentNode = findItemInTree(Frame);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Bottom");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actLineBottom->setChecked(value.toBool());
            map.insert(ui->actLineBottom,item);
            break;
        }
        case FrameNo: {
            setParamTree(FrameLeft,false,true);
            setParamTree(FrameRight,false,true);
            setParamTree(FrameTop,false,true);
            setParamTree(FrameBottom,false,true);
            ui->actLineAll->setChecked(false);
            ui->actLineNo->setChecked(true);
            break;
        }
        case FrameAll: {
            setParamTree(FrameLeft,true,true);
            setParamTree(FrameRight,true,true);
            setParamTree(FrameTop,true,true);
            setParamTree(FrameBottom,true,true);
            ui->actLineAll->setChecked(true);
            break;
        }
        case FontName: {
            parentNode = findItemInTree(Font);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Name");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,value.toString());
            cbFontName->setCurrentFont(QFont(value.toString()));

            map.insert(this->cbFontName,item);
            break;
        }
        case FontSize: {
            parentNode = findItemInTree(Font);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Size");
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
            item->setText(1,value.toString());
            cbFontSize->setEditText(value.toString());

            map.insert(this->cbFontSize,item);
            break;
        }
        case Bold: {
            parentNode = findItemInTree(Font);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Bold");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actionBold->setChecked(value.toBool());

            map.insert(ui->actionBold,item);
            break;
        }
        case Italic: {
            parentNode = findItemInTree(Font);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Italic");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actionItalic->setChecked(value.toBool());

            map.insert(ui->actionItalic,item);
            break;
        }
        case Underline: {
            parentNode = findItemInTree(Font);
            if (item == 0)
                item = new QTreeWidgetItem(parentNode);
            item->setText(0,"Underline");
            if (value.toBool()) item->setCheckState(1,Qt::Checked);
            else item->setCheckState(1,Qt::Unchecked);
            ui->actionUnderline->setChecked(value.toBool());

            map.insert(ui->actionUnderline,item);
            break;
        }
        case Printing: {
            item->setText(0,"Printing");
            if (value.toString().size() > 1) item->setCheckState(1,Qt::Checked);
            else {
                if (value.toBool()) item->setCheckState(1,Qt::Checked);
                else item->setCheckState(1,Qt::Unchecked);
            }
            break;
        }
        default: {
            return;
        }
    }

    if (cont != 0) {
        bool top = cont->borderIsCheck(FrameTop);
        bool bottom = cont->borderIsCheck(FrameBottom);
        bool left = cont->borderIsCheck(FrameLeft);
        bool right = cont->borderIsCheck(FrameRight);

        if (top && bottom && left && right) {
            ui->actLineAll->setChecked(true);
            ui->actLineNo->setChecked(false);
        } else
            ui->actLineAll->setChecked(false);

        if (!top && !bottom && !left && !right) {
            ui->actLineAll->setChecked(false);
            ui->actLineNo->setChecked(true);
        } else
            ui->actLineNo->setChecked(false);
    }

    item->setData(1,Qt::UserRole,command);

    if (parentNode == 0)
        ui->treeParams->addTopLevelItem(item);
    else
        parentNode->addChild(item);
}

void MainWindow::selTree(QTreeWidgetItem *item, int) {
    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
    QList<QWidget *> list = repPage->getReportItems();
    for (int i=0; i<list.count(); i++) {
        TContainerField *cont = qobject_cast<TContainerField *>(list.at(i));
        ReportBand *band = qobject_cast<ReportBand *>(list.at(i));
        if (cont == 0 && band == 0) {
            continue;

        } else {
            if (cont != 0 && cont->itemInTree == item) {
                widgetInFocus = cont;
                cont->setFocus();
                cont->setSelected(true);
            }
            if (band != 0 && band->itemInTree == item) {
                widgetInFocus = band;
                band->setFocus();
            }
        }
    }
}

void MainWindow::addBand() {
    BandType type;
    QString bandName;
    if (sender()->objectName() == "actRepTitle") {
        type = ReportTitle;
        bandName = "Report title";
    }
    if (sender()->objectName() == "actReportSummary") {
        type = ReportSummary;
        bandName = "Report summary";
    }
    if (sender()->objectName() == "actPageHeader") {
        type = PageHeader;
        bandName = "Page header";
    }
    if (sender()->objectName() == "actPageFooter") {
        type = PageFooter;
        bandName = "Page footer";
    }
    if (sender()->objectName() == "actMasterData") {
        type = MasterData;
        bandName = "Master data";
    }
    if (sender()->objectName() == "actMasterFooter") {
        type = MasterFooter;
        bandName = "Master Footer";
    }
    if (sender()->objectName() == "actMasterHeader") {
        type = MasterHeader;
        bandName = "Master Header";
    }
    ui->actSelect_tool->setChecked(true);
    QAction *action = qobject_cast<QAction *>(sender());
    action->setEnabled(false);
    ui->actSaveReport->setEnabled(true);

    RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
    if (repPage != 0) repPage->m_addBand(bandName, type);
}

void MainWindow::addField() {
    newContField  = new TContainerField(this,QCursor::pos());
    //newContField->setVisible(false);
    newContField->type = Text;
    generateName(newContField);
    //newContField->setVisible(true);
    newContField->setMenu(contMenu);
    newContField->setCursor(QCursor(Qt::CrossCursor));
    newContField->setSelected(true);
    QObject::connect(newContField, SIGNAL(delCont(QTreeWidgetItem *)), this, SLOT(delItemInTree(QTreeWidgetItem *)));
    QObject::connect(newContField, SIGNAL(inFocus(bool)), this, SLOT(setWidgetInFocus(bool)));
    QObject::connect(newContField, SIGNAL(newGeometry(QRect, QRect)), this, SLOT(contPos(QRect, QRect)));
    newContMoving = true;

    ui->actSaveReport->setEnabled(true);
    ui->toolBar_3->repaint();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (ui->actSaveReport->isEnabled()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Saving"),tr("The report was changed.\nSave the report?"),
                                         QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
            saveReport();
    }
 }

bool MainWindow::eventFilter(QObject *obj, QEvent *e) {
    if(e->type()==QEvent::Paint) {
        if (obj->objectName() == "repWidget") {
            RepScrollArea *repPage = qobject_cast<RepScrollArea *>(ui->tabWidget->currentWidget());
            repPage->paintGrid();
            return true;
        }
    }
    if(e->type() == QMouseEvent::MouseButtonPress) {
        QToolButton *tb = qobject_cast<QToolButton*>(obj);
        if (tb != 0 && tb->actions().at(0) == ui->actFrameStyle)
            showFrameStyle(tb->pos());
    }
    if (e->type() == QMouseEvent::MouseMove) {
        QMouseEvent *m = static_cast< QMouseEvent * >( e );
        if (newContField && newContMoving) {
            QPoint p1 = QPoint(m->globalPos().x()-1,
                                     m->globalPos().y());
            QWidget *pw = QApplication::widgetAt(p1);
            ReportBand *widget = qobject_cast<ReportBand *>(pw->parent());
            if (widget != 0) {
                newContField->setVisible(true);
            }
            newContField->allowEditing(false);
            newContField->setCursor(QCursor(Qt::CrossCursor));
            QPoint position = QPoint(m->globalPos().x(), m->globalPos().y()-19);
            newContField->move(position);
        }
    }
    if (e->type() == QMouseEvent::MouseButtonRelease) {
        QMouseEvent *m = static_cast< QMouseEvent * >( e );
        if (newContField && newContMoving) {
            ui->actSelect_tool->setChecked(true);
            QPoint position = QPoint(m->globalPos().x()-1,
                                     m->globalPos().y());
            QWidget *pw = QApplication::widgetAt(position);
            ReportBand *widget = qobject_cast<ReportBand *>(pw->parent());
            if (widget == 0) widget = qobject_cast<ReportBand *>(pw->parent()->parent());
            if (widget != 0) {
                newContField->setParent(widget->contWidget);
                QPoint p = QPoint(widget->contWidget->mapFromGlobal(m->globalPos()));
                newContField->move(QPoint(p.x()+1,
                                          p.y()+0));//-newContField->height()*2+22));
                newContField->setVisible(true);
                newContField->allowEditing(true);
                newContField->setFocus();
                newContField->setSelected(true);
                ui->actSaveReport->setEnabled(true);

                newFeildTreeItem(newContField,widget);
                newContField->edit();
            } else {
                QMessageBox::warning(this, tr("Error"), tr("This object %1 can't be a parent for %2").arg(pw->objectName()).arg(newContField->objectName()), QMessageBox::Ok);
                return QWidget::eventFilter(obj,e);
            }
        }
        newContMoving = false;
    }
    return QWidget::eventFilter(obj,e);
}

void MainWindow::AddPicture() {
    addField();
    newContField->setText(tr("New image"));
    newContField->setImage(QPixmap(QString::fromUtf8(":/new/prefix1/images/picture.png")));
    newContField->type = Image;
    newContField->setStyleSheet("/**/");
}

//Обработка при клике на встроенном чек-боксе
void MainWindow::itemChanged(QTreeWidgetItem *item, int column) {
    if (column == 1 ) {
        if (widgetInFocus == 0) return;
            QVariant v;
            Command command = (Command)item->data(1,Qt::UserRole).toInt();
            switch (command) {
                case Printing:
                case Bold:
                case Italic:
                case Underline:
                case FrameLeft:
                case FrameRight:
                case FrameTop:
                case FrameBottom: {
                    if (item->checkState(1) == Qt::Checked) v = true;
                    else v = false;
                    break;
                }
                default: {
                    return;
                }
            }
            execButtonCommand(command,v);
    }
}

//Меняем параметр в дереве параметров
void MainWindow::closeEditor() {
    QTreeWidgetItem *item = ui->treeParams->currentItem();
    if (item == 0) return;
    if (widgetInFocus == 0) return;
        QVariant v;
        Command command = (Command)item->data(1,Qt::UserRole).toInt();
        switch (command) {
            case Name:
            case Left:
            case Top:            
            case Height:
            case AligmentH:
            case AligmentV:
            case FontName:
            case FontSize: {
                v = item->text(1);
                ReportBand *rep = qobject_cast<ReportBand *>(widgetInFocus);
                if (command == Height && rep != 0)
                    v = item->text(1).toInt()+rep->titleHeight;
                break;
            }
            case Width: {
                v = item->text(1).toInt()+1;
                break;
            }
            default: {
                return;
            }
        }
        execButtonCommand(command,v);
}

void MainWindow::clipBoard() {
    if (sender() == ui->actCopy) {
        cloneCont = qobject_cast<TContainerField*>(widgetInFocus);
        ui->actPaste->setEnabled(true);
    }
    if (sender() == ui->actCut) {
        cloneCont = qobject_cast<TContainerField*>(widgetInFocus);
        cloneCont->setVisible(false);
        ui->actPaste->setEnabled(true);
    }
    if (sender() == ui->actPaste) {
        if (cloneCont == 0) return;
        if (cloneCont->isVisible()) {
            newContField = cloneCont->clone();
            generateName(newContField);

        } else {
            delItemInTree(cloneCont->itemInTree);
            newContField = cloneCont;
        }

        ReportBand *band = qobject_cast<ReportBand *>(widgetInFocus);
        TContainerField *cont = qobject_cast<TContainerField *>(widgetInFocus);
        if (cont != 0)
            band = qobject_cast<ReportBand *>(cont->parentWidget()->parentWidget());

        newContField->setParent(band->contWidget);
        newContField->setMenu(contMenu);
        newContField->setVisible(true);
        newFeildTreeItem(newContField,band);
        widgetInFocus = newContField;

        QObject::connect(newContField, SIGNAL(delCont(QTreeWidgetItem *)), this, SLOT(delItemInTree(QTreeWidgetItem *)));
        QObject::connect(newContField, SIGNAL(inFocus(bool)), this, SLOT(setWidgetInFocus(bool)));
        QObject::connect(newContField, SIGNAL(newGeometry(QRect, QRect)), this, SLOT(contPos(QRect, QRect)));

        newContField->setFocus();
        showParamState();
        ui->actSaveReport->setEnabled(true);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
