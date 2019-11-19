#include "geometry.h"

QCollada::Geometry::Geometry(const Mesh& mesh)
  : _mesh(mesh)
{

}

const QCollada::Mesh& QCollada::Geometry::mesh() const
{
  return _mesh;
}
