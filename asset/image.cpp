#include "image.h"


QCollada::Image::Image(const QString& initFrom)
  : _initFrom(initFrom)
{

}

const QString& QCollada::Image::initFrom() const
{
  return _initFrom;
}
