/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-04-29 00:00:26
 * @ Modified by: KaiserLancelot
 * @ Modified time: 2020-05-14 04:19:07
 */
use std::io;

fn main() {
    println!("Please enter Celsius: ");

    let mut celsius = String::new();
    io::stdin()
        .read_line(&mut celsius)
        .expect("Failed to read line");
    let celsius: i32 = celsius.trim().parse().expect("Please enter number");

    let fahrenheit = 9 * celsius / 5 + 32;

    println!("Fahrenheit: {}", fahrenheit);
}
