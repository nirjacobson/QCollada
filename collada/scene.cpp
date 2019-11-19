#include "scene.h"

QCollada::Scene::Scene(const InstanceVisualScene& instanceVisualScene)
  : _instanceVisualScene(instanceVisualScene)
{

}

const QCollada::InstanceVisualScene& QCollada::Scene::instanceVisualScene() const
{
  return _instanceVisualScene;
}

void QCollada::Scene::setInstanceVisualScene(const QCollada::InstanceVisualScene& instanceVisualScene)
{
  _instanceVisualScene = instanceVisualScene;
}
