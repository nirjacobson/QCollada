#include "visualscene.h"

QCollada::VisualScene::VisualScene()
  : _root(new Node("", "", Node::Type::NODE, nullptr, QMatrix4x4()))
{

}

QCollada::VisualScene::~VisualScene()
{
  delete _root;
}

QCollada::Node* QCollada::VisualScene::root()
{
  return _root;
}

const QCollada::Node* QCollada::VisualScene::root() const
{
  return _root;
}

const QCollada::Node* QCollada::VisualScene::resolve(const QString& url) const
{
  QString id = url.mid(1);

  const Node* node = nullptr;
  _root->depthFirst([&id, &node](const Node& sceneNode){
    if (sceneNode.id() == id) {
      node = &sceneNode;
      return true;
    }
    return false;
  });

  return node;
}

