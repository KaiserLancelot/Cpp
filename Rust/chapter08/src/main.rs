/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-18 12:24:04
 * @ Modified time: 2020-05-18 12:41:24
 */

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
}
