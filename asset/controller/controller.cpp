#include "controller.h"

QCollada::Controller::Controller(const QCollada::Skin& skin)
  : _skin(skin)
{

}

const QCollada::Skin& QCollada::Controller::skin() const
{
  return _skin;
}
