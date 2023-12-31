#pragma once

#include "automatcore_global.h"
#include <QGraphicsScene>
#include "CoreProperties.h"

namespace automat {
    class AbstractField;
}

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

    void setupTestField();

protected:

public:
    void LinkWithField(automat::AbstractField* pField);
    void ClearLinkedField();

public slots:
    void setNeedPaintGrid(bool isNeed);
    void setNeedPaintCellInfo(bool isNeed);
    void setNeedPaintDirections(bool isNeed);

signals:
    void FieldInfoChanged(const FieldInformation& actualInfo);

};

