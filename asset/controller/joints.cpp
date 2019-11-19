#include "joints.h"

QCollada::Joints::Joints()
{

}

void QCollada::Joints::addInput(const Semantic semantic, const QString& source)
{
  _inputs.insert(semantic, source);
}

const QMap<QCollada::Joints::Semantic, QString>& QCollada::Joints::inputs() const
{
  return _inputs;
}
