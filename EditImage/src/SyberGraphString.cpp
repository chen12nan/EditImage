#include "SyberGraphString.h"

SyberGraphString::SyberGraphString(QObject *parent):
    SyberGraphRect(parent)
{
}

void SyberGraphString::setText(const QString &text)
{
    m_text = text;
    m_textEdit->setText(text);
}

QString SyberGraphString::text() const
{
    return m_text;
}
