#ifndef HMI_GLOBAL_H
#define HMI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HMI_LIBRARY)
#  define HMISHARED_EXPORT Q_DECL_EXPORT
#else
#  define HMISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HMI_GLOBAL_H
