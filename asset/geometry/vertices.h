#ifndef QCOLLADA_VERTICES_H
#define QCOLLADA_VERTICES_H

#include "QCollada_global.h"

#include <QMap>
#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT Vertices
  {
    public:
      Vertices();

      enum Semantic {
        POSITION
      };

      void addInput(const Semantic semantic, const QString& source);

      const QMap<Semantic, QString>& inputs() const;

      static QString semanticToString(Semantic semantic);

    private:
      QMap<Semantic, QString> _inputs;
  };

}

#endif // QCOLLADA_VERTICES_H
