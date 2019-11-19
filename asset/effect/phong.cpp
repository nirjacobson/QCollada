#include "phong.h"

QCollada::Phong::Phong(const QVector4D& emission, const QVector4D& ambient, const QVector4D& diffuse, const QVector4D& specular, const float shininess)
  : _emission(emission)
  , _ambient(ambient)
  , _diffuse(diffuse)
  , _specular(specular)
  , _shininess(shininess)
{

}

const QVector4D& QCollada::Phong::emission() const
{
  return _emission;
}

const QVector4D& QCollada::Phong::ambient() const
{
  return _ambient;
}

const QVector4D& QCollada::Phong::diffuse() const
{
  return _diffuse;
}

const QVector4D& QCollada::Phong::specular() const
{
  return _specular;
}

float QCollada::Phong::shininess() const
{
  return _shininess;
}
