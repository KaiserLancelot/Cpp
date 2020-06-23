use std::collections::HashMap;

fn main() {
    let v = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9];

    println!("{}", mean(&v));
    println!("{}", median(&v));
    println!("{}", mode(&v));
}

fn mean(v: &Vec<i32>) -> f64 {
    if v.len() == 0 {
        return 0.0;
    }

    let mut sum = 0;
    for &entry in v.iter() {
        sum += entry;
    }

    (sum as f64) / (v.len() as f64)
}

fn median(v: &Vec<i32>) -> f64 {
    let mut sorted = v.clone();
    sorted.sort_unstable();

    let size = sorted.len();
    if size % 2 == 0 {
        (sorted[size / 2] as f64 + sorted[size / 2 - 1] as f64) / 2.0
    } else {
        sorted[size / 2] as f64
    }
}

fn mode(v: &Vec<i32>) -> i32 {
    let mut map = HashMap::new();
    for &entry in v.iter() {
        let value = map.entry(entry).or_insert(0);
        *value += 1;
    }

    let mut max_key = 0;
    let mut max_value = 0;
    for (&key, &value) in map.iter() {
        if value > max_value {
            max_value = value;
            max_key = key;
        }
    }

    max_key
}
