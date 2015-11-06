#ifndef RPTLIB_GLOBAL_H
#define RPTLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RPTLIB_LIBRARY)
#  define RPTLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RPTLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RPTLIB_GLOBAL_H
