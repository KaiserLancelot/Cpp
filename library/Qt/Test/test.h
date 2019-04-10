//
// Created by kaiser on 19-3-24.
//

#ifndef CPP_TEST_H
#define CPP_TEST_H

#include <QObject>
#include <QString>
#include <QTest>
#include <iostream>

class TestQString : public QObject {
  Q_OBJECT
 private slots:
  void initTestCase() { std::cout << "init\n"; }

  void toUpper_data() {
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    QTest::newRow("all lower") << "hello"
                               << "HELLO";
    QTest::newRow("mixed") << "Hello"
                           << "HELLO";
    QTest::newRow("all upper") << "HELLO"
                               << "HELLO";
  }

  void toUpper() {
    QFETCH(QString, string);
    QFETCH(QString, result);
    QCOMPARE(string.toUpper(), result);
  }

  void toUpper2() {
    QString str{"Hello"};
    QVERIFY(str.toUpper() == "HELLO");

    QString str2{"Hello"};
    QCOMPARE(str2.toUpper(), QString("HELLO"));
  }

  void cleanupTestCase() { std::cout << "clean up\n"; }
};

#endif  // CPP_TEST_H