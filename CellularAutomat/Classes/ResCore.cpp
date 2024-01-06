#include "stdafx.h"
#include "ResCore.h"

#include <QFile>
#include <QTextStream>
#include <QTextCodec>

ResCore::ResCore()
    : Prefix("CellularAutomat/")
{
}

ResCore::ResCore(const QString& basePrefix)
    : Prefix(basePrefix + "/")
{
}

ResCore ResCore::lowerPrefix(const QString& prefix)
{
    return ResCore(Prefix + prefix);
}

QString ResCore::loadString(const QString& ResAlias, bool IsRaw)
{
    QString out = "Not Found :(";

    QString filePath = ":/" + Prefix + ResAlias;

    if (IsRaw && !filePath.contains("txt")) {
        filePath = ":/" + Prefix + "txt/" + ResAlias;
    }

    QFile resFile(filePath);
    if (resFile.open(QIODevice::ReadOnly)) {
        QTextStream tSream(&resFile);
        tSream.setCodec(QTextCodec::codecForName("UTF-8"));
        out = tSream.readAll();
    }
    else {
        out = filePath + " Not Found :(";
    }

    return out;
}

QPixmap ResCore::loadImage(const QString& ResAlias, bool IsRaw)
{
    QPixmap out;

    QString filePath = ":/" + Prefix + ResAlias;
    if (IsRaw && !filePath.contains("img")) {
        filePath = ":/" + Prefix + "img/" + ResAlias;
    }

    QFile resFile(filePath);
    if (resFile.open(QIODevice::ReadOnly)) {
        out = QPixmap(resFile.fileName());
    }
    else {
        out = loadImageNotFound();
    }

    return out;
}

QPixmap ResCore::loadImageNotFound()
{
    QString filePath = ":/CellularAutomat/img/NotFound";
    QPixmap out(filePath);
    return out;
}


