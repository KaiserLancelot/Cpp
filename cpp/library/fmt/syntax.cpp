//
// Created by kaiser on 19-3-13.
//

#include <fmt/format.h>

int main()
{
    // 按位置访问
    fmt::print("{2}{1}{0}\n", "a", "b", "c");

    // 格式字符串在 : 之后
    // format_spec ::=  [[fill]align][sign]["#"]["0"][width]["." precision][type]
    // fill        ::=  <a character other than '{', '}' or '\0'>
    // align       ::=  "<" | ">" | "=" | "^"
    // sign        ::=  "+" | "-" | " "
    // width       ::=  integer | "{" arg_id "}"
    // precision   ::=  integer | "{" arg_id "}"
    // type        ::=  int_type | "a" | "A" | "c" | "e" | "E" | "f" | "F" | "g" |
    // "G" | "p" | "s"
    // int_type    ::=  "b" | "B" | "d" | "n" | "o" | "x" | "X"

    // align 定义了width才有意义
    // < 左对齐(大多数对象的默认值)
    // > 右对齐(数字的默认值)
    // ^ 居中
    // = 将填充放在符号后(如果有的话)数字之前,仅对数字有效

    // sign 仅对数字有效
    // + 显示+/-
    // - 显示-(默认)
    // 空格 在正数前空格,负数前-

    // width
    // 如果未定义或者比内容字符数量小,则宽度由内容决定
    // width前面的0效果是在符号之后填充0,仅对数字有效

    // precision
    // 对于非数字类型,表示最大字符数量
    // 对于 f/F 表示显示多少位的小数
    // 对于 g/G 表示精度
    // 对整型值不能使用

    // 指定整型值的进制
    // b/B 二进制
    // d/无 十进制
    // o 八进制
    // x/X 十六进制
    // n 同 d, 但是会插入适当的数字分隔符
    // 在前面加上 # 显示前缀
    fmt::print("{0:b} {0:o} {0:d} {0:x}\n", 42);
    fmt::print("{0:#b} {0:#o} {0:#d} {0:#x}\n", 42);
    fmt::print("{:#010x}\n", 42);

    // 指定浮点数
    // a/A 十六进制浮点格式,p表示指数, 有0x/0X前缀
    // e/E 指数表示法
    // f/F 显示为定点数,F将nan/inf转换为大写, 默认小数点后显示6位
    // g/G 一般格式,如果精度 p >= 1, 舍入数字到p位有效数字,并根据大小
    // 转换到f/e(F/E)的格式,如果p = 0, 则当做 p = 1
    // 无 同g
    fmt::print("{0:a} {0:e} {0:f} {0:g}\n", 42.42);

    // s 字符串
    // c 字符
    // p 指针
    // 以上是上述类型的默认类型, 可以省略
    // bool 类型默认显示 true/false
    bool check{true};
    fmt::print("{}\n", check);

    fmt::print("{:<30}\n", "左对齐");
    fmt::print("{:>30}\n", "右对齐");
    fmt::print("{:^30}\n", "居中");
    // 填充 *
    fmt::print("{:*^30}\n", "居中");

    // 动态宽度
    fmt::print("{:<{}}\n", "左对齐", 30);
    // 动态精度
    fmt::print("{:.{}f}\n", 3.14, 1);

    fmt::print("{:+f} {:+f}\n", 3.14, -3.14);
    fmt::print("{: f} {: f}\n", 3.14, -3.14);
    fmt::print("{:-f} {:-f}\n", 3.14, -3.14);

    // 默认不显示小数点
    fmt::print("{}\n", 3.0);
    fmt::print("{:.1f}\n", 3.0);
}
