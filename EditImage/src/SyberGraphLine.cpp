#include "SyberGraphLine.h"
#include <QDebug>
#include <QTextStream>

SyberGraphLine::SyberGraphLine(QObject *parent)
    :SyberGraphItem(parent)
{
}

ItemType SyberGraphLine::type()
{
    return epLine;
}

void SyberGraphLine::setLine(int x1, int y1, int x2, int y2)
{
    m_line.setLine(x1, y1, x2, y2);
}

void SyberGraphLine::setLine(const QPoint &p1, const QPoint &p2)
{
    m_line.setPoints(p1,p2);
}

QLine SyberGraphLine::line() const
{
    return m_line;
}

void SyberGraphLine::paint(QPainter *painter)
{
    painter->save();
    painter->setOpacity(opacity());
    painter->setPen(m_pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawLine(m_line);
    painter->restore();
}

void SyberGraphLine::paintActiveState(QPainter *painter)
{
    painter->save();
    QPen pen;
    pen.setColor(Qt::red);
//    painter->setRenderHint(Q);
    painter->setPen(pen);
    for(int i = 0; i<=getHandlerCount(); i++)
    {
        QRect rect = getPointRect();
        rect.moveCenter(getHandle(i));
        painter->drawRect(rect);
    }
    painter->restore();
}

bool SyberGraphLine::load(QTextStream &ts)
{
    int pw = 0;
    QString color;
    ts>>pw>>color;
    m_pen.setWidth(pw);
    m_pen.setColor(color);

    int x, y, x1, y1;
    ts>>x>>y>>x1>>y1;
    m_line.setLine(x, y, x1, y1);
}

bool SyberGraphLine::save(QTextStream &ts)
{
    ts<<m_pen.width()<<"\n";
    ts<<m_pen.color().name()<<"\n";
    ts<<m_line.p1().x()<<"\n";
    ts<<m_line.p1().y()<<"\n";
    ts<<m_line.p2().x()<<"\n";
    ts<<m_line.p2().y()<<"\n";
}

QPainterPath SyberGraphLine::shape()
{
    QPainterPath path;
    path.moveTo(m_line.p1());
    path.lineTo(m_line.p2());

    return path;
}

bool SyberGraphLine::intersects(const QRect &rect)
{
    return false;
}

bool SyberGraphLine::contains(const QPoint &point)
{
    QRect rect = getPointRect();
    rect.moveCenter(point);
    return shape().intersects(rect);
}

int SyberGraphLine::getHandlerCount()
{
    return 2;
}

QCursor SyberGraphLine::getHandleCursor(int handle)
{
    if(handle == 0)
        return QCursor(Qt::SizeAllCursor);
    else
        return QCursor(Qt::CrossCursor);
}

QPoint SyberGraphLine::getHandle(int handle)
{
    QPoint pos;
    switch(handle)
    {
    case 0:
        pos = m_line.p1() + m_line.p2();
        pos /= 2;
        break;

    case 1:
        pos = m_line.p1();
        break;

    case 2:
        pos = m_line.p2();
        break;
    }
    return pos;
}

void SyberGraphLine::moveHandleTo(const QPoint &pos, int index)
{
    switch(index)
    {
    case 0:
       {
            QPoint center = (m_line.p1() + m_line.p2())/2;
            QPoint delta = pos - center;
            m_line.translate(delta);
            break;
        }
    case 1:
        m_line.setP1(pos);
        break;
    case 2:
        m_line.setP2(pos);
        break;
    }
}

void SyberGraphLine::insertHandle(const QPoint &pos, int index)
{

}

void SyberGraphLine::removeHandle(int index)
{

}
