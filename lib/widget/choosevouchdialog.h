#ifndef CHOOSEVOUCHDIALOG_H
#define CHOOSEVOUCHDIALOG_H

#include <QDialog>
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

class LIBSHARED_EXPORT ChooseVouchDialog : public QDialog
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit ChooseVouchDialog(QWidget *parent = 0);
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *dwTypeLabel;
    QLabel *startLabel;
    QkSearchEditBox *proTypeQks;
    QLabel *proTypeLabel;
    QLabel *proNameLabel;
    QLabel *endLabel;
    QkSearchEditBox *dwTypeQks;
    QLabel *dwNameLabel;
    QDateEdit *sDateEdit1;
    QkSearchEditBox *dwNameQks;
    QkSearchEditBox *proNameQks;
    QDateEdit *eDateEdit;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QToolButton *queryButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *cancelButton;
    QToolButton *chooseButton;
    QTableView *tableView;

    void setFormId(QString s);
    void setDwLableText(QString type,QString name);
    void initTableHead();
    void initData(QList<childItemProperties> dItem,QString dSql);

    
signals:
    
private slots:
    void sQuery();
    void sChoose();
    void sExit();
private:
    void setupUI();
    void retranslateUi();
    void init();

    QSqlQueryModel *sqlQueryModel(QString sql,QVector<QVariant> qvar);
    QList<struct childItemProperties > mDetailChildItem;
    QStandardItemModel *mDetailModel;
    QString mHandleFiled;
    QString mFormId;
    QString mStrDetailSql;
    QString mStrDetailSql2;

    
};

#endif // CHOOSEVOUCHDIALOG_H
