//
// Created by kaiser on 19-3-23.
//

#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[]) {
  QCoreApplication app{argc, argv};

  Newspaper newspaper{"Newspaper A"};
  Reader reader;

  // 槽函数的参数不能多于信号函数的参数
  QObject::connect(&newspaper, &Newspaper::New, &reader,
                   &Reader::ReceiveNewspaper);
  newspaper.Send();

  return QCoreApplication::exec();
}