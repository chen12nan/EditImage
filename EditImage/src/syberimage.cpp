#include "syberimage.h"
#include <QPainter>

SyberImage::SyberImage():
    m_curLineWidth(1),
    m_curOpacity(10),
    m_pDoc(new SyberGraphDoc()),
    m_bPress(NULL),
    m_nDragHandle(-1),
    m_eTool(opLineTool),
    m_focusLine(QLine()),
    m_focusRect(QRect())
{
    m_tools[opLineTool] = new SyberLineTool();
    m_tools[opEditTool] = new SyberEditTool();
    m_tools[opRectTool] = new SyberRectTool();
    m_tools[opRoundTool] = new SyberRoundTool();
    m_tools[opImageTool] = new SyberImageTool();
    m_tools[opStringTool] = new SyberStringTool();
}

void SyberImage::mousePress(const QPoint& pos)
{
    m_bPress = true;
    m_beginPoint = pos;
    m_endPoint = pos;
    m_focusLine.setPoints(m_beginPoint, m_endPoint);
    m_focusRect = QRect(m_beginPoint, m_endPoint);

    m_tools[m_eTool]->mousePress(this, pos);
    update();
    qDebug()<<pos;
}

void SyberImage::mouseMouse(const QPoint& pos)
{
    m_endPoint = pos;
    if(m_bPress)
    {
        m_focusLine.setPoints(m_beginPoint, m_endPoint);
        m_focusRect = QRect(m_beginPoint, m_endPoint);
    }

    m_tools[m_eTool]->mouseMove(this, pos);
    update();
}

void SyberImage::mouseRelease(const QPoint& pos)
{
    m_bPress = false;
    m_focusLine = QLine();
    m_focusRect = QRect();

    m_tools[m_eTool]->mouseRelease(this, pos);
    update();
}

void SyberImage::mouseDoubleClick(const QPoint& pos)
{
    qDebug()<<Q_FUNC_INFO;
    m_tools[m_eTool]->mouseDoubleClick(this, pos);
}

void SyberImage::setDoc(SyberGraphDoc *doc)
{
    if(m_pDoc == doc)
        return;

    if(!m_pDoc)
    {
        m_pDoc = doc;
        update();
    }
}

SyberGraphDoc *SyberImage::getDoc()
{
    return m_pDoc;
}

int SyberImage::lineWidth() const
{
    return m_curLineWidth;
}

int SyberImage::opacity() const
{
    return m_curOpacity;
}

void SyberImage::setOperatorTool(OperatorTool tool)
{
    m_eTool = tool;
    if(m_eTool != opEditTool)
    {
        m_pDoc->m_selectItems.clear();
        update();
    }
}

OperatorTool SyberImage::operatorTool()
{
    return m_eTool;
}

QColor SyberImage::color() const
{

}

void SyberImage::drawBackground(QPainter *painter)
{

}

void SyberImage::drawForeground(QPainter *painter)
{

}

void SyberImage::sendHitItem(SyberGraphItem *item)
{

}

void SyberImage::paint(QPainter *painter)
{
    painter->save();

    drawBackground(painter);
    if(m_pDoc)
    {
        m_pDoc->paint(painter);
        m_pDoc->paintActiveState(painter);
    }
    if(m_pDoc->m_selectItems.count() == 0 && m_eTool == opEditTool)
        drawForeground(painter);

    painter->restore();
}

void SyberImage::setColor(const QColor &color)
{
    m_color = color;
}

void SyberImage::setLineWidth(int value)
{
    if(m_pDoc->m_pCurItem)
    {
        m_pDoc->m_pCurItem->setLineWidth(value);
    }
    m_curLineWidth = value;
    update();
}

void SyberImage::setOpacity(int value)
{

}
