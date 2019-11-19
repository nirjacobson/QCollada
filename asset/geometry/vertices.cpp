#include "vertices.h"

QCollada::Vertices::Vertices()
{

}

void QCollada::Vertices::addInput(const Semantic semantic, const QString& source)
{
  _inputs.insert(semantic, source);
}

const QMap<QCollada::Vertices::Semantic, QString>& QCollada::Vertices::inputs() const
{
  return _inputs;
}

QString QCollada::Vertices::semanticToString(QCollada::Vertices::Semantic semantic)
{
  switch (semantic) {
    case QCollada::Vertices::POSITION:
      return "POSITION";
  }
}
