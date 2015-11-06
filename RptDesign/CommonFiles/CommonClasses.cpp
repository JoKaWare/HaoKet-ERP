#include "CommonClasses.h"

QString double2MoneyUKR(double n) {
    static QString cap[4][10] =	{
        {
            "",
            "один ",
            "два ",
            "три ",
            "чотири ",
            "п'ять ",
            "шість ",
            "сім ",
            "вісім ",
            "дев'ять "
        },
        {
            "",
            "одна ",
            "дві ",
            "три ",
            "чотири ",
            "п'ять ",
            "шість ",
            "сім ",
            "вісім ",
            "дев'ять "
        },
        {
            "",
            "",
            "двадцять ",
            "тридцять ",
            "сорок ",
            "п'ятдесят ",
            "шістдесят ",
            "сімдесят ",
            "вісімдесят ",
            "дев'яносто "
        },
        {
            "",
            "сто ",
            "двісти ",
            "триста ",
            "чотириста ",
            "п'ятсот ",
            "шістсот ",
            "сімсот ",
            "вісімсот ",
            "дев'ятсот "
        }
    };

    static QString cap2[10] = {
        "десять ",
        "одинадцять ",
        "дванадцять ",
        "тринадцять ",
        "чотирнадцять ",
        "п'ятнадцять ",
        "шістнадцять ",
        "сімнадцять ",
        "вісімнадцять ",
        "дев'ятнадцять "
    };

    static QString cap3[5][3] = {
        {
            "копійка ",
            "копійки ",
            "копійок "
        },
        {
            "гривня, ",
            "гривні, ",
            "гривень, "
        },
        {
            "тисяча ",
            "тисячі ",
            "тисяч "
        },
        {
            "мілльон ",
            "мильони ",
            "мільонів "
        },
        {
            "мілліард ",
            "мільярди ",
            "мільярдів "
        }
    };

    QString s;

    long nn = ((int)(n)*10000 + (int)(n*1000) % 1000 + 5 ) / 10;

    long lo = 0;
    long hi = nn;
    int r[3];
    int rod;

    for ( int nPor = 0; true; ++nPor ) {
        QString olds = s;
        s = "";

        lo = hi%1000;
        hi = hi/1000;

        if ((nPor == 1) && (lo == 0) && (hi == 0)) {
            s = "ноль " + cap3[1][2] + olds;
            break;
        }

        for ( int nRaz = 0; nRaz < 3; ++nRaz ) {
            r[nRaz] = lo%10;
            lo      = lo/10;
        }

        switch ( nPor ) {
            case 0:
            case 1:
            case 2:
                rod = 1;
                break;
            default:
                rod = 0;
        }

        QString capt;
        if (r[1] != 1) {
            if (r[0] == 1)
                capt = cap3[nPor][0];
            else if ((r[0] > 1 ) && (r[0] < 5))
                capt = cap3[nPor][1];
        }
        if (capt.isEmpty())
            capt = cap3[nPor][2];

        if (nPor == 0) {
            s = QString::number(r[1]) + QString::number(r[0]) + " " + capt;
            continue;
        }

        s += cap[2+1][r[2]];
        s += ((r[1] == 1) ? cap2[r[0]] : cap[1+1][r[1]]+cap[0+rod][r[0]])+capt;
        s += olds;

        if ((hi == 0) && (nPor >= 1))
            break;
    }
    QString up(s[0]);
    s.replace(0,1,up);
    return s;
}

QString double2MoneyRUS(double n, int currency) {
    QString v1,v2,v3,s1,s2,s3;
    switch(currency) {
        case 1: {  //ГРИВНА
            v1 = QString::fromUtf8("гривна, ");
            v2 = QString::fromUtf8("гривны, ");
            v3 = QString::fromUtf8("гривен, ");
            s1 = QString::fromUtf8("одна ");
            s2 = QString::fromUtf8("две ");
            break;
        }
        case 2: {  //РУБЛЬ
            v1 = QString::fromUtf8("рубль, ");
            v2 = QString::fromUtf8("рубля, ");
            v3 = QString::fromUtf8("рублей, ");
            s1 = QString::fromUtf8("один ");
            s2 = QString::fromUtf8("два ");
            break;
        }
    }

    if ( n > 999999999999.99 )
        return QString::fromUtf8("Очень много денег ...");

    static QString cap[4][10] = {
        {
            "",
            s1,
            s2,
            s3,
            QString::fromUtf8("четыре "),
            QString::fromUtf8("пять "),
            QString::fromUtf8("шесть "),
            QString::fromUtf8("семь "),
            QString::fromUtf8("восемь "),
            QString::fromUtf8("девять ")
        },
        {
            "",
            QString::fromUtf8("одна "),
            QString::fromUtf8("две "),
            QString::fromUtf8("три "),
            QString::fromUtf8("четыре "),
            QString::fromUtf8("пять "),
            QString::fromUtf8("шесть "),
            QString::fromUtf8("семь "),
            QString::fromUtf8("восемь "),
            QString::fromUtf8("девять ")
        },
        {
            "",
            "",
            QString::fromUtf8("двадцать "),
            QString::fromUtf8("тридцать "),
            QString::fromUtf8("сорок "),
            QString::fromUtf8("пятьдесят "),
            QString::fromUtf8("шестьдесят "),
            QString::fromUtf8("семьдесят "),
            QString::fromUtf8("восемьдесят "),
            QString::fromUtf8("девяносто ")
        },
        {
            "",
            QString::fromUtf8("сто "),
            QString::fromUtf8("двести "),
            QString::fromUtf8("триста "),
            QString::fromUtf8("четыреста "),
            QString::fromUtf8("пятьсот "),
            QString::fromUtf8("шестьсот "),
            QString::fromUtf8("семьсот "),
            QString::fromUtf8("восемьсот "),
            QString::fromUtf8("девятьсот ")
        }
    };

    static QString cap2[10] = {
        QString::fromUtf8("десять "),
        QString::fromUtf8("одиннадцать "),
        QString::fromUtf8("двенадцать "),
        QString::fromUtf8("тринадцать "),
        QString::fromUtf8("четырнадцать "),
        QString::fromUtf8("пятнадцать "),
        QString::fromUtf8("шестнадцать "),
        QString::fromUtf8("семнадцать "),
        QString::fromUtf8("восемнадцать "),
        QString::fromUtf8("девятнадцать ")
    };

    static QString cap3[5][3] = {
        {
            QString::fromUtf8("копейка "),
            QString::fromUtf8("копейки "),
            QString::fromUtf8("копеек ")
        },
        {
            v1,
            v2,
            v3
        },
        {
            QString::fromUtf8("тысяча "),
            QString::fromUtf8("тысячи "),
            QString::fromUtf8("тысяч ")
        },
        {
            QString::fromUtf8("миллион "),
            QString::fromUtf8("милиона "),
            QString::fromUtf8("миллионов ")
        },
        {
            QString::fromUtf8("миллиард "),
            QString::fromUtf8("миллиарда "),
            QString::fromUtf8("миллиардов ")
        }
    };

    QString s;

    qlonglong nn = ((qlonglong)(n)*10000 + (qlonglong)(n*1000) % 1000 + 5 ) / 10;

    qlonglong lo = 0;
    qlonglong hi = nn;
    int r[3];
    int rod;

    for ( int nPor = 0; true; ++nPor ) {
        QString olds = s;
        s = "";

        lo = hi%1000;
        hi = hi/1000;

        if ((nPor == 1) && (lo == 0) && (hi == 0)) {
            s = QString::fromUtf8("ноль ") + cap3[1][2] + olds;
            break;
        }

        for ( int nRaz = 0; nRaz < 3; ++nRaz ) {
            r[nRaz] = lo%10;
            lo      = lo/10;
        }

        switch ( nPor ) {
            case 0:
            case 1:
            case 2:
                rod = 1;
                break;
            default:
                rod = 0;
        }

        QString capt;
        if (r[1] != 1) {
            if (r[0] == 1)
                capt = cap3[nPor][0];
            else if ((r[0] > 1 ) && (r[0] < 5))
                capt = cap3[nPor][1];
        }
        if (capt.isEmpty())
            capt = cap3[nPor][2];

        if (nPor == 0) {
            s = QString::number(r[1]) + QString::number(r[0]) + " " + capt;
            continue;
        }
        if (nPor == 1)
            rod = 0;

        s += cap[2+1][r[2]];
        s += ((r[1] == 1) ? cap2[r[0]] : cap[1+1][r[1]]+cap[0+rod][r[0]])+capt;
        s += olds;

        if ((hi == 0) && (nPor >= 1))
            break;
    }
    QString up(s[0]);
    s.replace(0,1,up);
    if ( n < 0 )
        return QString::fromUtf8("Минус ")+s;
    return s;
}
