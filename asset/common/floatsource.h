#ifndef QCOLLADA_FLOATSOURCE_H
#define QCOLLADA_FLOATSOURCE_H

#include <QList>

#include "source.h"

namespace QCollada {

  class FloatSource : public Source
  {
    public:
      FloatSource(const QList<float>& data, const int count, const Accessor& accessor);

      const QList<float>& data() const;

    private:
      QList<float> _data;
  };

}

#endif // QCOLLADA_FLOATSOURCE_H
