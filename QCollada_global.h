#ifndef QCOLLADA_GLOBAL_H
#define QCOLLADA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QCOLLADA_LIBRARY)
#  define QCOLLADA_EXPORT Q_DECL_EXPORT
#else
#  define QCOLLADA_EXPORT Q_DECL_IMPORT
#endif

#endif // QCOLLADA_GLOBAL_H
