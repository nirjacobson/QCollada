#include "accessor.h"

QCollada::Accessor::Accessor()
{

}

void QCollada::Accessor::addParam(const Param param)
{
  _params.append(param);
}

void QCollada::Accessor::setCount(const int count)
{
  _count = count;
}

void QCollada::Accessor::setStride(const int stride)
{
  _stride = stride;
}

const QList<QCollada::Accessor::Param>& QCollada::Accessor::params() const
{
  return _params;
}

int QCollada::Accessor::count() const
{
  return _count;
}

int QCollada::Accessor::stride() const
{
  return _stride;
}
