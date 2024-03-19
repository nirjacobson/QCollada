#include "material.h"

QCollada::Material::Material(const QString& name, const InstanceEffect& instanceEffect)
    : _name(name)
    , _instanceEffect(instanceEffect)
{

}

const QCollada::InstanceEffect& QCollada::Material::instanceEffect() const
{
    return _instanceEffect;
}

const QString& QCollada::Material::name() const
{
    return _name;
}
