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
signals:
  void addNewOperator(QString name, QString mcc, QString mnc);
public slots:
  void setOperator(QString name, QString mcc, QString mnc);
  void newOperator();
  void createOperator();

private:
  Ui::OperatorEditor *ui;
};

#endif // OPERATOREDITOR_H
