#include "effect.h"

QCollada::Effect::Effect(const Phong& phong)
  : _phong(phong)
{

}

QCollada::Effect::Effect(const Phong& phong, const Sampler2D& sampler2D)
  : _phong(phong)
  , _sampler2D(sampler2D)
{

}

const QCollada::Phong& QCollada::Effect::phong() const
{
  return _phong;
}

const std::optional<QCollada::Sampler2D>& QCollada::Effect::sampler2D() const
{
  return _sampler2D;
}
