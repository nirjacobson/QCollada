#ifndef QCOLLADA_INSTANCECAMERA_H
#define QCOLLADA_INSTANCECAMERA_H

#include <QString>

#include "../asset/visualscene/nodeitem.h"

namespace QCollada {

  class InstanceCamera : public NodeItem
  {
    public:
      InstanceCamera(const QString& url);
  };

}

#endif // QCOLLADA_INSTANCECAMERA_H
