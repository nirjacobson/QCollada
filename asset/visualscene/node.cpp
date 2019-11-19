#include "node.h"

QCollada::Node::Node(const QString& id, const QString& sid, const Type& type, NodeItem* const nodeItem, const QMatrix4x4& transform)
  : _id(id)
  , _sid(sid)
  , _type(type)
  , _item(nodeItem)
  , _transform(transform)
{

}

QCollada::Node::~Node()
{
  delete _item;
  for (const Node* node : _children) {
    delete node;
  }
}

const QList<QCollada::Node*>& QCollada::Node::children() const
{
  return _children;
}

void QCollada::Node::addChild(Node* node)
{
  _children.append(node);
}

const QCollada::NodeItem* QCollada::Node::item() const
{
  return _item;
}

const QMatrix4x4& QCollada::Node::transform() const
{
  return _transform;
}

void QCollada::Node::depthFirst(NodeVisitor visitor)
{
  bool stop = false;
  NodeVisitorStopFn doStop = [&]() {
    stop = true;
  };
  depthFirstOnNode(visitor, *this, doStop, stop);
}

void QCollada::Node::depthFirst(NodeVisitorConst visitor) const
{
  bool stop = false;
  NodeVisitorStopFn doStop = [&]() {
    stop = true;
  };
  depthFirstOnNode(visitor, *this, doStop, stop);
}

QCollada::Node::Type QCollada::Node::type() const
{
  return _type;
}

const QString& QCollada::Node::id() const
{
  return _id;
}

const QString& QCollada::Node::sid() const
{
  return _sid;
}

void QCollada::Node::depthFirstOnNode(NodeVisitor visitor, QCollada::Node& node, NodeVisitorStopFn stopFn, bool& stop)
{
  visitor(node, stopFn);

  for (Node* childNode : node._children) {
    if (stop) return;
    depthFirstOnNode(visitor, *childNode, stopFn, stop);
  }
}

void QCollada::Node::depthFirstOnNode(NodeVisitorConst visitor, const QCollada::Node& node, NodeVisitorStopFn stopFn, bool& stop) const
{
  visitor(node, stopFn);

  for (Node* childNode : node._children) {
    if (stop) return;
    depthFirstOnNode(visitor, *childNode, stopFn, stop);
  }
}
