#ifndef SyberGraphDoc_H
#define SyberGraphDoc_H

#include "SyberGraphItem.h"
#include <QObject>

class SyberGraphDoc : public QObject
{
    Q_OBJECT

public:
    SyberGraphDoc(QObject*parent = 0);

    SyberGraphItem* createItem(ItemType type);

    SyberGraphItem* itemAt(const QPoint& pos);

    void append(SyberGraphItem *item);
    void insert(int index, SyberGraphItem *item);
    void replace(int index, SyberGraphItem *item);
    void remove(int index, bool autoDelete = false);
    void move(int from, int to);
    void swap(int index1, int index2);
    int indexOf(SyberGraphItem *item);
    bool exists(SyberGraphItem *item);

    void moveForward(SyberGraphItem *item);
    void moveBack(SyberGraphItem *item);
    void moveToFront(SyberGraphItem *item);
    void moveToBack(SyberGraphItem *item);

    virtual void paint(QPainter* painter);
    virtual void paintActiveState(QPainter* painter);

    virtual void load(QTextStream &ts);
    virtual void save(QTextStream &ts);
    virtual SyberGraphItem* createObject(ItemType type);

public:
    SyberGraphItem* m_pCurItem;
    QList<SyberGraphItem*> m_selectItems;

private:
    QList<SyberGraphItem*> m_childItems;
};

#endif // SyberGraphDoc_H
