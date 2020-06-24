// use std::error::Error;
use std::fs::{self, File};
use std::io::{self, ErrorKind, Read};

// 示例, 代码原型和测试都非常适合 panic, 比如调用 unwrap 或 expect
// 当有一些其他的逻辑来确保 Result 会是 Ok 值时, 调用 unwrap 也是合适的
// 在当有可能会导致有害状态的情况下建议使用 panic! —— 在这里, 有害状态是指
// 当一些假设, 保证, 协议或不可变性被打破的状态, 例如无效的值, 自相矛盾的值
// 或者被传递了不存在的值 —— 外加如下几种情况:
// 有害状态并不包含预期会偶尔发生的错误
// 在此之后代码的运行依赖于不处于这种有害状态
// 当没有可行的手段来将有害状态信息编码进所使用的类型中的情况

fn main() {
    // 当执行这个宏时, 程序会打印出一个错误信息, 展开并清理栈数据, 然后接着退出
    // 出现这种情况的场景通常是检测到一些类型的 bug, 而且程序员并不清楚该如何处理它
    // panic!("crash and burn");
    // 当出现 panic 时, 程序默认会开始展开(unwinding), 这意味着 Rust 会回溯栈并清理
    // 它遇到的每一个函数的数据, 不过这个回溯并清理的过程有很多工作.
    // 另一种选择是直接终止(abort), 这会不清理数据就退出程序.那么程序所使用的内存需要由操作系统来清理
    // 如果你需要项目的最终二进制文件越小越好, panic 时通过在 Cargo.toml 的 [profile]([profile.release])
    // 部分增加 panic = 'abort', 可以由展开切换为终止

    // File::open 返回 Result<T, E>
    // 这里泛型参数 T 放入了成功值的类型 std::fs::File, 它是一个文件句柄
    // E 被用在失败值上时 E 的类型是 std::io::Error(一个结构体)
    // Result 枚举和其成员也被导入到了 prelude 中
    let f = match File::open("hello.txt") {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(file) => file,
                Err(error) => panic!("Problem creating the file: {:?}", error),
            },
            other_error => panic!("Problem opening the file: {:?}", other_error),
        },
    };

    // 如果 Result 值是成员 Ok, unwrap 会返回 Ok 中的值
    // 如果 Result 是成员 Err, unwrap 会为我们调用 panic!
    let f = File::open("hello.txt").unwrap();
    // 类似与 unwrap, 但可以提供错误信息
    let f = File::open("hello2.txt").expect("Failed to open hello.txt");
}

// main 函数另一个有效的返回值是 Result<T, E>
// Box<dyn Error> 被称为 trait 对象(trait object)
// 可以理解 Box<dyn Error> 为使用 ? 时 main 允许返回的任何类型的错误
// fn main() -> Result<(), Box<dyn Error>> {
//     let f = File::open("hello.txt")?;
//     Ok(())
// }

fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn read_username_from_file2() -> Result<String, io::Error> {
    // 只能在返回 Result 或者其它实现了 std::ops::Try 的类型的函数中使用 ? 运算符
    // 如果 Result 的值是 Ok, 这个表达式将会返回 Ok 中的值而程序将继续执行
    // 如果值是 Err, Err 中的值将作为整个函数的返回值, 就好像使用了 return 关键字一样
    // ? 运算符所使用的错误值被传递给了 from 函数, 它定义于标准库的 From trait 中
    // 其用来将错误从一种类型转换为另一种类型
    // 当 ? 运算符调用 from 函数时, 收到的错误类型被转换为定义为当前函数返回的错误类型
    // 这在当一个函数返回一个错误类型来代表所有可能失败的方式时很有用
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}

fn read_username_from_file3() -> Result<String, io::Error> {
    let mut s = String::new();
    // 可以链式方法调用
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}

fn read_username_from_file4() -> Result<String, io::Error> {
    fs::read_to_string("hello.txt")
}
