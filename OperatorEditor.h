#ifndef OPERATOREDITOR_H
#define OPERATOREDITOR_H

#include <QWidget>

namespace Ui {
  class OperatorEditor;
}

class OperatorEditor : public QWidget
{
  Q_OBJECT

public:
  explicit OperatorEditor(QWidget *parent = nullptr);
  ~OperatorEditor();

private:
  Ui::OperatorEditor *ui;
};

#endif // OPERATOREDITOR_H
