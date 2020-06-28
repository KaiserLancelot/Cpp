use chapter10::{Summary, Tweet};
use std::fmt::Display;

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];
    // 使用 & 即可获取 slice, 只想读的话通常使用 slice 作为参数
    println!("{}", largest(&number_list));

    let integer = Point { x: 1, y: 2 };
    let float = Point { x: 1.0, y: 2.0 };

    let p1 = Point2 { x: 5, y: 10.4 };
    let p2 = Point2 { x: "Hello", y: 'c' };

    let p3 = p1.mixup(p2);
    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);

    let tweet = Tweet {
        username: String::from("horse_ebooks"),
        content: String::from("of course, as you probably already know, people"),
        reply: false,
        retweet: false,
    };

    // 想使用 summarize(), 首先需要将 Summary trait 引入作用域
    println!("1 new tweet: {}", tweet.summarize());

    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);

    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    let i = ImportantExcerpt {
        part: first_sentence,
    };

    // 静态生命周期
    // 'static, 其生命周期能够存活于整个程序期间. 所有的字符串字面值都拥有 'static 生命周期
    let s: &'static str = "I have a static lifetime.";
}

// 使用泛型类型参数的代码相比使用具体类型并没有任何速度上的损失
// Rust 通过在编译时进行泛型代码的单态化（monomorphization）来保证效率
// 单态化是一个通过填充编译时使用的具体类型, 将通用代码转换为特定代码的过程
struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

struct Point2<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point2<T, U> {
    fn mixup<V, W>(self, other: Point2<V, W>) -> Point2<T, W> {
        Point2 {
            x: self.x,
            y: other.y,
        }
    }
}

enum Enum<T> {
    Some(T),
    None,
}

fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}

fn largest2<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}

struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
}

impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x = {}", self.x);
        } else {
            println!("The largest member is y = {}", self.y);
        }
    }
}

// blanket implementations
// impl<T: Display> ToString for T {
//     // --snip--
// }

// 生命周期语法是用于将函数的多个参数与其返回值的生命周期进行关联的
// 当指定了泛型生命周期后函数也能接受任何生命周期的引用
// 生命周期注解描述了多个引用生命周期相互的关系, 而不影响其生命周期
// longest 函数定义指定了签名中所有的引用必须有相同的生命周期 'a
// 当具体的引用被传递给 longest 时, 被 'a 所替代的具体生命周期是 x 的作用域
// 与 y 的作用域相重叠的那一部分.换一种说法就是泛型生命周期 'a 的具体生命周期等同于
// x 和 y 的生命周期中较小的那一个.返回的引用值保证在 x 和 y 中较短的那个生命周期结束之前保持有效
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

// 没有生命周期注解却能编译 -- 生命周期省略规则

// 函数或方法的参数的生命周期被称为输入生命周期(input lifetimes)
// 而返回值的生命周期被称为输出生命周期(output lifetimes)

// 第一条规则是每一个是引用的参数都有它自己的生命周期参数
// 第二条规则是如果只有一个输入生命周期参数，那么它被赋予所有输出生命周期参数
// 第三条规则是如果方法有多个输入生命周期参数并且其中一个参数是 &self 或 &mut self
// 说明是个对象的方法(method), 那么所有输出生命周期参数被赋予 self 的生命周期
// 编译器使用所有已知的生命周期省略规则, 仍不能计算出签名中所有引用的生命周期时, 报错
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

// 这个注解意味着 ImportantExcerpt 的实例不能比其 part 字段中的引用存在的更久
struct ImportantExcerpt<'a> {
    part: &'a str,
}

impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
        3
    }

    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}

fn longest_with_an_announcement<'a, T>(x: &'a str, y: &'a str, ann: T) -> &'a str
where
    T: Display,
{
    println!("Announcement! {}", ann);
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
