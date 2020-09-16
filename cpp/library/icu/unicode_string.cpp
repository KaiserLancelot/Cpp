#include <cstdint>
#include <iostream>

#include <unicode/schriter.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>

int main() {
  // 使用平台默认字符编码
  icu::UnicodeString str{"你好世界"};
  std::cout << str << '\n';

  str = "a string";
  // 注意, 下面这些都改变了 str
  std::cout << str.toUpper() << '\n';

  str = "  你好世界  ";
  std::cout << str.trim() << '\n';

  str = "你好";
  std::cout << str.append("世界") << '\n';

  str = "𐐷𐐷";
  // code units
  std::cout << str.length() << '\n';  // 4
  // code points(占据 1 个或 2 个 char16_t code units)
  // 没有标注 32 的成员函数都是指 code units
  std::cout << str.countChar32() << '\n';  // 2
  std::cout << str << '\n';

  // 截断
  str.truncate(2);
  std::cout << str << '\n';
  std::cout << str.length() << '\n';  // 2

  str = "你好";
  std::cout << icu::UnicodeString{str.charAt(1)} << '\n';
  str = "𐐷𐐷";
  std::cout << icu::UnicodeString{str.char32At(1)} << '\n';

  str.startsWith("");
  str.endsWith("");

  // 相当与 clear()
  str.remove();

  str = "𐐷𐐷";
  str.remove(2);
  std::cout << str << '\n';

  str = "𐐷你";
  std::cout << str.indexOf("你") << '\n';

  str = "你好好";
  std::cout << str.findAndReplace("好", "不好") << '\n';

  str = "你好好";
  std::cout << str.replace(1, 1, "不好") << '\n';

  icu::UnicodeString s1{"weißkopfseeadler"};
  icu::UnicodeString s2{"weisskopfseeadler"};
  // 大小写折叠
  std::cout << static_cast<std::int32_t>(s1.foldCase() == s2.foldCase())
            << '\n';  // 1

  // 只读视图
  str.tempSubString(1);

  str = "helLo wOrld!你好 世界";
  std::cout << str.toTitle(nullptr) << '\n';  // Hello World!

  str = "𐐷𐐷22";
  auto length{str.length()};
  // 获取每一个字符
  for (std::int32_t idx{}; idx < length; idx = str.moveIndex32(idx, 1)) {
    std::cout << str.char32At(idx) << '\t';
  }
  std::cout << '\n';

  // 同上
  str = "𐐷𐐷22";
  icu::StringCharacterIterator iter{str};
  while (iter.hasNext()) {
    std::cout << iter.next32PostInc() << '\t';
  }
  std::cout << '\n';
}
