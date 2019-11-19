#ifndef QCOLLADA_GEOMETRY_H
#define QCOLLADA_GEOMETRY_H

#include "../asset.h"
#include "mesh.h"

namespace QCollada {

  class Geometry : public Asset
  {
    public:
      Geometry(const Mesh& mesh);

      const Mesh& mesh() const;

    private:
      Mesh _mesh;
  };

}

#endif // QCOLLADA_GEOMETRY_H
