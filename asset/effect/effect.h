#ifndef QCOLLADA_EFFECT_H
#define QCOLLADA_EFFECT_H

#include "QCollada_global.h"

#include <optional>

#include "../asset.h"
#include "phong.h"
#include "sampler2d.h"

namespace QCollada {

  class QCOLLADA_EXPORT Effect : public Asset
  {
    public:
      Effect(const Phong& phong);
      Effect(const Phong& phong, const Sampler2D& sampler2D);

      const Phong& phong() const;
      const std::optional<Sampler2D>& sampler2D() const;

    private:
      Phong _phong;
      std::optional<Sampler2D> _sampler2D;
  };

}

#endif // QCOLLADA_EFFECT_H
