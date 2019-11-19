#include "floatsource.h"

QCollada::FloatSource::FloatSource(const QList<float>& data, const int count, const QCollada::Accessor& accessor)
  : Source(count, accessor)
  , _data(data)
{

}

const QList<float>& QCollada::FloatSource::data() const
{
  return _data;
}
