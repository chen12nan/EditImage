#include "SyberGraphItem.h"
#include <QPainter>
#include <QPainterPath>
#include <QRect>
#include <QDebug>

SyberGraphItem::SyberGraphItem(QObject *parent):
    QObject(parent),
    m_color(Qt::transparent)
{
}

ItemType SyberGraphItem::type()
{
    return epNone;
}

void SyberGraphItem::setLineWidth(int value)
{
    m_lineWidth = value;
}

int SyberGraphItem::lineWidth() const
{
    return m_lineWidth;
}

void SyberGraphItem::setOpacity(float value)
{
    m_opacity = value;
}

float SyberGraphItem::opacity() const
{
    return m_opacity;
}

void SyberGraphItem::setPen(const QPen &pen)
{
    m_pen = pen ;
}

QPen SyberGraphItem::pen() const
{
    return m_pen;
}

void SyberGraphItem::setColor(const QColor &color)
{
    m_color = color;
    m_pen.setColor(color);
}

QColor SyberGraphItem::color() const
{
    return m_color;
}

QRect SyberGraphItem::boundingRect() const
{
    return m_box;
}

void SyberGraphItem::setBoundingRect(const QRect &box)
{
    m_box = box;
}

QPainterPath SyberGraphItem::shape()
{
    return QPainterPath();
}

QRect SyberGraphItem::getPointRect()
{
    return QRect(0, 0, 70, 70);
}

void SyberGraphItem::paint(QPainter *painter)
{
    painter->save();
    painter->drawRect(m_box);
    painter->restore();
}

void SyberGraphItem::paintActiveState(QPainter *painter)
{

}

bool SyberGraphItem::load(QTextStream &ts)
{
    return false;
}

bool SyberGraphItem::save(QTextStream &ts)
{
    return false;
}

bool SyberGraphItem::intersects(const QRect &rect)
{
    return shape().intersects(rect);
}

bool SyberGraphItem::contains(const QPoint &point)
{
    return shape().contains(point);
}

int SyberGraphItem::getHandlerCount()
{
    return 0;
}

QCursor SyberGraphItem::getHandleCursor(int handle)
{
    return QCursor(Qt::ArrowCursor);
}

QPoint SyberGraphItem::getHandle(int handle)
{
    return QPoint();
}

void SyberGraphItem::moveHandleTo(const QPoint &pos, int index)
{

}

void SyberGraphItem::insertHandle(const QPoint &pos, int index)
{

}

void SyberGraphItem::removeHandle(int index)
{

}
