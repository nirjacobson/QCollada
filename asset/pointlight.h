#ifndef QCOLLADA_POINT_LIGHT_H
#define QCOLLADA_POINT_LIGHT_H

#include "light.h"

#include <QVector3D>

namespace QCollada {

  class PointLight : public Light
  {
    public:
      PointLight(const QVector3D& color, const float constantAttenuation, const float linearAttenuation, const float quadraticAttenuation);

      const QVector3D& color() const;
      float constantAttenuation() const;
      float linearAttenuation() const;
      float quadraticAttenuation() const;

    private:
      QVector3D _color;
      float _constantAttenuation;
      float _linearAttentuation;
      float _quadraticAttenuation;
  };

}

#endif // QCOLLADA_POINT_LIGHT_H
