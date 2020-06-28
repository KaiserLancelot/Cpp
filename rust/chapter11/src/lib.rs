#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

pub fn add_two(a: i32) -> i32 {
    internal_adder(a, 2)
}

fn internal_adder(a: i32, b: i32) -> i32 {
    a + b
}

// 单元测试(unit tests)与集成测试(integration tests)
// 单元测试倾向于更小而更集中, 在隔离的环境中一次测试一个模块, 或者是测试私有接口
// 而集成测试对于你的库来说则完全是外部的.它们与其他外部代码一样, 通过相同的方式使用你的代码
// 只测试公有接口而且每个测试都有可能会测试多个模块, 集成测试的目的是测试库的多个部分能否一起正常工作
// 一些单独能正确运行的代码单元集成在一起也可能会出现问题, 所以集成测试的覆盖率也是很重要的

// 单元测试与他们要测试的代码共同存放在位于 src 目录下相同的文件中
// 规范是在每个文件中创建包含测试函数的 tests 模块, 并使用 cfg(test) 标注模块
// cfg 属性代表 configuration, 它告诉 Rust 其之后的项只应该被包含进特定配置选项中
// 测试模块的 #[cfg(test)] 注解告诉 Rust 只在执行 cargo test 时才编译和运行测试代码
// 与之对应的集成测试位于另一个文件夹, 不需要 #[cfg(test)] 注解
#[cfg(test)]
mod tests {
    // Rust 中的测试就是一个带有 test 属性注解的函数
    // 属性(attribute)是关于 Rust 代码片段的元数据
    // 当使用 cargo test 命令运行测试时, Rust 会构建一个测试执行程序用来调用
    // 标记了 test 属性的函数, 并报告每一个测试是通过还是失败
    // 当测试函数中出现 panic 时测试就失败了
    // 每一个测试都在一个新线程中运行, 当主线程发现测试线程异常了, 就将对应测试标记为失败
    #[test]
    fn it_works() {
        // 被比较的值必需实现了 PartialEq 和 Debug trait
        // 所有的基本类型和大部分标准库类型都实现了这些 trait
        // 通常可以直接在结构体或枚举上添加 #[derive(PartialEq, Debug)] 注解
        assert_eq!(2 + 2, 4, "2 + 2 != {}", 4);
        assert_ne!(2 + 2, 5);
    }

    use super::*;

    #[test]
    // 排除测试
    #[ignore]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };

        assert!(larger.can_hold(&smaller));
    }

    #[test]
    // 这个属性在函数中的代码 panic 时会通过, 而在其中的代码没有 panic 时失败
    // 可以给 should_panic 属性增加一个可选的 expected 参数.测试工具会确保错误信息中包含其提供的文本
    // 如果提供的文本和错误信息不符, 测试失败
    #[should_panic(expected = "panic")]
    fn should_panic() {
        panic!("panic");
    }

    // 不能对这些使用 Result<T, E> 的测试使用 #[should_panic] 注解
    // 这样编写测试来返回 Result<T, E> 就可以在函数体中使用问号运算符
    // 如此可以方便的编写任何运算符会返回 Err 成员的测试
    #[test]
    fn f() -> Result<(), String> {
        if 2 + 2 == 4 {
            Ok(())
        } else {
            Err(String::from("two plus two does not equal four"))
        }
    }
}
