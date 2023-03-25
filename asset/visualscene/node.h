#ifndef QCOLLADA_NODE_H
#define QCOLLADA_NODE_H

#include <QMatrix4x4>

#include "nodeitem.h"

namespace QCollada {
  class Node
  {
    private:
      typedef std::function<bool(Node&)> NodeVisitor;
      typedef std::function<bool(const Node&)> NodeVisitorConst;

    public:
      enum Type {
        NODE,
        JOINT
      };

      Node(const QString& id, const QString& sid, const Type& type, NodeItem* const nodeItem, const QMatrix4x4& transform);
      ~Node();

      const QList<Node*>& children() const;
      void addChild(Node* node);

      bool depthFirst(NodeVisitor visitor);
      bool depthFirst(NodeVisitorConst visitor) const;

      Type type() const;
      const QString& id() const;
      const QString& sid() const;
      const NodeItem* item() const;

      const QMatrix4x4& transform() const;

    private:
      QString _id;
      QString _sid;
      Type _type;
      NodeItem* _item;
      QList<Node*> _children;
      QMatrix4x4 _transform;
  };
}

#endif // QCOLLADA_NODE_H
