#ifndef QCOLLADA_SAMPLER2D_H
#define QCOLLADA_SAMPLER2D_H

#include "QCollada_global.h"

#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT Sampler2D
  {
    public:
      Sampler2D(const QString& source);

      const QString& source() const;

    private:
      QString _source;
  };

}

#endif // QCOLLADA_SAMPLER2D_H
