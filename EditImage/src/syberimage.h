#ifndef SYBERIMAGE_H
#define SYBERIMAGE_H

#include <QQuickPaintedItem>
#include "SyberGraphDoc.h"
#include "SyberGraphTool.h"

class SyberImage : public QQuickPaintedItem
{
    Q_OBJECT
public:
    SyberImage();

    Q_INVOKABLE void mousePress(const QPoint& pos);
    Q_INVOKABLE void mouseMouse(const QPoint& pos);
    Q_INVOKABLE void mouseRelease(const QPoint& pos);
    Q_INVOKABLE void mouseDoubleClick(const QPoint &pos);

    Q_INVOKABLE void deleteItem();
    Q_INVOKABLE void setImagePath(const QString& path);

    void setDoc(SyberGraphDoc* doc);
    SyberGraphDoc* getDoc();

    int lineWidth() const;
    int opacity() const;

    OperatorTool operatorTool();

    QColor color() const;

    void drawBackground(QPainter* painter);
    void drawForeground(QPainter* painter);


    void sendHitItem(SyberGraphItem* item);

protected:
    void paint(QPainter *painter);

signals:
    void hitItem(SyberGraphItem* item);

public slots:
    void setOperatorTool(int operatorType);
    void setColor(const QColor& color);
    void setLineWidth(int value);
    void setOpacity(int value);

public:
    QPoint m_beginPoint, m_endPoint;

private:
    bool m_bPress;
    QString m_fileName;
    SyberGraphDoc* m_pDoc;
    OperatorTool m_eTool;
    QColor m_color;
    int m_nDragHandle;
    int m_curLineWidth;
    int m_curOpacity;
    QLine m_focusLine;
    QPixmap m_pixmap;
    QRect m_focusRect;
    QMap<OperatorTool, SyberGraphTool*> m_tools;
};

#endif // SYBERIMAGE_H
