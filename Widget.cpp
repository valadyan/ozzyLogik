#include "Widget.h"
#include "ui_Widget.h"
#include <QStandardItem>
#include <QStyledItemDelegate>
#include <QList>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  viewModel = new QStandardItemModel();
  ui->operatorsTreeView->setModel(viewModel);

  QObject::connect(ui->addOperatorPB, &QPushButton::clicked, this, &Widget::newOperator);

  //  QStyledItemDelegate style;


//  ui->operatorsTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
//  QObject::connect(ui->operatorsTreeView, &QTreeView::customContextMenuRequested
//          ,[&](const QPoint& point){
//            QModelIndex index = ui->operatorsTreeView->indexAt(point);
//            qDebug()<<index.data();
//            if (index.isValid() && index.row() % 2 == 0) {
//                qDebug()<<index.data();
//            }
//          });
}

void Widget::addCountry(QString name, QString mcc, QString pic){
  auto item = new QStandardItem(name);
  item->setEditable(false);
  item->setIcon(QIcon(QString("Countries/")+pic+".png"));

  viewModel->appendRow({item});
  countryCount++;
}

void Widget::addOperator(QString name, QString mcc, QString mnc){
  auto item = new QStandardItem(name);
  item->setEditable(false);
  item->setIcon(QIcon(QString("Operators/")+mcc+'_'+mnc+".png"));

  viewModel->item(countryCount)->appendRow(item);
}

Widget::~Widget()
{
  delete ui;
}

