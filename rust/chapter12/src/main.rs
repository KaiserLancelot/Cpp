use std::env;
use std::process;

use chapter12::Config;

fn main() {
    // 注意 std::env::args 在其任何参数包含无效 Unicode 字符时会 panic
    // 如果需要接受包含无效 Unicode 字符的参数, 使用 std::env::args_os 代替
    // 第一个参数是二进制文件的名称
    let args: Vec<String> = env::args().collect();
    // 当 Result 是 Ok 时, 这个方法的行为类似于 unwrap: 它返回 Ok 内部封装的值
    // 当其值是 Err 时, 该方法会调用一个闭包(closure), 也就是一个我们定义的
    // 作为参数传递给 unwrap_or_else 的匿名函数
    let config = Config::new(&args).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {}", err);
        // process::exit 会立即停止程序并将传递给它的数字作为退出状态码
        process::exit(1);
    });

    if let Err(e) = chapter12::run(config) {
        println!("Application error: {}", e);
        process::exit(1);
    }
}
