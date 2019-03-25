//
// Created by kaiser on 19-3-23.
//

#include <QtGlobal>

#include "newspaper.h"
#include "reader.h"

int main() {
  Newspaper newspaper{"Newspaper A"};
  Reader reader;

  // 槽函数的参数不能多于信号函数的参数
  QObject::connect(&newspaper,
                   QOverload<const std::string &>::of(&Newspaper::New), &reader,
                   &Reader::ReceiveNewspaper);
}