#ifndef SyberGraphTool_H
#define SyberGraphTool_H

#include <QMouseEvent>
#include "SyberGraphItem.h"
class SyberImage;
class SyberGraphItem;

enum OperatorTool{
    opEditTool,
    opLineTool,
    opRectTool,
    opRoundTool,
    opImageTool,
    opStringTool
};

class SyberGraphTool
{
public:
    virtual void mousePress(SyberImage* view, const QPoint& pos) = 0;
    virtual void mouseMove(SyberImage* view, const QPoint& pos) = 0;
    virtual void mouseRelease(SyberImage* view, const QPoint& pos) = 0;
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos) = 0;

protected:
    bool m_bPress;
    ItemType m_bType;
    SyberGraphItem* m_pCurItem;
    SyberGraphTool();
};

class SyberLineTool : public SyberGraphTool
{
public:
    SyberLineTool();

    virtual void mousePress(SyberImage* view, const QPoint& pos);
    virtual void mouseMove(SyberImage* view, const QPoint& pos);
    virtual void mouseRelease(SyberImage* view, const QPoint& pos);
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos);
};


class SyberRectTool : public SyberGraphTool
{
public:
    SyberRectTool();

    virtual void mousePress(SyberImage* view, const QPoint& pos);
    virtual void mouseMove(SyberImage* view, const QPoint& pos);
    virtual void mouseRelease(SyberImage* view, const QPoint& pos);
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos);
};

class SyberRoundTool : public SyberGraphTool
{
public:
    SyberRoundTool();

    virtual void mousePress(SyberImage* view, const QPoint& pos);
    virtual void mouseMove(SyberImage* view, const QPoint& pos);
    virtual void mouseRelease(SyberImage* view, const QPoint& pos);
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos);
};

class SyberImageTool : public SyberGraphTool
{
public:
    SyberImageTool();

    virtual void mousePress(SyberImage* view, const QPoint& pos);
    virtual void mouseMove(SyberImage* view, const QPoint& pos);
    virtual void mouseRelease(SyberImage* view, const QPoint& pos);
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos);
};


class SyberStringTool : public SyberGraphTool
{
public:
    SyberStringTool();

    virtual void mousePress(SyberImage* view, const QPoint& pos);
    virtual void mouseMove(SyberImage* view, const QPoint& pos);
    virtual void mouseRelease(SyberImage* view, const QPoint& pos);
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos);
};

class SyberEditTool : public SyberGraphTool
{
public:
    SyberEditTool();

    virtual void mousePress(SyberImage* view, const QPoint& pos);
    virtual void mouseMove(SyberImage* view, const QPoint& pos);
    virtual void mouseRelease(SyberImage* view, const QPoint& pos);
    virtual void mouseDoubleClick(SyberImage* view, const QPoint& pos);

private:
    int m_nDragHandle;
};

#endif // SyberGraphTool_H
