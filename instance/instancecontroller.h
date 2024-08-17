#ifndef QCOLLADA_INSTANCECONTROLLER_H
#define QCOLLADA_INSTANCECONTROLLER_H

#include "QCollada_global.h"

#include <QList>

#include "instancematerial.h"
#include "../asset/visualscene/nodeitem.h"

namespace QCollada {

  class QCOLLADA_EXPORT InstanceController : public NodeItem
  {
    public:
      InstanceController(const QString& url, const QString& skeleton, const QList<InstanceMaterial>& instanceMaterials);

      const QString& skeleton() const;
      const QList<InstanceMaterial>& instanceMaterials() const;

    private:
      QString _skeleton;
      QList<InstanceMaterial> _instanceMaterials;
  };

}

#endif // QCOLLADA_INSTANCECONTROLLER_H
