#ifndef QCOLLADA_INSTANCEVISUALSCENE_H
#define QCOLLADA_INSTANCEVISUALSCENE_H

#include "QCollada_global.h"

#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT InstanceVisualScene
  {
    public:
      InstanceVisualScene(const QString& url);

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_INSTANCEVISUALSCENE_H
