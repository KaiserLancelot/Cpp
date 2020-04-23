QIODevice::NotOpen	    未打开
QIODevice::ReadOnly	    以只读方式打开
QIODevice::WriteOnly	以只写方式打开
QIODevice::ReadWrite	以读写方式打开
QIODevice::Append	    以追加的方式打开, 新增加的内容将被追加到文件末尾
QIODevice::Truncate	    以截断的方式打开, 在写入新的数据时会将原有数据全部清除
QIODevice::Text	        在读取时, 将行结束符转换成 \n ;在写入时
                        将行结束符转换成本地格式
QIODevice::Unbuffered	忽略缓存