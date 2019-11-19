#include "channel.h"

QCollada::Channel::Channel(const QString& source, const QString& target)
  : _source(source)
  , _target(target)
{

}

QString QCollada::Channel::source() const
{
  return _source;
}

QString QCollada::Channel::target() const
{
  return _target;
}
