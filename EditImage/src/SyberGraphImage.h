#ifndef SYBERGRAPHIMAGE_H
#define SYBERGRAPHIMAGE_H
#include "SyberGraphRect.h"

class SyberGraphImage : public SyberGraphRect
{
public:
    SyberGraphImage();

    void setImage(const QImage& image);
    QImage image()const;

    // paint
    virtual void paint(QPainter* painter);
private:
    QImage m_image;
};

#endif // SYBERGRAPHIMAGE_H
