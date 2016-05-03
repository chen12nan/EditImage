#include "SyberGraphTool.h"
#include "SyberGraphDoc.h"
#include "SyberGraphLine.h"
#include "SyberGraphRect.h"
#include "SyberGraphString.h"
#include "SyberGraphImage.h"
#include "syberimage.h"

#include <QDebug>

SyberGraphTool::SyberGraphTool() :
    m_bPress(false),
    m_pCurItem(NULL)
{
}


SyberLineTool::SyberLineTool() :
    SyberGraphTool()
{

}

void SyberLineTool::mousePress(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = true;
    SyberGraphLine *item = new SyberGraphLine();
    item->setColor(view->color());
    item->setLine(view->m_beginPoint, view->m_endPoint);
    item->setLineWidth(view->lineWidth());
    item->setOpacity(view->opacity()*0.1);
    doc->m_pCurItem = item;
    doc->append(doc->m_pCurItem);
}

void SyberLineTool::mouseMove(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    if(m_bPress)
    {
        if(doc->m_pCurItem && doc->m_pCurItem->type() == epLine)
        {
            SyberGraphLine* line = (SyberGraphLine*)doc->m_pCurItem;
            line->setLine(view->m_beginPoint, view->m_endPoint);
        }
        view->update();
    }
}

void SyberLineTool::mouseRelease(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = false;
    doc->m_pCurItem = NULL;
    view->update();
}

void SyberLineTool::mouseDoubleClick(SyberImage *view, const QPoint& pos)
{

}


SyberEditTool::SyberEditTool()
{

}

void SyberEditTool::mousePress(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    SyberGraphItem* item = doc->itemAt(pos);
    m_bPress = true;
    doc->m_pCurItem = item;
    if(item)
    {
        doc->m_selectItems.clear();
        doc->m_selectItems.append(item);
        view->sendHitItem(item);
    }
    else
        doc->m_selectItems.clear();
}

void SyberEditTool::mouseMove(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    if(doc->m_pCurItem)
    {
        if(m_bPress)
        {
                doc->m_pCurItem->moveHandleTo(view->m_endPoint, m_nDragHandle);
        }
        else
        {
            for(int  i = 0; i<= doc->m_pCurItem->getHandlerCount(); i++)
            {
                QRect rect = doc->m_pCurItem->getPointRect();
                rect.moveCenter(doc->m_pCurItem->getHandle(i));
                if(rect.contains(pos))
                {
                    QCursor cursor = doc->m_pCurItem->getHandleCursor(i);
                    view->setCursor(cursor);
                    m_nDragHandle = i;
                    view->update();
                    return ;
                }
                else
                {
                    view->setCursor(Qt::ArrowCursor);
                    m_nDragHandle = -1;
                }
            }
        }
    }
    view->update();
}

void SyberEditTool::mouseRelease(SyberImage *view, const QPoint& pos)
{
    m_bPress = false;
}

void SyberEditTool::mouseDoubleClick(SyberImage *view, const QPoint& pos)
{

}


SyberRectTool::SyberRectTool()
{

}

void SyberRectTool::mousePress(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = true;
    SyberGraphRect *item = new SyberGraphRect();
    item->setRect(view->m_beginPoint, view->m_endPoint);
    item->setLineWidth(view->lineWidth());
    item->setOpacity(view->opacity()*0.1);
    doc->m_pCurItem = item;
    doc->append(doc->m_pCurItem);

}

void SyberRectTool::mouseMove(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    if(m_bPress)
    {
        if(doc->m_pCurItem && doc->m_pCurItem->type() == epRect)
        {
            SyberGraphRect* item = (SyberGraphRect*)doc->m_pCurItem;
            item->setRect(view->m_beginPoint, view->m_endPoint);
        }
        view->update();
    }
}

void SyberRectTool::mouseRelease(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = false;
    doc->m_pCurItem = NULL;
    view->update();
}

void SyberRectTool::mouseDoubleClick(SyberImage *view, const QPoint& pos)
{

}


SyberRoundTool::SyberRoundTool()
{

}

void SyberRoundTool::mousePress(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = true;
    SyberGraphRound *item = new SyberGraphRound();
    item->setRect(view->m_beginPoint, view->m_endPoint);
    item->setLineWidth(view->lineWidth());
    item->setOpacity(view->opacity()*0.1);
    item->setRoundFlag(true);
    doc->m_pCurItem = item;
    doc->append(doc->m_pCurItem);
}

void SyberRoundTool::mouseMove(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    if(m_bPress)
    {
        if(doc->m_pCurItem && doc->m_pCurItem->type() == epRoundRect)
        {
            SyberGraphRound* item = (SyberGraphRound*)doc->m_pCurItem;
            item->setRect(view->m_beginPoint, view->m_endPoint);
        }
        view->update();
    }
}

void SyberRoundTool::mouseRelease(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = false;
    doc->m_pCurItem = NULL;
    view->update();
}

void SyberRoundTool::mouseDoubleClick(SyberImage *view, const QPoint& pos)
{

}


SyberImageTool::SyberImageTool()
{

}

void SyberImageTool::mousePress(SyberImage *view, const QPoint& pos)
{
    SyberGraphDoc *doc = view->getDoc();
    m_bPress = true;
    SyberGraphImage *item = new SyberGraphImage();
    item->setRect(view->m_beginPoint, view->m_endPoint);
    item->setOpacity(view->opacity()*0.1);
    QImage image("/home/user/DCIM/Camera/one.jpg");
    qDebug()<<Q_FUNC_INFO<< image.isNull();
    item->setImage(image);
    doc->m_pCurItem = item;
    doc->append(doc->m_pCurItem);
}

void SyberImageTool::mouseMove(SyberImage *view, const QPoint& pos)
{

}

void SyberImageTool::mouseRelease(SyberImage *view, const QPoint& pos)
{

}

void SyberImageTool::mouseDoubleClick(SyberImage *view, const QPoint& pos)
{

}


SyberStringTool::SyberStringTool()
{

}

void SyberStringTool::mousePress(SyberImage *view, const QPoint& pos)
{

}

void SyberStringTool::mouseMove(SyberImage *view, const QPoint& pos)
{

}

void SyberStringTool::mouseRelease(SyberImage *view, const QPoint& pos)
{

}

void SyberStringTool::mouseDoubleClick(SyberImage *view, const QPoint& pos)
{

}
