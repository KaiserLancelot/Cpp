### 1. 字面类型

https://zh.cppreference.com/w/cpp/named_req/LiteralType

- 可为 cv 限定的 void (从而 constexpr 函数能返回 void)
- 标量类型
- 引用类型
- 字面类型的数组
- 可有 cv 限定的类类型, 并拥有下列全部属性:
  - 拥有 constexpr 析构函数
  - 是以下之一
    - 聚合类型
    - 或拥有至少一个 constexpr 构造函数(可为模板)且非复制或移动构造函数
    - 或为闭包类型
  - 对于联合体, 至少有一个非静态数据成员是非 volatile 字面类型
  - 对于非联合体, 所有非静态数据成员和基类是非 volatile 字面类型

### 2. constexpr 变量

https://zh.cppreference.com/w/cpp/language/constexpr

- 其类型必须是字面类型
- 它必须被立即初始化
- 其初始化的全表达式, 包括所有隐式转换, 构造函数调用等, 都必须是常量表达式
- 它必须拥有常量析构, 即:
  - 它既非类类型亦非其(可能多维的)数组, 或
  - 它是类类型或其(可能多维的)数组, 该类类型拥有 constexpr 析构函数

### 3. constexpr 函数

- 不能是协程
- 每个参数和返回值必须是字面类型
- 函数体不含
  - goto 语句
  - 拥有除 case 和 default 之外的标号的语句
  - 非字面类型, 静态或线程存储期的变量定义
    (=default 或=delete 的函数体不含上述内容)

注意, 如果任何参数都不能使函数提供 constexpr, 则程序为 ill-formed no diagnostic required
(例如调用了一个 non-constexpr 函数)

尽管在 constexpr 函数中允许 try 块与内联汇编, 常量表达式中仍然不允许抛异常或执行汇编
若 constexpr 变量拥有常量析构, 则无需为调用其析构函数而生成机器码

### 4. constexpr 构造函数

- 满足 constexpr 函数的要求
- 该类无虚基类
- 每个被选用于初始化非静态成员和基类的构造函数必须是 constexpr 构造函数

constexpr 构造函数允许用于非字面类型的类.例如, std::unique_ptr 的默认构造函数是 constexpr
允许常量初始化

### 5. constexpr 析构函数

- 满足 constexpr 函数的要求
- 该类无虚基类
- 每个用于销毁非静态数据成员与基类的析构函数必须为 constexpr 析构函数

### 6. 常量初始化

https://zh.cppreference.com/w/cpp/language/constant_initialization

静态及线程局部对象的常量初始化取代零初始化, 并早于所有其他初始化进行
如果编译器可以保证其值与当遵循初始化的标准顺序时的结果相同, 则允许其用常量初始化对其他的静态及线程局部对象进行初始化
实践中, 常量初始化在编译时进行, 并将预先计算的对象表示作为程序映像的一部分(如 .data 段)存储.若变量既为 const 又被常量初始化, 则其对象表示可存储于程序映像的只读段(如 .rodata 段)
