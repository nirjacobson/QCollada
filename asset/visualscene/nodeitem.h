#ifndef QCOLLADA_NODEITEM_H
#define QCOLLADA_NODEITEM_H

#include "../../QCollada_global.h"

#include <QString>

namespace QCollada {

  class QCOLLADA_EXPORT NodeItem
  {
    public:
      NodeItem(const QString& url);
      virtual ~NodeItem();

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_NODEITEM_H
