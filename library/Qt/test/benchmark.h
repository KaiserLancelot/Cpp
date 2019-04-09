//
// Created by kaiser on 19-3-24.
//

#ifndef CPP_BENCHMARK_H
#define CPP_BENCHMARK_H

#include <QObject>
#include <QString>
#include <QTest>
#include <iostream>

class TestBenchmark : public QObject {
  Q_OBJECT
 private slots:
  void initTestCase() { std::cout << "init\n"; }

  void simple() {
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    QCOMPARE(str1.localeAwareCompare(str2), 0);
    QBENCHMARK { str1.localeAwareCompare(str2); }
  }

  void multiple_data() {
    QTest::addColumn<bool>("useLocaleCompare");
    QTest::newRow("locale aware compare") << true;
    QTest::newRow("standard compare") << false;
  }

  void multiple() {
    QFETCH(bool, useLocaleCompare);
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

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