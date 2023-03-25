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

bool QCollada::Node::depthFirst(NodeVisitor visitor)
{
    if (visitor(*this)) {
        return true;
    }

    for (Node* childNode : _children) {
      if (childNode->depthFirst(visitor)) {
          return true;
      }
    }

    return false;
}

bool QCollada::Node::depthFirst(NodeVisitorConst visitor) const
{
    if (visitor(*this)) {
        return true;
    }

    for (const Node* childNode : _children) {
      if (childNode->depthFirst(visitor)) {
          return true;
      }
    }

    return false;
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
