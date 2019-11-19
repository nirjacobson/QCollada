#include "vertexweights.h"

QCollada::VertexWeights::VertexWeights(const int count, const QList<int>& vcount, const QList<int>& v, const QMap<QCollada::VertexWeights::Semantic, QPair<QString, int> >& inputs)
  : _count(count)
  , _vcount(vcount)
  , _v(v)
  , _inputs(inputs)
{

}

int QCollada::VertexWeights::count() const
{
  return _count;
}

const QList<int>& QCollada::VertexWeights::vcount() const
{
  return _vcount;
}

const QList<int>& QCollada::VertexWeights::v() const
{
  return _v;
}

const QMap<QCollada::VertexWeights::Semantic, QPair<QString, int> >& QCollada::VertexWeights::inputs() const
{
  return _inputs;
}
