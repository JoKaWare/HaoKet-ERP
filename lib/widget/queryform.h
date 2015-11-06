#ifndef QUERYFORM_H
#define QUERYFORM_H

#include <QWidget>
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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QCheckBox>
#include <QtGui/QRadioButton>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDomDocument>
#include "lib_global.h"
#include "qksearcheditbox.h"
#include "common/common.h"
#include "common/dbmanager.h"
#include "log4qt/log4qt.h"

class LIBSHARED_EXPORT QueryForm : public QWidget
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit QueryForm(QWidget *parent = 0);
    QueryForm(QList<struct childItemProperties > lItem,QList<struct childItemProperties > dItem,QString lSql,QString dSql,QWidget *parent = 0);
    QueryForm(QList<struct childItemProperties > lItem,QList<struct childItemProperties > dItem,QString lSql,QString lSql1,QString dSql,QString dSql1,QWidget *parent = 0);

    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *proTypeLabel;
    QkSearchEditBox *proNameQks;
    QDateEdit *eDateEdit;
    QLabel *endLabel;
    QkSearchEditBox *dwTypeQks;
    QLabel *dwNameLabel;
    QDateEdit *sDateEdit1;
    QLabel *idLabel;

    QLineEdit *noEdit;
    QkSearchEditBox *dwNameQks;
    QLabel *dwTypeLabel;
    QLabel *Label;
    QkSearchEditBox *proTypeQks;
    QLabel *proNameLabel;
    QLabel *startLabel;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QRadioButton *rBnt2;
    QRadioButton *rBnt1;
    QRadioButton *rBnt3;

    QToolButton *queryButton;
    QToolButton *cancelButton;
    QToolButton *printButton;
    QToolButton *exportButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_2;
    void setTabListText(QString s);
    void setTabDetailText(QString s);
    void setFormId(QString s);
    void setHandleFiled(QString h){ mHandleFiled = h;}
    void setHandleVisible(bool b);
    void setDwLableText(QString type,QString name);
    void setTotalItem(QList<int> totalItem);
    void initTableHead();
    void initData(QList<struct childItemProperties > lItem,QList<struct childItemProperties > dItem,QString lSql,QString dSql);
    void initData(QList<childItemProperties> lItem, QList<childItemProperties> dItem, QString lSql, QString lSql1,QString dSql, QString dSql1);
signals:
    void tableClicked(QString no);
private slots:
    void sQuery();
    void sPrint();
    void sExport();
    void sExit();
    void sCurChanged(int index);
    void sTableViewDoubleClicked(const QModelIndex &index);
    void sortByColumn(int column);

private:
    void setupUI();
    void retranslateUi();
    void init();
    void setupContextMenu();
    bool exportExcel(QString fileName);
    QString makeReport();

    QSqlQueryModel *sqlQueryModel(QString sql,QVector<QVariant> qvar);
    QSqlQuery sqlQuery(QString sql,QVector<QVariant> qvar);
    QList<struct childItemProperties > mListChildItem;
    QList<struct childItemProperties > mDetailChildItem;
    QList<int> mTotalItem;
    QStandardItemModel *mListModel;
    QStandardItemModel *mDetailModel;
    QString mHandleFiled;
    QString mTabListName;
    QString mTabDetailName;
    QString mFormId;
    QString mNo;
    QString mStrListSql;
    QString mStrListSql1;
    QString mStrListSql2;
    QString mStrDetailSql;
    QString mStrDetailSql1;
    QString mStrDetailSql2;

    
};

#endif // QUERYFORM_H
