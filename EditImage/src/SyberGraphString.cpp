#include "SyberGraphString.h"

SyberGraphString::SyberGraphString(QObject *parent):
    SyberGraphRect(parent)
{
}

void SyberGraphString::setText(const QString &text)
{
    m_text = text;
}

QString SyberGraphString::text() const
{
    return m_text;
}

void SyberGraphString::paint(QPainter *painter)
{
    painter->save();
    m_pen.setWidth(lineWidth());
    painter->setOpacity(opacity());
    painter->setPen(m_pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawText(m_box, Qt::AlignLeft|Qt::TextWordWrap, m_text);
    painter->restore();
}

void SyberGraphString::paintActiveState(QPainter *painter)
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
    painter->drawRect(m_box);
    painter->restore();
}
