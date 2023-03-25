#ifndef SOURCE_H
#define SOURCE_H

#include "accessor.h"

namespace QCollada {

  class Source
  {
    public:
      Source(const int count, const Accessor& accessor);
      virtual ~Source() { }

      int count() const;
      const Accessor& accessor() const;

    private:
      int _count;
      Accessor _accessor;
  };

}

#endif // SOURCE_H
