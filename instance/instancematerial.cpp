#include "instancematerial.h"

QCollada::InstanceMaterial::InstanceMaterial(const QString& symbol, const QString& target)
  : _symbol(symbol)
  , _target(target)
{

}

const QString& QCollada::InstanceMaterial::symbol() const
{
  return _symbol;
}

const QString& QCollada::InstanceMaterial::target() const
{
  return _target;
}
