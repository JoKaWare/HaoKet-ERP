#ifndef HAOKEAPP_H
#define HAOKEAPP_H
#include "lib_global.h"
#include "version.h"
#include "qsingleapplication.h"
#include "haokegui.h"
#include <QSplashScreen>
#include <QColor>
#include <QMessageBox>
#include <qtextcodec.h>
#include <QTranslator>
#include <QLocale>
#include <QDir>
#include <QPluginLoader>
#include "common/glogin.h"

#include "log4qt/consoleappender.h"
#include "log4qt/logmanager.h"
#include "log4qt/fileappender.h"
#include "log4qt/logger.h"
#include "log4qt/ttcclayout.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/basicconfigurator.h"
#include "common/config.h"
#include "common/netclient.h"
#include "common/dbmanager.h"
#include "HaoKeMenuInterface.h"

class LIBSHARED_EXPORT HaoKeApp : public QSingleApplication
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
        HaoKeApp(int& argc, char **argv);

        virtual ~HaoKeApp();

        static HaoKeApp* initInstance(int& argc, char **argv);
        static HaoKeApp* getInstance();
        static bool writeSysLog(QString accName,QString winTitle, int sub, int winId, QString procName);
        static bool writeSysLog(QString accName,QString log,int sub,int winId,int procId,QString desc);
        static bool writeProcess(QString accName, QString log, int sub, int winId, int procId, QString desc, QString objName);
        HaoKeGUI* gui() const;
        virtual void commitData(QSessionManager& manager);
        virtual void saveState (QSessionManager& manager);
        virtual bool event(QEvent *e);
        virtual int exec();
        int login();
        //

        static int version();
        static QString versionString();
        static QString sysSubId() { return HAOKE_SYS_STR;}
        static QString baSubId() { return HAOKE_BA_STR;}
        static QString mmSubId() { return HAOKE_MM_STR;}
        static QString puSubId() { return HAOKE_PU_STR;}
        static QString stSubId() { return HAOKE_ST_STR;}
        static QString saSubId() { return HAOKE_SA_STR;}
        static QString faSubId() { return HAOKE_FA_STR;}
        static QString posSubId() { return HAOKE_POS_STR;}
        static QString repSubId() { return HAOKE_REP_STR;}
        static QString bcSubId() { return HAOKE_BC_STR;}
        static QString dmSubId() { return HAOKE_DM_STR;}

        static QString getVouchRdPuIn() { return HAOKE_RD_PU_IN_STR;}
        static QString getVouchRdSaOut() { return HAOKE_RD_SA_OUT_STR;}
        static QString getVouchRdInvIn() { return HAOKE_RD_INV_IN_STR;}
        static QString getVouchRdInvOut() { return HAOKE_RD_INV_OUT_STR;}
        static QString getVouchRdOtherIn() { return HAOKE_RD_OTHER_IN_STR;}
        static QString getVouchRdSfOut() { return HAOKE_RD_STUFF_OUT_STR;}
        static QString getVouchRdOtherOut() { return HAOKE_RD_OTHER_OUT_STR;}
        static QString getVouchAllocation() { return HAOKE_ALLOCATION_STR;}
        static QString getVouchRdCntIn() { return HAOKE_RD_CONSIGNMENT_IN_STR;}
        static QString getVouchCheck() { return HAOKE_CHECK_STR;}
        static QString getVouchRdCtOut() { return HAOKE_RD_CONSIGNMENT_OUT_STR;}
        static QString getVouchRdCtRe() { return HAOKE_RD_CONSIGNMENT_RE_STR;}
        static QString getVouchRdPuRe() { return HAOKE_RD_PU_RE_STR;}
        static QString getVouchRdSaRe() { return HAOKE_RD_SA_RE_STR;}
        static QString getVouchPuOrder() { return HAOKE_RD_PU_ORDER_STR;}
        static QString getVouchPuArrival() { return HAOKE_RD_PU_ARRIVAL_STR;}
        static QString getVouchSaOrder() { return HAOKE_RD_SA_ORDER_STR;}
        static QString getVouchSaDelivery() { return HAOKE_RD_SA_DELIVERY_STR;}

        void setAccountName(QString s){ m_accountName = s;}
        void setAccountId(QString s){ m_accountId = s;}
        void setAccountYear(QString s){ m_accountYear = s;}
        void setUserName(QString s){ m_userName = s;}
        void setUserDesc(QString s){ m_userDesc = s;}
        void setPrintTitle(QString s){ m_printTitle = s;}
        void setPrintFooter(QString s){ m_printFooter = s;}
        void setUserLevel(int i){ m_userLevel = i;}
        void setUserId(int i){ m_userId = i;}
        void setOperateDate(QDate date){ m_operate_date = date;}
        QString getAccountName() const{ return m_accountName;}
        QString getAccountId() const{ return m_accountId;}
        QString getAccountYear()const { return m_accountYear;}
        QString getUserName() const{ return m_userName;}
        QString getUserDesc() const{ return m_userDesc;}
        QString getPrintTitle() const{ return m_printTitle;}
        QString getPrintFooter() const{ return m_printFooter;}
        QDate getOperateDate() const{ return m_operate_date;}
        int getUserLevel() const{ return m_userLevel;}
        int getUserId() const{ return m_userId;}
        QList<HaoKeMenuInterface *> getMenuInterfaces(){ return m_menu_interfaces;}

private:
    static HaoKeApp* staticAppInstance;
    QList<HaoKeMenuInterface *> m_menu_interfaces;
    QString m_path;
    void initSys();
    HaoKeGUI *pGUI;
    GLogin  *pLOGIN;
    QString m_accountName;
    QString m_userName;
    QString m_userDesc;
    QString m_accountId;
    QString m_accountYear;
    QDate m_operate_date;
    int m_userId;
    int m_userLevel;

    QString m_printTitle;
    QString m_printFooter;

    void loadPlugins();

};

#endif // HAOKEAPP_H
