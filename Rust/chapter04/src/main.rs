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

    // TODO Copy trait ???

    let s1 = String::from("hello");
    let (s2, len) = calculate_length(s1);
    println!("The length of '{}' is {}.", s2, len);
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();
    // 可以使用元组来返回多个值
    (s, length)
}
