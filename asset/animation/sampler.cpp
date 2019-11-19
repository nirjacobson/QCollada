#include "sampler.h"

QCollada::Sampler::Sampler(const QMap<QCollada::Sampler::Semantic, QString>& inputs)
  : _inputs(inputs)
{

}

const QMap<QCollada::Sampler::Semantic, QString>& QCollada::Sampler::inputs() const
{
  return _inputs;
}
