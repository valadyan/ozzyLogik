#include <QApplication>
#include "Widget.h"
#include "DbParser.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  DbParser* dbParser = new DbParser("system.db");

  Widget* w = new Widget;

  QObject::connect(dbParser, &DbParser::sendCountry,  w, &Widget::addCountry);
  QObject::connect(dbParser, &DbParser::sendOperator,  w, &Widget::addOperator);

  dbParser->readDb();

  w->show();
  return a.exec();
}

//"216" --- "71" --- "UPC"
//"216" --- "99"mnc --- "MAV"
//"255" --- "7" --- "3mob"
//"289"mcc --- "GE-AB"code --- "Abkhazia"
//"505" --- "AU" --- "Australia"
//"232" --- "AT" --- "Austria"
//"400" --- "AZ" --- "Azerbaijan"
