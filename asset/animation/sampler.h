#ifndef QCOLLADA_SAMPLER_H
#define QCOLLADA_SAMPLER_H

#include "../../QCollada_global.h"

#include <QMap>
#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT Sampler
  {
    public:

      enum Semantic {
        INPUT,
        OUTPUT,
        INTERPOLATION
      };

      Sampler(const QMap<Semantic, QString>& inputs);

      const QMap<Semantic, QString>& inputs() const;

    private:
      QMap<Semantic, QString> _inputs;
  };

}

#endif // QCOLLADA_SAMPLER_H
