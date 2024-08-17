#ifndef QCOLLADA_CHANNEL_H
#define QCOLLADA_CHANNEL_H

#include "QCollada_global.h"

#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT Channel
  {
    public:
      Channel(const QString& source, const QString& target);

      QString source() const;
      QString target() const;

    private:
      QString _source;
      QString _target;
  };

}

#endif // QCOLLADA_CHANNEL_H
