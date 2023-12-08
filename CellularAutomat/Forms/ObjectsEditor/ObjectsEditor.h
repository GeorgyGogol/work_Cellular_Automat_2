#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ObjectsEditorClass; };
QT_END_NAMESPACE

class ObjectsEditor : public QMainWindow
{
    Q_OBJECT

public:
    ObjectsEditor(QWidget *parent = nullptr);
    ~ObjectsEditor();

private:
    Ui::ObjectsEditorClass *ui;
};
