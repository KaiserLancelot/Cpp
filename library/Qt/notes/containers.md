Qt 的容器都没有集成 QObject , 都提供了隐式数据共享 (implicit-sharing), 也就是 copy on write
对象共享一份数据时, 如果数据不改变, 就不进行数据的复制, 需要进行改变是才进行复制
具有数据共享能力的类包含了一个指向共享数据块的指针.这个数据块包含了数据本身以及数据的引用计数
随机访问尽可能使用 at() 而不是 operator[], 使用迭代器时尽可能使用 const 的而不是非 const 的

* QList
它是最通用的容器类.随机访问 O(1) , 向首尾添加元素是均摊 O(1), 向中间插入是 O(n)
QStringList 继承自 QList<QString>

* QLinkedList
同 std::list

* QVector
同 std::vector

* QStack
QVector 的子类

* QQueue
QList 的子类

以下和标准库中的类似
* QSet
* QMap
* QMultiMap
* QHash
* QMultiHash
