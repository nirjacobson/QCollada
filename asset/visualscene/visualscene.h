#ifndef QCOLLADA_VISUALSCENE_H
#define QCOLLADA_VISUALSCENE_H

#include "../../QCollada_global.h"

#include <QList>

#include "../asset.h"
#include "node.h"

namespace QCollada {

  class QCOLLADA_EXPORT VisualScene : public Asset
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
