#ifndef QCOLLADA_PHONG_H
#define QCOLLADA_PHONG_H

#include <QVector4D>

namespace QCollada {

  class Phong
  {
    public:
      Phong(const QVector4D& emission, const QVector4D& ambient, const QVector4D& diffuse, const QVector4D& specular, const float shininess);

      const QVector4D& emission() const;
      const QVector4D& ambient() const;
      const QVector4D& diffuse() const;
      const QVector4D& specular() const;
      float shininess() const;

    private:
      QVector4D _emission;
      QVector4D _ambient;
      QVector4D _diffuse;
      QVector4D _specular;
      float _shininess;
  };

}

#endif // QCOLLADA_PHONG_H
