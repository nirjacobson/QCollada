#include "instanceanimation.h"

QCollada::InstanceAnimation::InstanceAnimation(const QString& url)
  : _url(url)
{

}

const QString& QCollada::InstanceAnimation::url() const
{
  return _url;
}
