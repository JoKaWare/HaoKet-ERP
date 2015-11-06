/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtGui>
#include <QDomDocument>
#include "PageSettingDlg.h"
#include "ReportBand.h"
#include "tcontainerfield.h"
#include "aboutDlg.h"
#include "languagedlg.h"
#include "RepScrollArea.h"
#include "editordelegate.h"
#include "LibGlobal.h"
namespace Ui {
    class MainWindow;
}

class LIBSHARED_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPrintFotmatData(int id,QString winId,QString title,QString data);

protected:
    bool eventFilter(QObject *obj, QEvent *e);
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    int mId;
    QString mWinId;
    QString mWinPrintTitle;
    QString mFormatData;
    QListWidget *listFrameStyle;
    QDomDocument *xmlDoc;    
    QTreeWidgetItem *rootItem;
    QWidget *widgetInFocus;
    TContainerField *newContField;
    TContainerField *cloneCont;
    QFontComboBox *cbFontName;
    QComboBox *cbFontSize;
    QComboBox *cbFrameWidth;
    bool newContMoving;
    QIcon icon;
    QString fileName;
    QMap<QObject *, QTreeWidgetItem *> map;
    QMenu *contMenu;


    QAction *actRepTitle;
    QAction *actReportSummary;
    QAction *actPageHeader;
    QAction *actPageFooter;
    QAction *actMasterData;
    QAction *actMasterFooter;
    QAction *actMasterHeader;
    QAction *separatorAct;

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActs[MaxRecentFiles];

    void newFeildTreeItem(TContainerField *contField, ReportBand *widget);
    bool setXMLProperty(QDomElement *repElem, QWidget *widget);
    void selectItemInTree(QTreeWidgetItem *item);
    void showParamState();
    Command getCommand(QObject *obj);
    void execButtonCommand(Command command, QVariant value);
    QTreeWidgetItem *findItemInTree(Command command);
    void generateName(TContainerField *cont);
    void setParamTree(Command command, QVariant value = 0, bool child = false);
    void updateRecentFileActions();
    void setCurrentFile(const QString &fileName);

private slots:
    void showAbout();
    void openFile();
    void newReport();
    void saveReport();
    void showPageSetting();
    void clickOnTBtn();
    void addBand();
    void addField();
    void AddPicture();
    void setWidgetInFocus(bool inFocus);
    void delItemInTree(QTreeWidgetItem *);
    void selTree(QTreeWidgetItem *item, int);
    void itemChanged(QTreeWidgetItem *item, int column);
    void closeEditor();
    void changeTextFont();
    void contPos(QRect oldRect, QRect newRect);
    void clipBoard();
    void chooseColor();
    void showFrameStyle(QPoint pos);
    void setFrameStyle(QListWidgetItem * item);
    void changeFrameWidth();
    void showLanguage();
    void bandResing(int value);
    void reportPageChanged(int index);
    void newReportPage();
    void deleteReportPage();
    void alignFields();
    void openRecentFile();
    void closeProgram();
};

#endif // MAINWINDOW_H
