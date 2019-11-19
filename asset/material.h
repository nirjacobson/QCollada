#ifndef QCOLLADA_MATERIAL_H
#define QCOLLADA_MATERIAL_H

#include <QString>

#include "asset.h"
#include "../instance/instanceeffect.h"

namespace QCollada {

  class Material : public Asset
  {
    public:
      Material(const InstanceEffect& instanceEffect);

      const InstanceEffect& instanceEffect() const;

     private:
      InstanceEffect _instanceEffect;
  };

}

#endif // QCOLLADA_MATERIAL_H
