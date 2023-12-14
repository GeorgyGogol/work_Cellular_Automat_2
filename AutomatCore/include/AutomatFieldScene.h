#pragma once

#include "automatcore_global.h"
#include <QGraphicsScene>

class SceneSettings;
class AbstractField;
class SimpleSquareTestField;

class AUTOMATCORE_EXPORT AutomatFieldScene
    : public QGraphicsScene
{
    Q_OBJECT

public:
    AutomatFieldScene(QObject* parent = nullptr);
    ~AutomatFieldScene();

private:
    SceneSettings* Settings;
    QRectF DefaultCellSize;

    void createTestField(SimpleSquareTestField* pField);

protected:

public:
    void LinkWithField(AbstractField* pField);
    void ClearLinkedField();

public slots:
    void setNeedPaintGrid(bool isNeed);

};

