#include "perspectivecamera.h"

QCollada::PerspectiveCamera::PerspectiveCamera(const float xfov, const float aspect, const float znear, const float zfar)
  : _xfov(xfov)
  , _aspect(aspect)
  , _znear(znear)
  , _zfar(zfar)
{

}

float QCollada::PerspectiveCamera::xfov() const
{
  return _xfov;
}

float QCollada::PerspectiveCamera::aspect() const
{
  return _aspect;
}

float QCollada::PerspectiveCamera::znear() const
{
  return _znear;
}

float QCollada::PerspectiveCamera::zfar() const
{
  return _zfar;
}
