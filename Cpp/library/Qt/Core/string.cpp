//
// Created by kaiser on 19-4-14.
//

#include <iostream>

#include <QString>
#include <QTextStream>

// 在 Linux 下, wchar_t 为 32 位, 使用 UTF-32 编码

// QString 存储一系列 16 位的 QChar, 每个对应一个 UTF-16 代码单元
// 如果某字符需要两个代码单元则由连续的两个 QChar 存储
// QString 使用 copy-on-write
// QByteArray 存储原始字节并有空终止字符(类似于 const char*)

int main() {
  QTextStream out{stdout, QIODevice::WriteOnly};

  // const char *字符串将被认为是带有空终止字符, UTF-8 编码的字符串
  QString fuck("你好");
  std::cout << fuck.toStdString().c_str() << '\n';
  std::cout << fuck.toLocal8Bit().data() << '\n';
  // 使用 at() 可以比 operator[](...) 更快, 因为它永远不会造成 deep copy
  // QString 可以嵌入空字符 (QChar::Null), size() 会计算它

  QString str("and");
  // 插到前面
  str.prepend("rock ");
  str.append(" roll");
  str.replace(5, 3, "&");
  out << str << '\n';

  str.clear();

  str.sprintf("The answer is %d\n", 42);
  out << str;

  out << QString("The answer is %1\n").arg(42);

  str = QString::number(42);
  str.setNum(42);
  out << str << '\n';

  str = "The answer is 42";
  // 同 strsub()
  out << str.mid(14, 2) << '\n';
  // 最右边的 n 个字符(还有 left())
  out << str.right(2) << '\n' << flush;

  // 判断一个字符串是否包含某个字符, 字符串或匹配某个正则表达式
  // 失败则返回 -1, 否则返回找到的东西第一次出现的索引
  str.indexOf("42");
  QString x("sticky question");
  QString y("sti");

  // 第二个参数指明在第几个字符开始寻找, 如果为 -1 就从最后一个字符开始
  std::cout << x.indexOf(y) << '\n';      // 0
  std::cout << x.indexOf(y, 1) << '\n';   // 10
  std::cout << x.indexOf(y, 10) << '\n';  // 10
  std::cout << x.indexOf(y, 11) << '\n';  // -1

  std::cout << std::boolalpha << x.startsWith("sti") << '\n';
  std::cout << std::boolalpha << x.endsWith("sti") << '\n';

  // replace remove insert 类似与 std::string 的

  // 删除两端的空白
  out << QString("     test    test     ").trimmed() << '\n';
  // 删除两端的空白, 并将内部的一个或多个空白符替换为单个空格
  out << QString("     test    test     ").simplified() << '\n';

  str = "polluter pays principle";
  // 拆分字符串
  auto words{str.split(" ")};
  for (const auto &word : words) {
    out << word << ' ';
  }
  out << '\n';

  // 合并字符串
  out << words.join('a') << '\n';
}
