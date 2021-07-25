#include "Widget.h"
#include "ui_Widget.h"
#include <QStandardItem>
#include <QStyledItemDelegate>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  viewModel = new QStandardItemModel();
//  QStyledItemDelegate style;

//  viewModel->item(0)->setChild(0, new QStandardItem(QString("aaaa")));

  ui->operatorsTreeView->setModel(viewModel);
}

void Widget::addCountry(QString name, QString mcc, QString pic){
  viewModel->appendRow({new QStandardItem(name)});
  countryCount++;
}

void Widget::addOperator(QString name, QString mcc, QString pic){
  viewModel->item(countryCount)->setChild(0, new QStandardItem(name));
}

Widget::~Widget()
{
  delete ui;
}

