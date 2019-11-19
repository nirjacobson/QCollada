#include "pointlight.h"

QCollada::PointLight::PointLight(const QVector3D& color, const float constantAttenuation, const float linearAttenuation, const float quadraticAttenuation)
  : _color(color)
  , _constantAttenuation(constantAttenuation)
  , _linearAttentuation(linearAttenuation)
  , _quadraticAttenuation(quadraticAttenuation)
{

}

const QVector3D& QCollada::PointLight::color() const
{
  return _color;
}

float QCollada::PointLight::constantAttenuation() const
{
  return _constantAttenuation;
}

float QCollada::PointLight::linearAttenuation() const
{
  return _linearAttentuation;
}

float QCollada::PointLight::quadraticAttenuation() const
{
  return _quadraticAttenuation;
}
