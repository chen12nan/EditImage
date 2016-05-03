#ifndef EPGRAPLINE_H
#define EPGRAPLINE_H

#include <QObject>
#include <QPen>
#include <QLine>
#include "SyberGraphItem.h"

class SyberGraphLine : public SyberGraphItem
{
    Q_OBJECT

public:
    SyberGraphLine(QObject*parent = 0);

    virtual ItemType type();

    void setLine(int x1, int y1, int x2, int y2);
    void setLine(const QPoint& p1, const QPoint& p2);
    QLine line() const;

    virtual void paint(QPainter *painter);
    virtual void paintActiveState(QPainter *painter);
    virtual bool load(QTextStream &ts);
    virtual bool save(QTextStream &ts);

    virtual QPainterPath shape();
    virtual bool intersects(const QRect &rect);
    virtual bool contains(const QPoint &point);
    virtual int getHandlerCount();
    virtual QCursor getHandleCursor(int handle);
    virtual QPoint getHandle(int handle);
    virtual void moveHandleTo(const QPoint& pos, int index = -1);
    virtual void insertHandle(const QPoint& pos, int index = -1);
    virtual void removeHandle(int index = -1);
protected:
    QPen m_pen;
    QLine m_line;
    QColor m_color;
};

#endif // EPGRAPLINE_H
