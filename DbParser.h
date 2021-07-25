#ifndef DBPARSER_H
#define DBPARSER_H

#include <QObject>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

class DbParser : public QObject
{
  Q_OBJECT

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  QSqlQuery query;
public:
  DbParser(QString databaseName);
  void readDb();
  ~DbParser();
signals:
  void sendCountry(QString name, QString mcc, QString pic);
  void sendOperator(QString name, QString mcc, QString mnc);
};

#endif // DBPARSER_H
