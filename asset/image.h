#ifndef QCOLLADA_IMAGE_H
#define QCOLLADA_IMAGE_H

#include "../QCollada_global.h"

#include <QString>

#include "asset.h"

namespace QCollada {

  class QCOLLADA_EXPORT Image : public Asset
  {
    public:
      Image(const QString& initFrom);

      const QString& initFrom() const;

    private:
      QString _initFrom;
  };

}

#endif // QCOLLADA_IMAGE_H
