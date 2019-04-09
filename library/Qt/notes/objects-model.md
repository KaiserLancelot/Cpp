在创建 QObject 对象时, 可以提供一个其父对象, 我们创建的
这个 QObject 对象会自动添加到其父对象的 children 列表.
当父对象析构的时候, 这个列表中的所有对象也会被析构

当一个 QObject 对象在堆上创建的时候, Qt 会同时为其创建一个对象树
销毁这些对象的顺序是未指定的.Qt 保证, 任何对象树中的 QObject 对象
被 delete 的时候, 如果这个对象有 parent , 则自动将其从 parent 的
children 列表中删除;如果有孩子, 则自动 delete 每一个孩子.