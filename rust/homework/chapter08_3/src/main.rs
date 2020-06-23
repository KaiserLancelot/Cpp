use std::collections::HashMap;
use std::io;

fn main() {
    let mut map: HashMap<String, Vec<String>> = HashMap::new();

    loop {
        let mut str = String::new();
        io::stdin().read_line(&mut str).expect("read failed");
        if str.trim() == "quit" {
            break;
        }
        add_employee(str.trim(), &mut map);
    }

    for (key, value) in map.iter_mut() {
        value.sort_unstable();
    }

    println!("{:?}", map);
}

fn add_employee(str: &str, map: &mut HashMap<String, Vec<String>>) {
    let (employee, department) = process_command(str);
    let v = map.entry(department).or_insert(Vec::new());
    v.push(employee);
}

fn process_command(str: &str) -> (String, String) {
    let v: Vec<&str> = str.split_whitespace().collect();

    assert_eq!(v.len(), 4);
    assert_eq!(v[0], "Add");
    assert_eq!(v[2], "to");

    (v[1].to_string(), v[3].to_string())
}
