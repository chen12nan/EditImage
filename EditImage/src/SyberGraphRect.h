#ifndef SYBERGRAPHRECT_H
#define SYBERGRAPHRECT_H
#include "SyberGraphItem.h"

class SyberGraphRect : public SyberGraphItem
{
    Q_OBJECT

public:
    SyberGraphRect(QObject*parent = 0);
    virtual ItemType type(){ return epRect;}

    void setRect(const QRect& rect);
    void setRect(const QPoint& p1, const QPoint& p2);
    QRect rect() const;

    void setRoundFlag(bool flag) { m_bRound = flag;}
    // paint
    virtual void paint(QPainter* painter);
    virtual void paintActiveState(QPainter* painter);

    virtual QPainterPath shape();
    virtual bool contains(const QPoint &point);
    virtual int getHandlerCount();
    virtual QCursor getHandleCursor(int handle);
    virtual QPoint getHandle(int handle);
    virtual void moveHandleTo(const QPoint& pos, int index = -1);

private:
    bool m_bRound;
};

class SyberGraphRound : public SyberGraphRect
{
public:
    SyberGraphRound();
    virtual ItemType type(){ return epRoundRect;}
};

#endif // SYBERGRAPHRECT_H
