#ifndef QCOLLADA_VERTEXWEIGHTS_H
#define QCOLLADA_VERTEXWEIGHTS_H

#include <QMap>
#include <QPair>
#include <QString>

namespace QCollada {

  class VertexWeights
  {
    public:

      enum Semantic {
        JOINT,
        WEIGHT
      };

      VertexWeights(const int count, const QList<int>& vcount, const QList<int>& v, const QMap<Semantic, QPair<QString, int>>& inputs);

      int count() const;
      const QList<int>& vcount() const;
      const QList<int>& v() const;
      const QMap<Semantic, QPair<QString, int>>& inputs() const;

    private:
      int _count;
      QList<int> _vcount;
      QList<int> _v;
      QMap<Semantic, QPair<QString, int>> _inputs;
  };

}

#endif // QCOLLADA_VERTEXWEIGHTS_H
