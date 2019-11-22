#include "phong.h"

QCollada::Phong::Phong(const QColor& emission, const QColor& ambient, const QColor& diffuse, const QColor& specular, const float shininess)
  : _emission(emission)
  , _ambient(ambient)
  , _diffuse(diffuse)
  , _specular(specular)
  , _shininess(shininess)
{

}

const QColor& QCollada::Phong::emission() const
{
  return _emission;
}

const QColor& QCollada::Phong::ambient() const
{
  return _ambient;
}

const QColor& QCollada::Phong::diffuse() const
{
  return _diffuse;
}

const QColor& QCollada::Phong::specular() const
{
  return _specular;
}

float QCollada::Phong::shininess() const
{
  return _shininess;
}
