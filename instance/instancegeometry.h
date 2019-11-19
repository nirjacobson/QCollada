#ifndef QCOLLADA_INSTANCEGEOMETRY_H
#define QCOLLADA_INSTANCEGEOMETRY_H

#include <QList>
#include <QString>

#include "instancematerial.h"
#include "../asset/visualscene/nodeitem.h"

namespace QCollada {

  class InstanceGeometry : public NodeItem
  {
    public:
      InstanceGeometry(const QString& url, const QList<InstanceMaterial>& instanceMaterials);

      const QList<InstanceMaterial>& instanceMaterials() const;

    private:
      QList<InstanceMaterial> _instanceMaterials;
  };

}

#endif // QCOLLADA_INSTANCEGEOMETRY_H
