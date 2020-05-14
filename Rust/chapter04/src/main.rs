/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-04-29 00:00:26
 * @ Modified time: 2020-05-15 02:11:41
 */

// 所有权规则:
// 1. Rust 中的每一个值都有一个被称为所有者(owner)的变量
// 2. 值有且只有一个所有者
// 3. 当所有者(变量)离开作用域, 这个值将被丢弃

// 变量的所有权总是遵循相同的模式: 将值赋给另一个变量时移动它
// 当持有堆中数据值的变量离开作用域时, 其值将通过 drop 被清理掉
// 除非数据被移动为另一个变量所有

fn main() {
    // 注意两者类型不一样
    // 前者是不可变的, 后者是可变的
    // 这里 s 的类型是 &str: 它是一个指向二进制程序特定位置的 slice
    let s = "str";
    let mut ss = String::from("str");

    ss.push_str("str");
    println!("{}", ss);

    // 当 s 离开作用域的时候, Rust 为我们调用一个特殊的函数, 这个函数叫做 drop

    let s1 = String::from("hello");
    // 移动
    let s2 = s1;
    // 错误, s1 已经无效了
    // println!("{}, world!", s1);

    // Rust 永远也不会自动创建数据的"深拷贝"
    // 因此, 任何自动的复制可以被认为对运行时性能影响较小

    let s1 = String::from("hello");
    // 克隆, 拷贝了实际的数据, 可能相当消耗资源
    let s2 = s1.clone();

    let x = 5;
    // 只在栈上的数据: 拷贝
    let y = x;

    // 如果一个类型拥有 Copy trait, 一个旧的变量在将其赋值给其他变量后仍然可用
    // 任何简单标量值的组合可以是 Copy 的, 不需要分配内存或某种形式资源的类型是 Copy 的
    // 所有整数类型
    // 布尔类型
    // 所有浮点数类型
    // 字符类型
    // 元组, 当且仅当其包含的类型也都是 Copy 的时候
    // 注意 struct 中成员类型都是 copy 的时候, 它也不是 copy 的

    let s1 = String::from("hello");
    let (s2, len) = calculate_length(s1);
    println!("The length of '{}' is {}.", s2, len);

    let s1 = String::from("hello");
    // &s1 语法让我们创建一个指向值 s1 的引用
    println!("{}\n", calculate_length2(&s1));

    let mut s = String::from("hello");
    // 在同一作用域中的同一数据最多只能有一个可变引用
    // 可以使用大括号来创建一个新的作用域, 以允许拥有多个可变引用
    // 只是不能同时拥有
    // 这个限制的好处是 Rust 可以在编译时就避免数据竞争
    // 错误
    // let r1 = &mut s;
    // let r2 = &mut s;
    // println!("{}, {}", r1, r2);

    // 也不能在拥有不可变引用的同时拥有可变引用
    // 错误
    // let r1 = &s;
    // let r2 = &s;
    // let r3 = &mut s;
    // println!("{}, {}, and {}", r1, r2, r3);

    change(&mut s);
    println!("{}\n", s);

    // 注意一个引用的作用域从声明的地方开始一直持续到最后一次使用为止
    let mut s = String::from("hello");

    let r1 = &s;
    let r2 = &s;
    println!("{} and {}", r1, r2);
    // 此位置之后 r1 和 r2 不再使用

    let r3 = &mut s; // 没问题
    println!("{}", r3);

    let s = String::from("hello world");
    // 字符串 slice(string slice)是 String 中一部分值的引用
    // 它没有所有权
    let hello = &s[0..5]; // 0 可以省略
    let world = &s[6..11]; // 11 可以省略

    // 6
    println!("{}\n", String::from("你好").len());
    // 字符串 slice range 的索引必须位于有效的 UTF-8 字符边界内
    // 如果尝试从一个多字节字符的中间位置创建字符串 slice
    // 则程序将会因错误而退出
    // error
    // println!("{}\n", &String::from("你好")[0..1]);

    let mut s = String::from("hello world");

    let word = first_word2(&s);

    // 错误, 当拥有某值的不可变引用时, 就不能再获取一个可变引用(&mut self)
    // s.clear();

    println!("the first word is: {}", word);

    let s = String::from("str");
    first_word2(&s[..]);

    let a = [1, 2, 3, 4, 5];
    // 类型是 &[i32], 它跟字符串 slice 的工作方式一样
    // 通过存储第一个集合元素的引用和一个集合总长度
    let slice = &a[1..3];
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();
    // 可以使用元组来返回多个值
    (s, length)
}

// 函数签名使用 & 来表明参数 s 的类型是一个引用
// 它允许使用值但不获取其所有权, 默认不允许修改引用的值
// 获取引用作为函数参数称为借用
fn calculate_length2(s: &String) -> usize {
    s.len()
}

fn change(s: &mut String) {
    s.push_str("aaaaa");
}

// 错误
// fn dangle() -> &String {
//     let s = String::from("hello");
//     &s
// }

fn first_word(s: &String) -> usize {
    // as_bytes 方法将 String 转化为字节数组
    let bytes = s.as_bytes();

    // 使用 iter 方法在字节数组上创建一个迭代器
    // enumerate 包装了 iter 的结果
    // enumerate 返回的元组中, 第一个元素是索引, 第二个元素是集合中元素的引用
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }

    s.len()
}

fn first_word2(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }

    &s[..]
}

// 可以将函数参数类型改为 &str, 更加通用
fn first_word2(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }

    &s[..]
}
