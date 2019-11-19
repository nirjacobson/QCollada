#ifndef QCOLLADA_SCENE_H
#define QCOLLADA_SCENE_H

#include <QString>

#include "instance/instancevisualscene.h"

namespace QCollada {

  class Scene {
    public:
      Scene(const InstanceVisualScene& instanceVisualScene);

      const InstanceVisualScene& instanceVisualScene() const;
      void setInstanceVisualScene(const InstanceVisualScene& instanceVisualScene);

    private:
      InstanceVisualScene _instanceVisualScene;
  };

}

#endif // QCOLLADA_SCENE_H
