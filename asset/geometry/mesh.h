#ifndef QCOLLADA_MESH_H
#define QCOLLADA_MESH_H

#include "../../QCollada_global.h"

#include <QList>
#include <QMap>
#include <QString>

#include <memory>

#include "../common/source.h"
#include "vertices.h"
#include "triangles.h"

namespace QCollada {

  class QCOLLADA_EXPORT Mesh
  {
    public:
      Mesh(const QMap<QString, Source*>& sources, const Vertices& vertices, const QList<Triangles>& triangles);

      const QStringList sources() const;
      const Vertices& vertices() const;
      const QList<Triangles>& triangles() const;

      const Source& getSource(QString url) const;

    private:
      QMap<QString, Source*> _sources;
      Vertices _vertices;
      QList<Triangles> _triangles;
  };

}

#endif // QCOLLADA_MESH_H
