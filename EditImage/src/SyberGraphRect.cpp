#include "SyberGraphRect.h"

SyberGraphRect::SyberGraphRect(QObject *parent):
    SyberGraphItem(parent),
    m_bRound(false),
    m_bBrush(false)
{
}

void SyberGraphRect::setRect(const QRect &rect)
{
    m_box = rect;
}

void SyberGraphRect::setRect(const QPoint &p1, const QPoint &p2)
{
    m_box = QRect(p1, p2);
}

QRect SyberGraphRect::rect() const
{
    return m_box;
}

QPainterPath SyberGraphRect::shape()
{
    QPainterPath path;
    path.addRect(m_box);
    return path;
}

void SyberGraphRect::paint(QPainter *painter)
{
    painter->save();
    painter->setOpacity(opacity());
    painter->setPen(m_pen);
    if(m_bBrush)
        painter->setBrush(m_color);
    painter->setRenderHint(QPainter::Antialiasing);
    if(m_bRound)
        painter->drawRoundedRect(m_box,20,20);
    else
        painter->drawRect(m_box);
    painter->restore();
}

void SyberGraphRect::paintActiveState(QPainter *painter)
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

bool SyberGraphRect::contains(const QPoint &point)
{
    QRect rect = getPointRect();
    rect.moveCenter(point);
    return intersects(rect);
}

int SyberGraphRect::getHandlerCount()
{
    return 8;
}

QCursor SyberGraphRect::getHandleCursor(int nHandle)
{
    Qt::CursorShape id = Qt::ArrowCursor;
    switch (nHandle)
    {
        case 0:
            id = Qt::SizeAllCursor;
            break;
        case 1:
        case 5:
            id = Qt::SizeFDiagCursor;
            break;
        case 2:
        case 6:
            id = Qt::SizeVerCursor;
            break;
        case 3:
        case 7:
            id = Qt::SizeBDiagCursor;
            break;
        case 4:
        case 8:
            id = Qt::SizeHorCursor;
            break;
    }

    return QCursor(id);
}

QPoint SyberGraphRect::getHandle(int nHandle)
{
    double x = 0, y = 0, xCenter, yCenter;

    xCenter = m_box.center().x();
    yCenter = m_box.center().y();

    switch (nHandle)
    {
        case 0:
            x = xCenter;
            y = yCenter;
            break;
        case 1:
            x = m_box.left();
            y = m_box.top();
            break;

        case 2:
            x = xCenter;
            y = m_box.top();
            break;

        case 3:
            x = m_box.right();
            y = m_box.top();
            break;

        case 4:
            x = m_box.right();
            y = yCenter;
            break;

        case 5:
            x = m_box.right();
            y = m_box.bottom();
            break;

        case 6:
            x = xCenter;
            y = m_box.bottom();
            break;

        case 7:
            x = m_box.left();
            y = m_box.bottom();
            break;

        case 8:
            x = m_box.left();
            y = yCenter;
            break;
    }

    return QPoint(x, y);
}

void SyberGraphRect::moveHandleTo(const QPoint &newPos, int index)
{
    switch (index)
    {
        case 0:
            m_box.moveCenter(newPos);
            break;
        case 1:
            m_box.setTopLeft(newPos);
            break;

        case 2:
            m_box.setTop(newPos.y());
            break;

        case 3:
            m_box.setTopRight(newPos);
            break;

        case 4:
            m_box.setRight(newPos.x());
            break;

        case 5:
            m_box.setBottomRight(newPos);
            break;

        case 6:
            m_box.setBottom(newPos.y());
            break;

        case 7:
            m_box.setBottomLeft(newPos);
            break;

        case 8:
            m_box.setLeft(newPos.x());
            break;
        default:
            break;
    }
    m_box = m_box.normalized();
}


SyberGraphRound::SyberGraphRound()
{

}
