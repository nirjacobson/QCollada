#include "triangles.h"

QCollada::Triangles::Triangles(const int count, const QString& material, const QMap<QCollada::Triangles::Semantic, QPair<QString, int> >& inputs, const QList<int>& p)
  : _count(count)
  , _material(material)
  , _inputs(inputs)
  , _p(p)
{

}

const QString& QCollada::Triangles::material() const
{
  return _material;
}

const QMap<QCollada::Triangles::Semantic, QPair<QString, int> >& QCollada::Triangles::inputs() const
{
  return _inputs;
}

const QList<int>& QCollada::Triangles::p() const
{
  return _p;
}

int QCollada::Triangles::count() const
{
  return _count;
}

QString QCollada::Triangles::semanticToString(const QCollada::Triangles::Semantic semantic)
{
  switch (semantic) {
    case QCollada::Triangles::VERTEX:
      return "VERTEX";
    case QCollada::Triangles::NORMAL:
      return "NORMAL";
    case QCollada::Triangles::TEXCOORD:
      return "TEXCOORD";
  }
}
