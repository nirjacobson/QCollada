#ifndef QCOLLADA_NAMESOURCE_H
#define QCOLLADA_NAMESOURCE_H

#include "QCollada_global.h"

#include <QList>
#include <QString>

#include "source.h"

namespace QCollada {

  class QCOLLADA_EXPORT NameSource : public Source
  {
    public:
      NameSource(const QList<QString>& data, const int count, const Accessor& accessor);

      const QList<QString>& data() const;

    private:
      QList<QString> _data;
  };

}

#endif // QCOLLADA_NAMESOURCE_H
