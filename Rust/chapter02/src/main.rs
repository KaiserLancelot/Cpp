/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-06 01:14:44
 * @ Modified time: 2020-05-15 02:11:20
 */
// 类似于 C++ 的 using
// 默认情况下, Rust 将 prelude 模块中少量的类型引入到每个程序的作用域中
// https://doc.rust-lang.org/std/prelude/index.html
// 如果需要的类型不在 prelude 中, 必须使用 use 语句显式地将其引入作用域

// Rng 是一个 trait, 它定义了随机数生成器应实现的方法
// 想使用这些方法的话, 此 trait 必须在作用域中
use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    // 当看到符号 ! 的时候, 就意味着调用的是宏 (macro) 而不是普通函数
    println!("Guess the number");

    // rand::thread_rng() 函数提供实际使用的随机数生成器
    // 它位于当前执行线程的本地环境中, 并从操作系统获取 seed
    // gen_range 方法获取两个数字作为参数, 并生成一个范围在两者之间的随机数(左开右闭)
    let secret_number = rand::thread_rng().gen_range(1, 101);
    println!("The secret number is: {}", secret_number);

    // loop 关键字创建了一个无限循环
    loop {
        println!("Please input your guess.");

        // 在 Rust 中, 变量默认是不可变的
        // 使用 mut 来使一个变量可变
        // String 是 UTF-8 编码的
        // new() 关联函数(associated function), 类似于 C++ 中的静态成员函数
        let mut guess = String::new();

        io::stdin()
            // & 表示引用, 默认也是不可变的
            // read_line 读到换行符为止(保存了换行符), 返回 io::Result, 是枚举类型
            // 成员是 Ok 和 Err, Ok 成员表示操作成功, 内部包含成功时产生的值
            // Err 成员则意味着操作失败, 并且包含失败的前因后果
            .read_line(&mut guess)
            // 是 Err, expect 会导致程序崩溃, 并显示当做参数传递给 expect 的信息
            // 是 OK, expect 会获取 Ok 中的值并原样返回
            // 如果不调用 expect, 程序也能编译, 不过会出现一个警告
            .expect("Failed to read line");

        // Rust 允许用一个新变量来隐藏(shadow)之前同名的变量.这个功能常用在需要转换值类型之类的场景
        // 因为 parse() 可以解析多种数字类型, 因此需要告诉 Rust 具体的数字类型
        // 注意 50x 这种也不行
        let guess: u32 = match guess.trim().parse() {
            // match 语句是处理错误的惯用方法
            // num 是自己起的名
            Ok(num) => num,
            // _ 是一个通配符值, 用来匹配所有 Err 值, 不管其中有何种信息
            Err(_) => continue,
        };
        println!("You guessed: {}", guess);

        // 一个 match 表达式由分支(arms)构成.
        // 一个分支包含一个模式(pattern)和表达式开头的值与分支模式相匹配时应该执行的代码
        // 注意, 因为 guess 与 secret_number 的比较,  secret_number 也被推断出是 u32 类型
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
