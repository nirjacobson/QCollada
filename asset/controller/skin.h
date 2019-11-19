#ifndef QCOLLADA_SKIN_H
#define QCOLLADA_SKIN_H

#include <QString>
#include <QMatrix4x4>

#include "../common/source.h"
#include "joints.h"
#include "vertexweights.h"

namespace QCollada {
  class Skin
  {
    public:
      Skin(const QString& source, const QMatrix4x4& bindShapeMatrix, const QMap<QString, Source*>& sources, const Joints& joints, const VertexWeights& vertexWeights);

      const QString& source() const;
      const QMatrix4x4& bindShapeMatrix() const;
      QStringList sources() const;
      const Joints& joints() const;
      const VertexWeights& vertexWeights() const;

      const Source& getSource(QString url) const;

    private:
      QString _source;
      QMatrix4x4 _bindShapeMatrix;
      QMap<QString, std::shared_ptr<Source>> _sources;
      Joints _joints;
      VertexWeights _vertexWeights;
  };
}

#endif // QCOLLADA_SKIN_H
