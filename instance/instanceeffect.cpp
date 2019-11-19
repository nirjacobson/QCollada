#include "instanceeffect.h"

QCollada::InstanceEffect::InstanceEffect(const QString& url)
  : _url(url)
{

}

const QString& QCollada::InstanceEffect::url() const
{
  return _url;
}
