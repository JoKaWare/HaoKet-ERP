#ifndef QKSTRINGUTILS_H
#define QKSTRINGUTILS_H
#include <QtCore>
#include "lib_global.h"

class LIBSHARED_EXPORT QkStringUtils
{
public:
    QkStringUtils();
    static QString numberToString(int n,int length);
    static QString getUuid(QString userId,QString id);
    static QString GenerateSpaces(int n);

};

#endif // QKSTRINGUTILS_H
