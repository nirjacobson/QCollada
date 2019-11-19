#include "namesource.h"

QCollada::NameSource::NameSource(const QList<QString>& data, const int count, const QCollada::Accessor& accessor)
  : Source(count, accessor)
  , _data(data)
{

}

const QList<QString>& QCollada::NameSource::data() const
{
  return _data;
}
