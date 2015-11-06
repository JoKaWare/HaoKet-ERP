#ifndef SINGLEQUERYFORM_H
#define SINGLEQUERYFORM_H

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
#include "widget/foottablemodel.h"
#include "widget/hierarchicalheaderview.h"
#include "log4qt/log4qt.h"

class LIBSHARED_EXPORT SingleQueryForm  : public QWidget
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    SingleQueryForm(QWidget *parent);
    SingleQueryForm(QList<childItemProperties> dItem, QString dSql, QString dSql1, QWidget *parent);

    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
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
    QSpacerItem *verticalSpacer_2;
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

    void setTabDetailText(QString s);
    void setFormId(QString s);
    void setHandleFiled(QString h){ mHandleFiled = h;}
    void setHandleVisible(bool b);
    void setDwLableText(QString type,QString name);
    void setTotalItem(QList<int> totalItem);
    void initTableHead();
    void initData(QList<childItemProperties> dItem, QString dSql, QString dSql1);
signals:
    void tableClicked(QString no);
private slots:
    void sQuery();
    void sPrint();
    void sExport();
    void sExit();
    void sCurChanged(int index);
    void sTableViewDoubleClicked(const QModelIndex &index);

private:
    void setupUI();
    void retranslateUi();
    void init();
    void setupContextMenu();
    bool exportExcel(QString fileName);
    QString makeReport();

    QSqlQueryModel *sqlQueryModel(QString sql,QVector<QVariant> qvar);
    QSqlQuery sqlQuery(QString sql,QVector<QVariant> qvar);
    QList<struct childItemProperties > mDetailChildItem;
    QList<int> mTotalItem;
    QStandardItemModel *mDetailModel;
    HierarchicalHeaderView *mHv2;
    QString mHandleFiled;
    QString mTabDetailName;
    QString mFormId;
    QString mNo;
    QString mStrDetailSql;
    QString mStrDetailSql1;
    QString mStrDetailSql2;

};

#endif // SINGLEQUERYFORM_H
