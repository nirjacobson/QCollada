#ifndef QCOLLADA_INSTANCECAMERA_H
#define QCOLLADA_INSTANCECAMERA_H

#include "../QCollada_global.h"

#include <QString>

#include "../asset/visualscene/nodeitem.h"

namespace QCollada {

  class QCOLLADA_EXPORT InstanceCamera : public NodeItem
  {
    public:
      InstanceCamera(const QString& url);
  };

}

#endif // QCOLLADA_INSTANCECAMERA_H
