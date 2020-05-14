/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-14 03:38:18
 * @ Modified time: 2020-05-15 02:07:28
 */

enum IpAddrKind {
    V4,
    V6,
}

struct IpAddr {
    kind: IpAddrKind,
    address: String,
}

enum IpAddr2 {
    // 每个成员可以处理不同类型和数量的数据
    V4(u8, u8, u8, u8),
    V6(String),
}

enum Message {
    Quit,
    // 包含一个匿名结构体
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

// 可以在枚举上定义方法
impl Message {
    fn call(&self) {
        println!("call");
    }
}

fn main() {
    let home = IpAddr {
        kind: IpAddrKind::V4,
        address: String::from("127.0.0.1"),
    };

    let home2 = IpAddr2::V4(127, 0, 0, 1);

    let m = Message::Write(String::from("hello"));
    m.call();

    // Option<T> 枚举被包含在了 prelude 之中
    let some_number = Some(5);
    let some_string = Some("hello");
    // 如果使用 None 而不是 Some, 需要告诉 Rust Option<T> 是什么类型的
    let absent_number: Option<i32> = None;
    assert_eq!(absent_number.is_none(), true);

    let x: i8 = 5;
    let y: Option<i8> = Some(5);
    // 错误
    // 因为 Option<T> 和 T 是不同的类型, 编译器不允许像一个肯定有效
    // 的值那样使用 Option<T>
    // 换句话说, 在对 Option<T> 进行 T 的运算之前必须将其转换为 T
    // 通常这能帮助我们捕获到空值最常见的问题之一: 假设某值不为空但实际上为空的情况
    // let sum = x + y;
}
