#include "OperatorEditor.h"
#include "ui_OperatorEditor.h"

OperatorEditor::OperatorEditor(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::OperatorEditor)
{
  ui->setupUi(this);
}

OperatorEditor::~OperatorEditor()
{
  delete ui;
}
