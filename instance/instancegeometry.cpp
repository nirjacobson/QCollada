#include "instancegeometry.h"

QCollada::InstanceGeometry::InstanceGeometry(const QString& url, const QList<InstanceMaterial>& instanceMaterials)
  : NodeItem(url)
  , _instanceMaterials(instanceMaterials)
{

}

const QList<QCollada::InstanceMaterial>& QCollada::InstanceGeometry::instanceMaterials() const
{
  return _instanceMaterials;
}
