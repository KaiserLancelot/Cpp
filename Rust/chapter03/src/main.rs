/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-04-29 00:00:26
 * @ Modified by: KaiserLancelot
 * @ Modified time: 2020-05-14 04:18:28
 */

fn main() {
    // 声明常量使用 const 关键字而不是 let, 并且必须注明值的类型
    // 变量不能在全局作用域中使用, 但是常量可以
    // 常量只能被设置为常量表达式
    // 常量在整个程序生命周期中都有效
    // 可以在数字字面值中插入下划线来提升可读性
    const MAX_VALUE: i32 = 100_000;
    println!("{}", MAX_VALUE);

    // Rust 中数据类型有两种, 标量(scalar)和复合(compound)
    // 标量有 4 种: 整型, 浮点, 布尔, 字符
    // 整型的长度有 8/16/32/64/128 这几种, 都有有无符号两种版本
    // 还有一个特殊的 isize/usize, 64 位架构上它们是 64 位的
    // 32 位架构上它们是 32 位的, 主要作为某些集合的索引

    // 这是错误的
    // let a: i32 = 3;
    // let b: u32 = 4;
    // let c = a + b;

    // 有 0x/0o/0b 前缀, 还有一个特殊的 Byte(u8 only), e.g. b'A'
    // 除 byte 以外的所有数字字面值允许使用类型后缀, 例如 57u16
    let num = 1u8;
    println!("{}", num);

    // 关于整型溢出, 当在 debug 模式编译时, Rust 检查这类问题并使程序 panic
    // 这个术语被 Rust 用来表明程序因错误而退出
    // 在 release 构建中, Rust 不检测溢出, 相反会进行一种被称为
    // two’s complement wrapping 的操作
    // 也就是加/减/mod 2^n
    // let num: i8 = 127;
    // println!("{}", num + 1); // -128
    // 注意, 这会在编译时出错
    // let num: i8 = 128;
    // let num = 128i8;

    // 浮点数有 2 种, f32/f64

    // Rust 的 char 类型的大小为四个字节
    // 并代表了一个 Unicode 标量值(Unicode Scalar Value)
    let c = 'a';
    println!("{}", c);

    // Rust 有两个原生的复合类型: 元组(tuple)和数组(array)
    // 两者都是固定长度的

    // 元组
    let tuple = (1, 'a', 20.6);
    // 使用模式匹配(pattern matching)来解构(destructure)元组值
    let (a, b, c) = tuple;
    println!("{}, {}, {}", a, b, c);
    // 使用索引直接访问
    println!("{}, {}, {}", tuple.0, tuple.1, tuple.2);

    // 数组(在栈上)
    let a = [1, 2, 3, 4, 5];
    // 初始值;数组的长度
    let a = [3; 5];

    // 会出现一个运行时 (runtime) 错误
    // 如果索引值是常量表达式/字面量会编译错误
    // let index = 100_000;
    // println!("{}", a[index]);

    function(4);

    // Rust 是一门基于表达式(expression-based)的语言
    // 语句(Statements)是执行一些操作但不返回值的指令.表达式(Expressions)计算并产生一个值
    // 使用 let 关键字创建变量并绑定一个值是语句, 函数定义是语句,  y = 6 也是语句
    // {}, 是一个表达式, 值等同于 {} 中最后一个表达式的值

    // let mut x = 2;
    // let mut y = 3;
    // // 错误
    // x = y = 6;

    let x = 5;
    let y = {
        let x = 3;
        x + 1
    };
    println!("{}", y);

    // 注意 if 是一个表达式
    // 没有括号
    // 条件必须是 bool 类型, 不能隐式转换
    if y < 10 {
        println!("y < 10");
    }

    let condition = true;
    // 在这种情况下, if 和 else 分支表达式类型必须匹配
    let number = if condition { 5 } else { 6 };

    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            // break 表达式
            break counter * 2;
        }
    };

    println!("The result is {}", result);

    let a = [10, 20, 30, 40, 50];
    let mut index = 0;

    while index < 5 {
        println!("the value is: {}", a[index]);
        index = index + 1;
    }
    // 和使用 while 循环相比, 更简洁并且更快
    // 因为使用 while 循环时, 编译器增加了运行时
    // 代码来对每次循环的每个元素进行条件检查
    for element in a.iter() {
        println!("the value is: {}", element);
    }

    // (1..4) 是 Range, 它是标准库提供的类型
    // rev 反转
    for number in (1..4).rev() {
        println!("{}!", number);
    }
}

// 定义在 main 之后也可以在 main 中调用
// 必须声明每个参数的类型
// 在 Rust 中, 函数的返回值等同于函数体最后一个表达式的值
// 使用 return 关键字和指定值, 可从函数中提前返回
fn function(x: i32) -> i32 {
    println!("the value is {}", x);
    5
    // 5; 为错误: expected i32, found ()
    // 空元组 () 表示不返回值
}
