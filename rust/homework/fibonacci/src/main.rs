/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-04-29 00:00:26
 * @ Modified time: 2020-05-15 02:11:59
 */
use std::io;

fn main() {
    println!("Please enter the number of items: ");

    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("Failed to read line");
    let n = n.trim().parse().expect("Please enter the number");

    println!("{}", fibonacci(n));
}

fn fibonacci(n: i32) -> i64 {
    if n == 0 {
        0
    } else if n == 1 {
        1
    } else {
        fibonacci(n - 1) + fibonacci(n - 2)
    }
}
