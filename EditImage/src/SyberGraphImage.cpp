#include "SyberGraphImage.h"
#include <QFileDialog>

SyberGraphImage::SyberGraphImage()
{
}

void SyberGraphImage::setImage(const QImage &image)
{
    m_image = image;
}

QImage SyberGraphImage::image() const
{
    return m_image;
}

void SyberGraphImage::paint(QPainter *painter)
{
    painter->save();
    m_pen.setWidth(lineWidth());
    painter->setOpacity(opacity());
    painter->setPen(m_pen);
    painter->setBrush(m_color);
    painter->setRenderHint(QPainter::Antialiasing);
    m_image = m_image.scaled(m_box.size());
    painter->drawImage(m_box, m_image);
    painter->restore();
}
