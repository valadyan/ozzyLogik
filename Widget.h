#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  int16_t countryCount = - 1;
  ~Widget();
signals:
  void newOperator();
public slots:
  void addCountry(QString name, QString mcc, QString pic);
  void addOperator(QString name, QString mcc, QString pic);

private:
  Ui::Widget *ui;
  QStandardItemModel* viewModel;
};
#endif // WIDGET_H
