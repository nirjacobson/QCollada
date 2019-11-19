#ifndef QCOLLADA_CONTROLLER_H
#define QCOLLADA_CONTROLLER_H

#include "../asset.h"
#include "skin.h"

namespace QCollada {

  class Controller : public Asset
  {
    public:
      Controller(const Skin& skin);

      const Skin& skin() const;

    private:
      Skin _skin;
  };

}

#endif // QCOLLADA_CONTROLLER_H
