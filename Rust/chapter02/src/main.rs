// 看起来和 C++ 的 using 一样
use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    // println! 是一个 Rust 宏 (macro) 而不是函数
    // 当看到符号 ! 的时候, 就意味着调用的是宏而不是普通函数
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
        // new() 关联函数(associated function), 一些语言中把它称为静态方法
        let mut guess = String::new();

        io::stdin()
            // & 表示引用, 默认也是不可变的
            // read_line 行为和 C++ 的 getline() 相同, 返回 io::Result, 是枚举类型
            // 成员是 Ok 和 Err, Ok 成员表示操作成功, 内部包含成功时产生的值
            // Err 成员则意味着操作失败, 并且包含失败的前因后果
            .read_line(&mut guess)
            // 是 Err, expect 会导致程序崩溃, 并显示当做参数传递给 expect 的信息
            // 是 OK, expect 会获取 Ok 中的值并原样返回
            .expect("Failed to read line");

        // Rust 允许用一个新变量来隐藏(shadow)之前同名的变量.这个功能常用在需要转换值类型之类的场景
        // 因为 parse() 可以解析多种数字类型, 因此需要告诉 Rust 具体的数字类型
        // 注意, 因为 guess 与 secret_number 的比较,  secret_number 也被推断出是 u32 类型
        let guess: u32 = match guess.trim().parse() {
            // match 语句是处理错误的惯用方法
            Ok(num) => num,
            // _ 是一个通配符值, 用来匹配所有 Err 值, 不管其中有何种信息
            Err(_) => continue,
        };
        println!("You guessed: {}", guess);

        // 一个 match 表达式由分支(arms)构成.
        // 一个分支包含一个模式(pattern)和表达式开头的值与分支模式相匹配时应该执行的代码
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
