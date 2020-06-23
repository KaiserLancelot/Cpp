// crate 是一个二进制项或者库, crate root 是一个源文件
// Rust 编译器以它为起始点, 并构成 crate 的根模块

// 包(package)是提供一系列功能的一个或者多个 crate
// 一个包会包含有一个 Cargo.toml 文件, 阐述如何去构建这些 crate

// 一个包中至多只能包含一个库 crate(library crate);
// 包中可以包含任意多个二进制 crate(binary crate);
// 包中至少包含一个 crate, 无论是库的还是二进制的

// src/main.rs 就是一个与包同名的二进制 crate 的 crate root
// src/lib.rs 就是一个与包同名的库 crate 的 crate root

// 此声明将会查找名为 front_of_house.rs 的文件
// 并将该文件的内容放到此作用域中一个名为 front_of_house 的模块里面
mod front_of_house;

pub fn eat_at_restaurant() {
    // Rust 中默认所有项(函数, 方法, 结构体, 枚举, 模块和常量)都是私有的
    // 父模块中的项不能使用子模块中的私有项, 但是子模块中的项可以使用他们父模块中的项
    // front_of_house 模块不是公有的, 不过因为 eat_at_restaurant 函数
    // 与 front_of_house 定义于同一模块中, 所以可以访问
    // add_to_waitlist 函数与 eat_at_restaurant 被定义在同一 crate 中
    // 这意味着我们可以使用 crate 关键字为起始的绝对路径
    crate::front_of_house::hosting::add_to_waitlist();
    // 使用绝对路径还是相对路径取决于你是更倾向于将项的定义代码与使用该项的代码分开移动还是一起移动
    // 更倾向于使用绝对路径, 因为它更适合移动代码定义和项调用的相互独立
    front_of_house::hosting::add_to_waitlist();
}

fn serve_order() {}

// 使用 mod 关键字定义一个模块
// 模块让我们可以将一个 crate 中的代码进行分组, 以提高可读性与重用性, 还可以控制项的私有性
// 在模块内, 还可以定义其他的模块
// 模块还可以保存一些定义的其他项, 比如结构体, 枚举, 常量, 特性, 或者函数
// 整个模块树都植根于名为 crate 的隐式模块下
mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        // 可以使用 super 开头来构建从父模块开始的相对路径
        // 因为 back_of_house 模块和 server_order 函数之间可能具有某种关联关系
        // 并且, 如果我们要重新组织这个 crate 的模块树, 需要一起移动它们, 因此, 使用 super
        // 注意, 直接 serve_order() 是错误的
        super::serve_order();
    }

    fn cook_order() {}

    // 在一个结构体定义的前面使用了 pub, 这个结构体会变成公有的, 但是这个结构体的字段仍然是私有的
    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
    // 如果我们将枚举设为公有, 则它的所有成员都将变为公有
}

// 习惯上将函数的父模块引入作用域
// 使用 use 引入结构体, 枚举和其他项时, 习惯是指定它们的完整路径
// (想使用 use 语句将两个具有相同名称的项带入作用域时除外)
// use crate::front_of_house::hosting;
// use front_of_house::hosting;

// 当使用 use 关键字将名称导入作用域时, 在新作用域中可用的名称是私有的
// 使用 pub use 重导出名称, 这样外部代码也可以使用这个新路径
pub use crate::front_of_house::hosting;

use std::fmt::Result;
// 使用 as 关键字重命名
use std::io::Result as IoResult;

fn eat_at_restaurant2() {
    hosting::add_to_waitlist();
}

// 嵌套路径
// 需要指定路径的相同部分, 接着是两个冒号, 接着是大括号中的各自不同的路径部分
// use std::{cmp::Ordering, io};
// 将 std::io 和 std::io::Write 同时引入作用域
use std::io::{self, Write};
// 如果希望将一个路径下所有公有项引入作用域, 可以指定路径后跟 * glob 运算符
// glob 运算符经常用于测试模块 tests 中, 这时会将所有内容引入作用域
use std::collections::*;
