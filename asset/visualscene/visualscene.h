#ifndef QCOLLADA_VISUALSCENE_H
#define QCOLLADA_VISUALSCENE_H

#include <QList>

#include "../asset.h"
#include "node.h"

namespace QCollada {

  class VisualScene : public Asset
  {
    public:
      VisualScene();
      ~VisualScene();

      Node* root();
      const Node* root() const;

      const Node* resolve(const QString& url) const;

    private:
      Node* _root;
  };

}

#endif // QCOLLADA_VISUALSCENE_H
