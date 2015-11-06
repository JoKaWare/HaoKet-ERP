#ifndef COMMON_H
#define COMMON_H
#include <QMenu>
#include <QString>
#include <QToolBar>
#include <QPixmap>
#include <QIcon>

struct actionProperties {
  const char*		actionName;
  const QString     actionTitle;
  const char*		slot;
  QMenu*            menu;
  QString           priv;
  QPixmap           pixmap;
  QToolBar*         toolBar;
  bool              visible;
  const QString     toolTip;
  const QString     menuId;
};

struct childItemProperties{
    QString name;
    QString cnName;
    QString title;
    const int id;
    const int width;
    bool visible;
    bool isEdit;
};

enum gEditFlag {
    joinFlag= 0x0,
    addFlag = 0x1,
    editFlag= 0x2,
    standeFlag= 0x3
};
enum SaleFlag{
    waitFlag = 0x0,     //等待
    orderFlag = 0x01,   //下单
    supsendFlag = 0x02, //挂起
    makeFlag = 0x03,    //制作
    urgeFlag = 0x04,    //催菜
    outFlag = 0x05,     //出菜
    onFlag = 0x06,      //上菜
    endFlag = 0x08,     //结束 已结算
    cancelFlag = 0x09   //取消

};


enum RdFlag{
    RdInFlag = 0x01,     //入库
    RdOutFlag = 0x02
};
enum VouchTypeFlag{
    VouchInFlag = 0x01,     //入库
    VouchOutFlag = 0x02,
    VouchRePuFlag = 0x14
};
#endif // COMMON_H
