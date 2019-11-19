#include "mesh.h"

QCollada::Mesh::Mesh(const QMap<QString, Source*>& sources, const Vertices& vertices, const QList<Triangles>& triangles)
  : _vertices(vertices)
  , _triangles(triangles)
{
  for (auto it = sources.begin(); it != sources.end(); it++) {
    _sources.insert(it.key(), std::shared_ptr<Source>(it.value()));
  }
}

const QStringList QCollada::Mesh::sources() const
{
  return _sources.keys();
}

const QCollada::Vertices& QCollada::Mesh::vertices() const
{
  return _vertices;
}

const QList<QCollada::Triangles>& QCollada::Mesh::triangles() const
{
  return _triangles;
}

const QCollada::Source& QCollada::Mesh::getSource(QString url) const
{
  QString id = url.mid(1);
  return *_sources[id];
}
