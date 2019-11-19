#ifndef QCOLLADA_PERSPECTIVE_CAMERA_H
#define QCOLLADA_PERSPECTIVE_CAMERA_H

#include "camera.h"

namespace QCollada {

  class PerspectiveCamera : public Camera
  {
    public:
      PerspectiveCamera(const float xfov, const float aspect, const float znear, const float zfar);

      float xfov() const;
      float aspect() const;
      float znear() const;
      float zfar() const;

    private:
      float _xfov;
      float _aspect;
      float _znear;
      float _zfar;
  };

}

#endif // QCOLLADA_PERSPECTIVE_CAMERA_H
