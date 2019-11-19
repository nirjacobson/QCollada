#include "material.h"

QCollada::Material::Material(const InstanceEffect& instanceEffect)
  : _instanceEffect(instanceEffect)
{

}

const QCollada::InstanceEffect& QCollada::Material::instanceEffect() const
{
  return _instanceEffect;
}
