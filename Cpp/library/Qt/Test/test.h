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

  // 必须是 _data 后缀
  void ToUpper_data() {
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    QTest::newRow("all lower") << "hello"
                               << "HELLO";
    QTest::newRow("mixed") << "Hello"
                           << "HELLO";
    QTest::newRow("all upper") << "HELLO"
                               << "HELLO";
  }

  void ToUpper() {
    QFETCH(QString, string);
    QFETCH(QString, result);
    QCOMPARE(string.toUpper(), result);
  }

  void ToUpper2() {
    QString str{"Hello"};
    // 检测条件是否为真, 其他同 QCOMPARE
    QVERIFY(str.toUpper() == "HELLO");

    QString str2{"Hello"};
    // QCOMPARE 宏使用 operator== 将实际值与预期值进行比较
    // 如果实际和预期相同, 则继续执行
    // 如果不是, 则在测试日志中记录故障, 并且不会进一步执行测试
    QCOMPARE(str2.toUpper(), QString("HELLO"));
  }

  void cleanupTestCase() { std::cout << "clean up\n"; }
};

#endif  // CPP_TEST_H