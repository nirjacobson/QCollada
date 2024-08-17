#ifndef QCOLLADA_INSTANCEGEOMETRY_H
#define QCOLLADA_INSTANCEGEOMETRY_H

#include "QCollada_global.h"

#include <QList>
#include <QString>

#include "instancematerial.h"
#include "../asset/visualscene/nodeitem.h"

namespace QCollada {

  class QCOLLADA_EXPORT InstanceGeometry : public NodeItem
  {
    public:
      InstanceGeometry(const QString& url, const QList<InstanceMaterial>& instanceMaterials);

      const QList<InstanceMaterial>& instanceMaterials() const;

    private:
      QList<InstanceMaterial> _instanceMaterials;
  };

}

#endif // QCOLLADA_INSTANCEGEOMETRY_H
