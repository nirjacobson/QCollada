#ifndef QCOLLADA_SAMPLER_H
#define QCOLLADA_SAMPLER_H

#include <QMap>
#include <QString>

namespace QCollada {

  class Sampler
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
