#ifndef QCOLLADA_INSTANCEEFFECT_H
#define QCOLLADA_INSTANCEEFFECT_H

#include "../QCollada_global.h"

#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT InstanceEffect
  {
    public:
      InstanceEffect(const QString& url);

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_INSTANCEEFFECT_H
