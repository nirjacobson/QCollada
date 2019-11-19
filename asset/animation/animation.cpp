#include "animation.h"

QCollada::Animation::Animation(const QMap<QString, QCollada::Source*>& sources, const QCollada::Sampler& sampler, const QCollada::Channel& channel)
  : _sampler(sampler)
  , _channel(channel)
{
  for (auto it = sources.begin(); it != sources.end(); it++) {
    _sources.insert(it.key(), std::shared_ptr<Source>(it.value()));
  }
}

QStringList QCollada::Animation::sources() const
{
  return _sources.keys();
}

const QCollada::Source& QCollada::Animation::getSource(QString url) const
{
  QString id = url.mid(1);
  return *_sources[id];
}

const QCollada::Sampler& QCollada::Animation::sampler() const
{
  return _sampler;
}

const QCollada::Channel& QCollada::Animation::channel() const
{
  return _channel;
}
