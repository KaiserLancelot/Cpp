//
// Created by kaiser on 19-3-24.
//

#ifndef CPP_BENCHMARK_H
#define CPP_BENCHMARK_H

#include <QObject>
#include <QString>
#include <QTest>
#include <iostream>

class Benchmark : public QObject {
  Q_OBJECT
 private slots:
  void initTestCase() { std::cout << "init\n"; }

  void Simple() {
    QString str1("This is a Test string");
    QString str2("This is a Test string");

    // localeAwareCompare 比较两个字符串, 并返回指示小于大于或等于的整数
    QCOMPARE(str1.localeAwareCompare(str2), 0);
    QBENCHMARK { str1.localeAwareCompare(str2); }
  }

  void Multiple_data() {
    QTest::addColumn<bool>("useLocaleCompare");
    QTest::newRow("locale aware compare") << true;
    QTest::newRow("standard compare") << false;
  }

  void Multiple() {
    QFETCH(bool, useLocaleCompare);
    QString str1("This is a Test string");
    QString str2("This is a Test string");

    int result;
    if (useLocaleCompare) {
      QBENCHMARK { result = str1.localeAwareCompare(str2); }
    } else {
      QBENCHMARK { result = (str1 == str2); }
    }
    // 这可以抑制编译器有关未使用变量的警告
    Q_UNUSED(result)
  }

  void cleanupTestCase() { std::cout << "clean up\n"; }
};

#endif  // CPP_BENCHMARK_H
