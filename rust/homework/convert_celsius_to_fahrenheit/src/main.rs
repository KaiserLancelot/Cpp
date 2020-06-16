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
