#include "DbParser.h"

#include <QDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlField>

DbParser::DbParser(QString databaseName)
{
  db.setDatabaseName(databaseName);
  db.open();
}

DbParser::~DbParser()
{
  db.close();
}

void DbParser::readDb(){
  query.exec("SELECT * FROM countries");
  QSqlQuery q(db);

  while (query.next())
  {
    emit sendCountry(query.value(2).toString(), query.value(0).toString(), query.value(1).toString());
    q.exec(QString("SELECT * FROM operators WHERE mcc='") +
           query.value(0).toString() + "'");
    while (q.next())
    {
      emit sendOperator(q.value(2).toString(), q.value(0).toString(), q.value(1).toString());
    }
  }

}

void DbParser::createOperator(QString name, QString mcc, QString mnc){
  sendOperator(name, mcc, mnc);
  query.prepare("INSERT INTO operators (name, mcc, mnc) "
                "VALUES (:name, :mcc, :mnc)");
  query.bindValue(":name", name);
  query.bindValue(":mcc", mcc);
  query.bindValue(":mnc", mnc);
  query.exec();
}

//  query.exec("SELECT * FROM operators");
//  query.exec("SELECT * FROM countries");

//  auto driver = db.driver();
//  auto record = driver->record("countries");
//  for(int i = 0; i < record.count(); i++){
//      qDebug() << record.field(i);
//    }
