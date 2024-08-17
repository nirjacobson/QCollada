#ifndef QCOLLADA_ACCESSOR_H
#define QCOLLADA_ACCESSOR_H

#include "QCollada_global.h"

#include <QString>
#include <QList>

namespace QCollada {

  class QCOLLADA_EXPORT Accessor
  {
    public:

      typedef struct {
          enum Type {
            FLOAT,
            FLOAT4X4,
            NAME
          } ;
          QString name;
          Type type;
      } Param;

      Accessor();
      void addParam(const Param param);
      void setCount(const int count);
      void setStride(const int stride);

      const QList<Param>& params() const;
      int count() const;
      int stride() const;

    private:
      QList<Param> _params;
      int _count;
      int _stride;
  };

}

#endif // QCOLLADA_ACCESSOR_H
