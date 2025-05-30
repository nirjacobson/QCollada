#ifndef QCOLLADA_ANIMATION_H
#define QCOLLADA_ANIMATION_H

#include "../../QCollada_global.h"

#include <QMap>
#include <QString>

#include <memory>

#include "../common/source.h"
#include "../asset.h"
#include "sampler.h"
#include "channel.h"

namespace QCollada {

  class QCOLLADA_EXPORT Animation : public Asset
  {
    public:
      Animation(const QMap<QString, Source*>& sources, const Sampler& sampler, const Channel& channel);

      QStringList sources() const;
      const Source& getSource(QString url) const;
      const Sampler& sampler() const;
      const Channel& channel() const;

    private:
      QMap<QString, Source*> _sources;
      Sampler _sampler;
      Channel _channel;
  };

}

#endif // QCOLLADA_ANIMATION_H
