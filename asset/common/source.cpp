#include "source.h"

QCollada::Source::Source(const int count, const QCollada::Accessor& accessor)
  : _count(count)
  , _accessor(accessor)
{

}

int QCollada::Source::count() const
{
  return _count;
}

const QCollada::Accessor& QCollada::Source::accessor() const
{
  return _accessor;
}
