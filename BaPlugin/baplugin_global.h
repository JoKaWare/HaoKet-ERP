#ifndef BAPLUGIN_GLOBAL_H
#define BAPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BAPLUGIN_LIBRARY)
#  define BAPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BAPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif

#define HAOKE_BA_AREA_STR "001"
#define HAOKE_BA_CUS_STR "002"
#define HAOKE_BA_CUSFORM_STR "003"
#define HAOKE_BA_DEP_STR "004"
#define HAOKE_BA_EMP_STR "005"
#define HAOKE_BA_PRO_STR "006"
#define HAOKE_BA_PROFORM_STR "007"
#define HAOKE_BA_PROTYPE_STR "008"
#define HAOKE_BA_SUP_STR "009"
#define HAOKE_BA_SUPTYPE_STR "010"
#define HAOKE_BA_TYPE_STR "011"
#define HAOKE_BA_WAREHOUSE_STR "012"
#define HAOKE_BA_TASTE_STR "013"
#define HAOKE_BA_POSITION_STR "014"
#define HAOKE_BA_CUSTYPE_STR "015"
#define HAOKE_BA_UNIT_STR "016"
#endif // BAPLUGIN_GLOBAL_H
