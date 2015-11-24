## 说明
好客来 进销存供应链系统,基于QT跨平台 应用模块插件化，使用postgresql 数据库 可用于商品流通行业

## 依赖
1.Qt 4.8.4 

2.Microsoft Visual C++ Compiler 10.0 

3.wwWidgets 与 log4qt库

## 站点

好客来ERP站点[`www.haokel.com:8083`](http://www.haokel.com:8083)

## 安装包下载

客户端 Setup.exe 文件：[`下载`](http://www.haokel.com:8083/downfile/Setup.exe)

服务端 Setup-Server.exe 文件：[`下载`](http://www.haokel.com:8083/downfile/Setup-Server.exe)

## 安装文档下载

[`好客来ERP安装手册`](http://www.haokel.com:8083/downfile/好客来ERP安装手册.doc)

##编译介绍
BaPlugin 基础资料项目文件夹 BcPlugin 串码管理项目文件夹  CgPlugin 采购管理项目文件夹 CommonFiles 公用组件 

RptDesign 打印报表 SaPlugin 销售管理 StPlugin 库存管理 WFaPlugin 财务核算

lib 底层组件[未开源,有些版权所属问题，但不影响大家业务二次开发]

项目都是在Release版本下编译，如要编译Debug版本，大家可修改各项目下 .pro文件 如下：

win32 {
    #CONFIG(release): LIBS += ../lib/release/parent.lib
    CONFIG(release): LIBS += ../release/commlib.lib ../CommonFiles/lib/log4qt.lib ../CommonFiles/lib/kWidget.lib ../CommonFiles/lib/wwwidgets4.lib
    CONFIG(release):  DESTDIR       = ../release/plugins
    #CONFIG(debug): LIBS += ../debug/commlib.lib ../CommonFiles/lib/log4qtd.lib ../CommonFiles/lib/kWidgetd.lib ../CommonFiles/lib/wwwidgets4d.lib
    #CONFIG(debug): DESTDIR = ../debug/plugins
} 
把release 用#注释掉，把debug 开启

designer 目录下文件是QtCreator 开发所属插件文件【只能用于Qt4.8.4 QtCreator 2.7】,请复制文件到自已QtCreator归属目录designer下

designer\Qt 目录下文件是Qt designer插件所属库文件，请复制到QT安装目录  Qt\bin 下

## 交流群
好客来ERP：[`QQ群:423811442`](http://shang.qq.com/wpa/qunwpa?idkey=42ddfae43805df0af20ea8b616d4156c41e65511443fb3e04fb3c1b3cf410b54)
