| mode  | openmode & ~ate                       | 若文件已存在的动作 | 若文件不存在的动作 |
| ----- | ------------------------------------- | ------------------ | ------------------ |
| "r"   | in                                    | 从头读取           | 打开失败           |
| "w"   | out, out\|trunc                       | 销毁内容           | 创建新文件         |
| "a"   | app, out\|app                         | 后附到文件         | 创建新文件         |
| "r+"  | out\|in                               | 从头读取           | 错误               |
| "w+"  | out\|in\|trunc                        | 销毁内容           | 创建新文件         |
| "a+"  | out\|in\|app, in\|app                 | 写入到结尾         | 创建新文件         |
| "rb"  | binary\|in                            | 从头读取           | 打开失败           |
| "wb"  | binary\|out, binary\|out\|trunc       | 销毁内容           | 创建新文件         |
| "ab"  | binary\|app, binary\|out\|app         | 写入结尾           | 创建新文件         |
| "r+b" | binary\|out\|in                       | 从头读取           | 错误               |
| "w+b" | binary\|out\|in\|trunc                | 销毁内容           | 创建新文件         |
| "a+b" | binary\|out\|in\|app, binary\|in\|app | 写入到结尾         | 创建新文件         |