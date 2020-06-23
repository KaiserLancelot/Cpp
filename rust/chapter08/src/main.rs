use std::collections::HashMap;

fn main() {
    let v: Vec<i32> = Vec::new();
    // 根据提供的值来创建一个新的 Vec
    let v = vec![1, 2, 3];

    let mut v = Vec::new();
    v.push(5);
    // 删除并返回最后一个元素
    v.pop();

    let s = String::from("fuck");
    let mut v = Vec::new();
    // s 被移动
    v.push(s);

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

    // TODO & 的用法
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
    // let s = s1 + "-" + &s2 + "-" + &s3;
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

    // HashMap 默认使用一种密码学安全的(cryptographically strong)哈希函数
    // 它可以抵抗拒绝服务(Denial of Service, DoS)攻击.然而这并不是可用的最快的算法
    let mut source = HashMap::new();
    source.insert("blue", 10);
    source.insert("yellow", 20);

    let team = vec!["blue", "yellow"];
    let source = vec![10, 50];
    // 可以使用 zip 方法来创建一个元组的 vector
    // 使用 collect 方法将这个元组 vector 转换成一个 HashMap
    // 这里 HashMap<_, _> 类型注解是必要的, 因为可能 collect 很多不同的数据结构
    // 但是对于键和值的类型参数来说, 可以使用下划线占位, 而 Rust 能够根据 vector
    // 中数据的类型推断出 HashMap 所包含的类型
    let map: HashMap<_, _> = team.iter().zip(source.iter()).collect();

    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    // field_name 和 field_value 被移动到哈希 map 中
    map.insert(field_name, field_value);

    for (key, value) in &map {
        println!("{}: {}", key, value);
    }

    match map.get(&String::from("Favorite color")) {
        Some(value) => println!("{}", value),
        None => println!("error"),
    }

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    // 旧值将被替换
    scores.insert(String::from("Blue"), 25);
    // entry 函数的返回值是一个枚举, Entry, 它代表了可能存在也可能不存在的值
    // Entry 的 or_insert 方法在键不存在时插入, 返回值的一个可变引用
    scores.entry(String::from("Blue")).or_insert(50);

    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{:?}", map);
}
