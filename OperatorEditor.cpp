#include "OperatorEditor.h"
#include "ui_OperatorEditor.h"

OperatorEditor::OperatorEditor(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::OperatorEditor)
{
  ui->setupUi(this);
  QObject::connect(ui->savePB, &QPushButton::clicked, this, &OperatorEditor::createOperator);
  QObject::connect(ui->cancelPB, &QPushButton::clicked, this, &OperatorEditor::close);

}

void OperatorEditor::setOperator(QString name, QString mcc, QString mnc){
  //  ui->countryIcon->;
  //  ui->operatorIcon
    ui->operatorName->setText(name);
    ui->mcc->setText(mcc);
    ui->mnc->setText(mnc);
}

void OperatorEditor::newOperator(){
  //  ui->countryIcon->;
  //  ui->operatorIcon
  ui->operatorName->setText("");
  ui->mcc->setText("0");
  ui->mnc->setText("0");
}

void OperatorEditor::createOperator(){
  emit addNewOperator(ui->operatorName->text(),
                      ui->mcc->text(),
                      ui->mnc->text());
}

OperatorEditor::~OperatorEditor()
{
  delete ui;
}
