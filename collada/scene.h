#ifndef QCOLLADA_SCENE_H
#define QCOLLADA_SCENE_H

#include "../QCollada_global.h"

#include <QString>

#include "../instance/instancevisualscene.h"

namespace QCollada {

  class QCOLLADA_EXPORT Scene {
    public:
      Scene(const InstanceVisualScene& instanceVisualScene);

      const InstanceVisualScene& instanceVisualScene() const;
      void setInstanceVisualScene(const InstanceVisualScene& instanceVisualScene);

    private:
      InstanceVisualScene _instanceVisualScene;
  };

}

#endif // QCOLLADA_SCENE_H
