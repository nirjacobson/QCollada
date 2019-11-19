#ifndef QCOLLADA_INSTANCEVISUALSCENE_H
#define QCOLLADA_INSTANCEVISUALSCENE_H

#include <QString>

namespace QCollada {

  class InstanceVisualScene
  {
    public:
      InstanceVisualScene(const QString& url);

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_INSTANCEVISUALSCENE_H
