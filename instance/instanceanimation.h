#ifndef QCOLLADA_INSTANCEANIMATION_H
#define QCOLLADA_INSTANCEANIMATION_H


#include <QString>

namespace QCollada {

  class InstanceAnimation
  {
    public:
      InstanceAnimation(const QString& url);

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_INSTANCEANIMATION_H
