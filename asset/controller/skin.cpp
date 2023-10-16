#include "skin.h"

QCollada::Skin::Skin(const QString& source, const QMatrix4x4& bindShapeMatrix, const QMap<QString, Source*>& sources, const Joints& joints, const VertexWeights& vertexWeights)
  : _source(source)
  , _bindShapeMatrix(bindShapeMatrix)
  , _joints(joints)
  , _vertexWeights(vertexWeights)
{
  for (auto it = sources.begin(); it != sources.end(); it++) {
    _sources.insert(it.key(), it.value());
  }
}

const QString& QCollada::Skin::source() const
{
  return _source;
}

const QMatrix4x4& QCollada::Skin::bindShapeMatrix() const
{
  return _bindShapeMatrix;
}

QStringList QCollada::Skin::sources() const
{
  return _sources.keys();
}

const QCollada::Joints& QCollada::Skin::joints() const
{
  return _joints;
}

const QCollada::VertexWeights& QCollada::Skin::vertexWeights() const
{
  return _vertexWeights;
}

const QCollada::Source& QCollada::Skin::getSource(QString url) const
{
  QString id = url.mid(1);
  return *_sources[id];
}
