#ifndef QCOLLADA_INSTANCEANIMATION_H
#define QCOLLADA_INSTANCEANIMATION_H

#include "../QCollada_global.h"

#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT InstanceAnimation
  {
    public:
      InstanceAnimation(const QString& url);

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_INSTANCEANIMATION_H
