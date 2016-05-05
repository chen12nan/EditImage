#ifndef SYBERGRAPHSTRING_H
#define SYBERGRAPHSTRING_H
#include "SyberGraphRect.h"
#include <QTextEdit>

class SyberGraphString : public SyberGraphRect
{
    Q_OBJECT

public:
    SyberGraphString(QObject*parent = 0);

    void setText(const QString& text);
    QString text() const;

    // paint
    virtual void paint(QPainter* painter);
    virtual void paintActiveState(QPainter* painter);

private:
    QString m_text;
};

#endif // SYBERGRAPHSTRING_H
