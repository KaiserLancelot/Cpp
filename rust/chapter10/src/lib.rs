use std::fmt::{Debug, Display};

pub trait Summary {
    fn summarize_author(&self) -> String {
        String::new()
    }

    fn summarize(&self) -> String {
        // 可以提供默认实现
        // 默认实现允许调用相同 trait 中的其他方法, 哪怕这些方法没有默认实现
        format!("(Read more from {}...)", self.summarize_author())
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

// 不能为外部类型实现外部 trait
// 例如, 不能在 该 crate 中为 Vec<T> 实现 Display trait
impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }
}

// 有多个, 通过 + 连接
pub fn notify(item: impl Summary + Display) {
    println!("Breaking news! {}", item.summarize());
}

// trait bound
pub fn notify2<T: Summary + Display>(item: T) {
    println!("Breaking news! {}", item.summarize());
}

fn some_function<T: Display + Clone, U: Clone + Debug>(t: T, u: U) -> i32 {
    0
}

// 和上面的等价
fn some_function2<T, U>(t: T, u: U) -> i32
where
    T: Display + Clone,
    U: Clone + Display,
{
    0
}

// 只适用于返回单一类型的情况
fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("horse_ebooks"),
        content: String::from("of course, as you probably already know, people"),
        reply: false,
        retweet: false,
    }
}
