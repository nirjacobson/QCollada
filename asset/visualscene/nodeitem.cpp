#include "nodeitem.h"

QCollada::NodeItem::NodeItem(const QString& url)
  : _url(url)
{

}

QCollada::NodeItem::~NodeItem()
{

}

const QString& QCollada::NodeItem::url() const
{
  return _url;
}
