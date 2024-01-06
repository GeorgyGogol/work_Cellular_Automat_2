#pragma once

#include <QString>
#include <QPixmap>

class ResCore
{
public:
    ResCore();
    ResCore(const QString& basePrefix);
    ~ResCore() = default;

private:
    QString Prefix;

public:
    ResCore lowerPrefix(const QString& prefix);

    QString loadString(const QString& ResAlias, bool IsRaw = true);
    QPixmap loadImage(const QString& ResAlias, bool IsRaw = true);
    QPixmap loadImageNotFound();


};

