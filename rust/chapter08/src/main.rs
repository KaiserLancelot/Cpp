use std::collections::HashMap;

fn main() {
    let v: Vec<i32> = Vec::new();
    // 根据提供的值来创建一个新的 Vec
    let v = vec![1, 2, 3];

    let mut v = Vec::new();
    v.push(5);
    // 当 vector 被丢弃时, 所有其内容也会被丢弃

    let v = vec![1, 2, 3, 4, 5];

    // 当引用一个不存在的元素时 Rust 会造成 panic
    let third = &v[2];
    println!("The third element is: {}", third);

    // 使用 get 方法以索引作为参数来返回一个 Option<&T>
    match v.get(2) {
        Some(third) => println!("The third element is: {}", third),
        None => println!("The is no third element"),
    }

    let first = &v[0];
    // 错误
    // v.push(6);

    for i in &v {
        println!("{}", i);
    }

    let mut v = vec![100, 32, 57];
    // 为了修改可变引用所指向的值
    // 在使用 += 运算符之前必须使用解引用运算符获取 i 中的值
    for i in &mut v {
        *i += 50;
    }

    // 储存不同类型值时, 可以定义并使用一个枚举
    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12),
    ];

    // to_string 方法能用于任何实现了 Display trait 的类型
    let mut s = "str".to_string();
    s.push('3');
    s.push_str("333");
    s += "aa";
    println!("{}", s);

    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    // 注意 s1 被移动了, 不能继续使用(必须是下面的形式)
    // + 运算符使用了 add 函数
    // 类似于 fn add(self, s: &str) -> String
    // &String 可以被强转(coerced)成 &str
    // 当add函数被调用时, Rust 使用了一个被称为解引用强制多态(deref coercion)
    // 的技术, 可以将其理解为它把 &s2 变成了 &s2[..]
    // 会获取 s1 的所有权, 附加上从 s2 中拷贝的内容, 并返回结果的所有权
    let s3 = s1 + &s2;
    println!("{}", s3);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    // 不会获取任何参数的所有权
    let s = format!("{}-{}-{}", s1, s2, s3);

    // String 不支持索引
    // String 是一个 Vec<u8> 的封装
    // 另一个 Rust 不允许使用索引获取 String 字符的原因是
    // 索引操作预期总是需要常数时间.但是对于 String 不可能保证这样的性能
    // 因为 Rust 必须从开头到索引位置遍历来确定有多少有效的字符

    // 单独的 Unicode 标量值
    for c in "नमस्ते".chars() {
        println!("{}", c);
    }
    // 每一个原始字节
    for b in "नमस्ते".bytes() {
        println!("{}", b);
    }

    let mut source = HashMap::new();
    source.insert("blue", 10);
    source.insert("yellow", 20);

    let team = vec!["blue", "yellow"];
    let source = vec![10, 50];
    let map: HashMap<_, _> = team.iter().zip(source.iter()).collect();
}
