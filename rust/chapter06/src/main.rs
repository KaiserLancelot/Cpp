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

    let m = Message::Move { x: 1, y: 2 };

    // Option<T> 枚举被包含在了 prelude 之中, 它的成员也是如此
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

    let some_u8_value = 0u8;
    match some_u8_value {
        1 => println!("one"),
        3 => println!("three"),
        5 => println!("five"),
        7 => println!("seven"),
        // _ 模式会匹配所有的值
        // 通过将其放置于其他分支之后, _ 将会匹配所有之前没有
        // 指定的可能的值.() 就是 unit 值, 所以 _ 的情况什么也不会发生
        _ => (),
    }

    let some_u8_value = Some(0u8);

    match some_u8_value {
        Some(3) => println!("three"),
        _ => (),
    }

    // 和上面的 match 等价
    // if let 获取通过等号分隔的一个模式和一个表达式
    // 但是这样会失去 match 强制要求的穷尽性检查
    if let Some(3) = some_u8_value {
        println!("three");
    } else {
        // else 相当于 _ 分支块
        println!("other");
    }
}

#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}!", state);
            25
        }
    }
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    // Rust 中的匹配是穷尽的(exhaustive):
    // 必须穷举到最后的可能性来使代码有效
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}
