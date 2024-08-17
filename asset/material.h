#ifndef QCOLLADA_MATERIAL_H
#define QCOLLADA_MATERIAL_H

#include "QCollada_global.h"

#include <QString>

#include "asset.h"
#include "../instance/instanceeffect.h"

namespace QCollada {

  class QCOLLADA_EXPORT Material : public Asset
  {
    public:
      Material(const QString& name, const InstanceEffect& instanceEffect);

      const InstanceEffect& instanceEffect() const;
      const QString& name() const;

     private:
      QString _name;
      InstanceEffect _instanceEffect;
  };

}

#endif // QCOLLADA_MATERIAL_H
