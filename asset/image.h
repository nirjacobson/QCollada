#ifndef QCOLLADA_IMAGE_H
#define QCOLLADA_IMAGE_H

#include <QString>

#include "asset.h"

namespace QCollada {

  class Image : public Asset
  {
    public:
      Image(const QString& initFrom);

      const QString& initFrom() const;

    private:
      QString _initFrom;
  };

}

#endif // QCOLLADA_IMAGE_H
