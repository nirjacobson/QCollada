#ifndef QCOLLADA_INSTANCEMATERIAL_H
#define QCOLLADA_INSTANCEMATERIAL_H

#include <QString>

namespace QCollada {

  class InstanceMaterial
  {
    public:
      InstanceMaterial(const QString& symbol, const QString& target);

      const QString& symbol() const;
      const QString& target() const;

    private:
      QString _symbol;
      QString _target;
  };

}

#endif // IQCOLLADA_NSTANCEMATERIAL_H
