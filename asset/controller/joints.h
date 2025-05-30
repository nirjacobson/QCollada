#ifndef QCOLLADA_JOINTS_H
#define QCOLLADA_JOINTS_H

#include "../../QCollada_global.h"

#include <QMap>
#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT Joints
  {
    public:

      enum Semantic {
        JOINT,
        INV_BIND_MATRIX
      };

      void addInput(const Semantic semantic, const QString& source);

      const QMap<Semantic, QString>& inputs() const;

      Joints();

    private:
      QMap<Semantic, QString> _inputs;
  };

}

#endif // QCOLLADA_JOINTS_H
