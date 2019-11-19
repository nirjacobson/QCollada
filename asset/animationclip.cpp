#include "animationclip.h"

QCollada::AnimationClip::AnimationClip(const QString& name, const QList<QCollada::InstanceAnimation>& instanceAnimations)
  : _name(name)
  , _instanceAnimations(instanceAnimations)
{

}

const QString& QCollada::AnimationClip::name() const
{
  return _name;
}

const QList<QCollada::InstanceAnimation>& QCollada::AnimationClip::instanceAnimations() const
{
  return _instanceAnimations;
}
