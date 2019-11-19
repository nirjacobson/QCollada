#ifndef QCOLLADA_INSTANCEEFFECT_H
#define QCOLLADA_INSTANCEEFFECT_H

#include <QString>

namespace QCollada {

  class InstanceEffect
  {
    public:
      InstanceEffect(const QString& url);

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_INSTANCEEFFECT_H
