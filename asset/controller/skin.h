#ifndef QCOLLADA_SKIN_H
#define QCOLLADA_SKIN_H

#include "../../QCollada_global.h"

#include <QString>
#include <QMatrix4x4>

#include "../common/source.h"
#include "joints.h"
#include "vertexweights.h"

namespace QCollada {
  class QCOLLADA_EXPORT Skin
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
      QMap<QString, Source*> _sources;
      Joints _joints;
      VertexWeights _vertexWeights;
  };
}

#endif // QCOLLADA_SKIN_H
