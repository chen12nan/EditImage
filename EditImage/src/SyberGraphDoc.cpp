#include "SyberGraphDoc.h"
#include "SyberGraphLine.h"
#include "SyberGraphRect.h"
#include "SyberGraphString.h"
#include "SyberGraphImage.h"
#include <QTextStream>

SyberGraphDoc::SyberGraphDoc(QObject *parent)
    :QObject(parent),
     m_pCurItem(NULL)
{
}

SyberGraphItem *SyberGraphDoc::createItem(ItemType type)
{
    if(type == epLine)
        return new SyberGraphLine();
    else if(type == epRect)
        return new SyberGraphRect();
    else if(type == epRoundRect)
        return new SyberGraphRound();
    else if(type == epImage)
        return new SyberGraphImage();
    else if(type == epString)
        return new SyberGraphString();
    else
        return NULL;
}

SyberGraphItem *SyberGraphDoc::itemAt(const QPoint &pos)
{
    for (int i = m_childItems.size() - 1; i >= 0; i--) {
        SyberGraphItem *item = m_childItems.at(i);
        if(item->contains(pos))
        {
            return item;
        }
    }
    return NULL;
}

void SyberGraphDoc::append(SyberGraphItem *item)
{
    m_childItems.append(item);
}

void SyberGraphDoc::insert(int index, SyberGraphItem *item)
{
    m_childItems.insert(index, item);
}

void SyberGraphDoc::replace(int index, SyberGraphItem *item)
{
    m_childItems.replace(index, item);
}

void SyberGraphDoc::remove(int index, bool autoDelete)
{
    SyberGraphItem *item = m_childItems.at(index);
    m_childItems.removeAt(index);
    if(autoDelete)
    {
        delete item;
    }
}

void SyberGraphDoc::move(int from, int to)
{
     m_childItems.move(from, to);
}

void SyberGraphDoc::swap(int index1, int index2)
{
    m_childItems.swap(index1, index2);
}

int SyberGraphDoc::indexOf(SyberGraphItem *item)
{
    return m_childItems.indexOf(item);
}

bool SyberGraphDoc::exists(SyberGraphItem *item)
{
    QList<SyberGraphItem *>::iterator iterator;
    for (iterator = m_childItems.begin(); iterator != m_childItems.end(); iterator++) {
        SyberGraphItem *pItem = (*iterator);
        if(pItem == item)
            return true;
    }
    return false;
}

void SyberGraphDoc::moveForward(SyberGraphItem *item)
{
    int index = indexOf(item);
    move(index, index +1);
}

void SyberGraphDoc::moveBack(SyberGraphItem *item)
{
    int index = indexOf(item);
    move(index, index -1);
}

void SyberGraphDoc::moveToFront(SyberGraphItem *item)
{
    int index = indexOf(item);
    move(index, m_childItems.count() - 1);
}

void SyberGraphDoc::moveToBack(SyberGraphItem *item)
{
    int index = indexOf(item);
    move(index, 0);
}

void SyberGraphDoc::paint(QPainter *painter)
{
    foreach (SyberGraphItem* item, m_childItems) {
        item->paint(painter);
    }
}

void SyberGraphDoc::paintActiveState(QPainter *painter)
{
    foreach (SyberGraphItem* item, m_selectItems) {
        item->paintActiveState(painter);
    }
}

void SyberGraphDoc::load(QTextStream &ts)
{
    while(!ts.atEnd())
    {
            int value = -1;
            ts>>value;
            ItemType type = (ItemType)value;
            SyberGraphItem* item = createObject(type);
            if(item)
            {
                item->load(ts);
                append(item);
            }
    }
}

void SyberGraphDoc::save(QTextStream &ts)
{
    foreach (SyberGraphItem* item, m_childItems) {
        ts<<item->type()<<"\n";
        item->save(ts);
    }
}

SyberGraphItem *SyberGraphDoc::createObject(ItemType type)
{
    if(type == epLine)
    {
        return new SyberGraphLine();
    }
    else
    {
        return NULL;
    }
}
