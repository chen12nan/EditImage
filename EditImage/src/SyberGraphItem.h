#ifndef SyberGraphItem_H
#define SyberGraphItem_H

#include <QPainter>
#include <QCursor>
#include <QObject>

class QTextStream;
class QRect;

enum ItemType
{
    epNone,
    epLine,
    epRect,
    epRoundRect,
    epImage,
    epString
};

class SyberGraphItem : public QObject
{
    Q_OBJECT

public:
    SyberGraphItem(QObject*parent = 0);

    virtual ItemType type();

    void setLineWidth(int value);
    int lineWidth() const;

    void setOpacity(float value);
    float opacity() const;

    void setPen(const QPen& pen);
    QPen pen() const;

    void setColor(const QColor& color);
    QColor color() const;

    QRect boundingRect() const;
    void setBoundingRect(const QRect& box);

    virtual QPainterPath shape();

    QRect getPointRect();

    // paint
    virtual void paint(QPainter* painter);
    virtual void paintActiveState(QPainter* painter);

    // read and save data
    virtual bool load(QTextStream &ts);
    virtual bool save(QTextStream& ts);

    // operator graph
    virtual bool intersects(const QRect &rect);
    virtual bool contains(const QPoint &point);
    virtual int getHandlerCount();
    virtual QCursor getHandleCursor(int handle);
    virtual QPoint getHandle(int handle);
    virtual void moveHandleTo(const QPoint& pos, int index = -1);
    virtual void insertHandle(const QPoint& pos, int index = -1);
    virtual void removeHandle(int index = -1);

protected:
    QRect m_box;
    QPen m_pen;
    QColor m_color;
    int m_lineWidth;
    float m_opacity;
};

#endif // SyberGraphItem_H
