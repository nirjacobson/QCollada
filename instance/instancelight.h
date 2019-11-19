#ifndef QCOLLADA_INSTANCELIGHT_H
#define QCOLLADA_INSTANCELIGHT_H

#include <QString>

#include "../asset/visualscene/nodeitem.h"

namespace QCollada {

  class InstanceLight : public NodeItem
  {
    public:
      InstanceLight(const QString& url);
  };

}

#endif // QCOLLADA_INSTANCELIGHT_H
