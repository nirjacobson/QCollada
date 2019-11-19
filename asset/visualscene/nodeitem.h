#ifndef QCOLLADA_NODEITEM_H
#define QCOLLADA_NODEITEM_H

#include <QString>

namespace QCollada {

  class NodeItem
  {
    public:
      NodeItem(const QString& url);
      virtual ~NodeItem();

      const QString& url() const;

    private:
      QString _url;
  };

}

#endif // QCOLLADA_NODEITEM_H
