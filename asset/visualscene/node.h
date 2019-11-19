#ifndef QCOLLADA_NODE_H
#define QCOLLADA_NODE_H

#include <QMatrix4x4>

#include "nodeitem.h"

namespace QCollada {

  class Node
  {
    private:
      typedef std::function<void(void)> NodeVisitorStopFn;
      typedef std::function<void(Node&, NodeVisitorStopFn)> NodeVisitor;
      typedef std::function<void(const Node&, NodeVisitorStopFn)> NodeVisitorConst;

    public:
      enum Type {
        NODE,
        JOINT
      };

      Node(const QString& id, const QString& sid, const Type& type, NodeItem* const nodeItem, const QMatrix4x4& transform);
      ~Node();

      const QList<Node*>& children() const;
      void addChild(Node* node);

      void depthFirst(NodeVisitor visitor);
      void depthFirst(NodeVisitorConst visitor) const;

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

      void depthFirstOnNode(NodeVisitor visitor, Node& node, NodeVisitorStopFn stopFn, bool& stop);
      void depthFirstOnNode(NodeVisitorConst visitor, const Node& node, NodeVisitorStopFn stopFn, bool& stop) const;
  };

}

#endif // QCOLLADA_NODE_H
