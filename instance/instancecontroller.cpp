#include "instancecontroller.h"

QCollada::InstanceController::InstanceController(const QString& url, const QString& skeleton, const QList<QCollada::InstanceMaterial>& instanceMaterials)
  : NodeItem(url)
  , _skeleton(skeleton)
  , _instanceMaterials(instanceMaterials)
{

}

const QString& QCollada::InstanceController::skeleton() const
{
  return _skeleton;
}

const QList<QCollada::InstanceMaterial>& QCollada::InstanceController::instanceMaterials() const
{
  return _instanceMaterials;
}
