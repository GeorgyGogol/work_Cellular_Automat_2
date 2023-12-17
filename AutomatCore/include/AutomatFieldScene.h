#pragma once

#include "automatcore_global.h"
#include <QGraphicsScene>
#include "CoreProperties.h"

class SceneSettings;

class AUTOMATCORE_EXPORT AutomatFieldScene
    : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit AutomatFieldScene(QObject* parent = nullptr);
    ~AutomatFieldScene();

private:
    SceneSettings* Settings;

    void createTestField();

protected:

public:
    void LinkWithField(automat::AbstractField* pField);
    void ClearLinkedField();

public slots:
    void setNeedPaintGrid(bool isNeed);

};

