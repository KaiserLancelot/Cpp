use std::io;

fn main() {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("read failed");
    println!("{}", pig_latin(str.trim()).trim());
}

fn pig_latin(str: &str) -> String {
    let words: Vec<&str> = str.split_whitespace().collect();
    let mut result = String::new();

    for word in words {
        match word.chars().next() {
            Some(c) => {
                if vowel(c) {
                    result.push_str(&format!("{}-hay ", word)[..]);
                } else {
                    result.push_str(&format!("{}-{}ay ", &word[1..], &word[0..1])[..]);
                }
            }
            None => (),
        }
    }

    result
}

fn vowel(c: char) -> bool {
    c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
}
