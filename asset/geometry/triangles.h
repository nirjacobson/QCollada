#ifndef QCOLLADA_TRIANGLES_H
#define QCOLLADA_TRIANGLES_H

#include <QMap>
#include <QString>

namespace QCollada {

  class Triangles
  {
    public:

      enum Semantic {
        VERTEX,
        NORMAL,
        TEXCOORD
      };

      Triangles(const int count, const QString& material, const QMap<Semantic, QPair<QString, int>>& inputs, const QList<int>& p);

      const QString& material() const;
      const QMap<Semantic, QPair<QString, int>>& inputs() const;
      const QList<int>& p() const;
      int count() const;

      static QString semanticToString(const Semantic semantic);

    private:
      int _count;
      QString _material;
      QMap<Semantic, QPair<QString, int>> _inputs;
      QList<int> _p;
  };

}

#endif // QCOLLADA_TRIANGLES_H
