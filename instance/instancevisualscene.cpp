#include "instancevisualscene.h"

QCollada::InstanceVisualScene::InstanceVisualScene(const QString& url)
  : _url(url)
{

}

const QString& QCollada::InstanceVisualScene::url() const
{
  return _url;
}
