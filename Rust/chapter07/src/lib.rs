/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-16 04:30:34
 * @ Modified time: 2020-05-17 19:59:45
 */

// 使用 mod 关键字定义一个模块
// 模块让我们可以将一个 crate 中的代码进行分组, 以提高可读性与重用性, 还可以控制项的私有性
// 在模块内, 还可以定义其他的模块
// 模块还可以保存一些定义的其他项, 比如结构体, 枚举, 常量, 特性, 或者函数
// 整个模块树都植根于名为 crate 的隐式模块下
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
        fn seat_at_table() {}
    }

    mod serving {
        fn take_order() {}
        fn server_order() {}
        fn take_payment() {}
    }
}

pub fn eat_at_restaurant() {
    // Rust 中默认所有项(函数, 方法, 结构体, 枚举, 模块和常量)都是私有的
    // 父模块中的项不能使用子模块中的私有项, 但是子模块中的项可以使用他们父模块中的项
    crate::front_of_house::hosting::add_to_waitlist();
    front_of_house::hosting::add_to_waitlist();
}

// 习惯上将函数的父模块引入作用域
// 使用 use 引入结构体, 枚举和其他项时, 习惯是指定它们的完整路径
// 想使用 use 语句将两个具有相同名称的项带入作用域时除外
// use crate::front_of_house::hosting;
// use front_of_house::hosting;

// 使用 pub use 重导出名称
pub use crate::front_of_house::hosting;

use std::fmt::Result;
// 使用 as 关键字重命名
use std::io::Result as IoResult;

fn eat_at_restaurant2() {
    hosting::add_to_waitlist();
}

fn serve_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        super::serve_order();
    }

    fn cook_order() {}
}

// 嵌套路径
// 需要指定路径的相同部分, 接着是两个冒号, 接着是大括号中的各自不同的路径部分
// use std::{cmp::Ordering, io};
// 将 std::io 和 std::io::Write 同时引入作用域
use std::io::{self, Write};
// 如果希望将一个路径下所有公有项引入作用域, 可以指定路径后跟 * glob 运算符
// glob 运算符经常用于测试模块 tests 中, 这时会将所有内容引入作用域
use std::collections::*;
