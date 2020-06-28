use chapter11;

// 这样命名告诉 Rust 不要将 common 看作一个集成测试文件
mod common;

// tests 文件夹在 Cargo 中是一个特殊的文件夹, Cargo 只会在运行 cargo test 时编译这个目录中的文件
// 可以随意在这个目录中创建任意多的测试文件, Cargo 会将每一个文件当作单独的 crate 来编译
#[test]
fn it_adds_two() {
    common::setup();
    assert_eq!(4, chapter11::add_two(2));
}
