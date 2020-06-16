// 如果尝试在结构体中存储一个引用而不指定生命周期将是无效的
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

// 元组结构体(tuple structs)
struct Color(i32, i32, i32);

// 没有任何字段的结构体, 类单元结构体(unit-like structs)
// 因为它们类似于 (), 即 unit 类型
// 类单元结构体常常在想要在某个类型上实现 trait
// 但不需要在类型中存储数据的时候发挥作用
struct UnitLike {}

// 通过派生 trait 增添功能
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// impl 块可以有多个
impl Rectangle {
    // 不以 self 作为参数的函数 -- 关联函数
    // 使用结构体名和 :: 语法来调用关联函数
    // 经常被用作返回一个结构体新实例的构造函数
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size,
        }
    }
    // 定义 area 方法
    // 第一个参数总是 self/&self
    // 方法可以选择获取 self 的所有权
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    // Rust 并不允许只将某个字段标记为可变
    let mut user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };

    let user2 = User {
        email: String::from("another@example.com"),
        username: String::from("anotherusername567"),
        // 结构体更新语法, 其余值来自 user1 中的字段
        ..user1
    };

    let black = Color(0, 0, 0);

    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    println!("{}", area(&rect1));

    // {} 默认告诉 println! 使用被称为 Display 的格式:
    // 意在提供给直接终端用户查看的输出
    // 结构体默认并没有提供一个 Display 实现
    // {:?} 指示符告诉 println! 我们想要使用叫做 Debug 的输出格式
    // {:#?} 会有一个更易读的输出
    println!("{:#?}", rect1);

    // Rust 有一个叫自动引用和解引用(automatic referencing and dereferencing)的功能
    // 方法调用是 Rust 中少数几个拥有这种行为的地方
    // 当使用 object.something() 调用方法时, Rust 会自动为
    // object 添加 &、&mut 或 * 以便使 object 与方法签名匹配
    println!("{}", rect1.area());
}

fn build_user(email: String, username: String) -> User {
    User {
        // 如果变量和字段同名时可以简写
        email,
        username: username,
        active: true,
        sign_in_count: 1,
    }
}

fn area(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}
