#include "sampler2d.h"

QCollada::Sampler2D::Sampler2D(const QString& source)
  : _source(source)
{

}

const QString& QCollada::Sampler2D::source() const
{
  return _source;
}
