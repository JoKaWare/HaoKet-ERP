#ifndef PRINTUTILS_H
#define PRINTUTILS_H
#include "lib_global.h"
#include "common.h"
#include <QtGui>
#include <QDomDocument>
class LIBSHARED_EXPORT PrintUtils
{
public:
    PrintUtils();
    static QString makeWinPrintFormatData(QGridLayout *layout,QList<struct childItemProperties > printChildItem,QString title,QString fName);
};

#endif // PRINTUTILS_H
