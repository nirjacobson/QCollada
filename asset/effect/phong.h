#ifndef QCOLLADA_PHONG_H
#define QCOLLADA_PHONG_H

#include "../../QCollada_global.h"

#include <QColor>

namespace QCollada {

  class QCOLLADA_EXPORT Phong
  {
    public:
      Phong(const QColor& emission, const QColor& ambient, const QColor& diffuse, const QColor& specular, const float shininess);

      const QColor& emission() const;
      const QColor& ambient() const;
      const QColor& diffuse() const;
      const QColor& specular() const;
      float shininess() const;

    private:
      QColor _emission;
      QColor _ambient;
      QColor _diffuse;
      QColor _specular;
      float _shininess;
  };

}

#endif // QCOLLADA_PHONG_H
