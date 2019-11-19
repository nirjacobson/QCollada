#ifndef QCOLLADA_ANIMATIONCLIP_H
#define QCOLLADA_ANIMATIONCLIP_H

#include <QList>

#include "asset.h"
#include "instance/instanceanimation.h"

namespace QCollada {

  class AnimationClip : public Asset
  {
    public:
      AnimationClip(const QString& name, const QList<InstanceAnimation>& instanceAnimations);

      const QString& name() const;
      const QList<InstanceAnimation>& instanceAnimations() const;

    private:
      QString _name;
      QList<InstanceAnimation> _instanceAnimations;
  };

}

#endif // QCOLLADA_ANIMATIONCLIP_H
