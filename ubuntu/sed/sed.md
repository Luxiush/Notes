## [sed(stream editor)]( https://en.wikipedia.org/wiki/Sed#Mode_of_operation )
* 流编辑器

### 工作原理:
* 将文本逐行读取到`模式空间`(pattern space)中, 接着用sed命令(sed script)进行处理, 然后输出到屏幕开始下一行.
* sed命令是<pattern,action>格式,相当于if语句,用于指明什么时候执行什么指令

### 常用参数
| 参数 | 说明 |
|:---|:---|
| -n | slient模式, 只输出被处理的行 |
| -e | 多点编辑, 在同一行里执行多条命令 |
| -f | 从文件读取sed命令 |
| -i | in-place |
| -r | 直接修改文件内容,不输出 |

### [常用sed命令]( http://blog.csdn.net/wl_fln/article/details/7281986 )
* 命令格式: [n1 [,n2]]function; n1,n2用于指定function执行的时机,通常为行号

#### 常用函数
| function | 说明 |
|:---|:---|
| a | 在当前行之后插入文本 |
| i | 在当前行之前插入文本 |
| c | 替换指定的行 |
| s | 替换指定字符 |
| n | 读入下一行 |
| r <file> | 从file中读取 |
| w <file> | 写文件 |
| p | 打印行 |
| q | 退出 |

#### 替换标记
| 标记 | 说明 |
|:---|:---|
| g | 替换行内所有匹配的字符 |
| p | 打印行 |
| w | 写入文件 |
| \1 | 标记第i个匹配的子表达式 |
| & | 标记整个表达式 |

#### [用法实例]( http://man.linuxde.net/sed )
| ... | ... | ... |
|:---|:---|:---|
| 追加 | sed '/^##/a\aaaa' | 在以##开头的行之后追加aaaa |
| 删除 | sed '/^$d' file.name | 删除空白行 |
| ... | sed '2d' file.name | 删除第2行 |
| ... | sed '2,$d' file.name | 删除第2行到末行 |
| ... | sed '/aaaa/d' file.name | 删除包含aaaa的行,aaaa可以为正则表达式 |
| 替换 | sed 's/aaaa/bbbb/' file.name | 将行中的aaaa替换为bbbb,aaaa可以为正则表达式 |
| ... | sed 's/aaaa/bbbb/g' file.name | 将行中所有的aaaa替换为bbbb |
| ... | sed 's/aaaa/bbbb/3g' file.name | 从第3处匹配开始替换 |
| ... | sed 's/aaaa/[&]/g' file.name | 将aaaa替换为[aaaa] |
| ... | sed 's/\(aaa\)bbb/\1ccc/g' file.name | 将aaabbb替换为aaaccc |
| 选定行的范围 | sed -n '/aaaa/,/bbbb/p' file.name | 输出在aaaa和bbbb所指定范围内的行 |
| ... | sed -n '5,/aaaa/p' file.name | 输出从第5行开始到第一个包含aaaa的行之间的所有行 |
| ... | sed '/mmm/,/nnn/s/aaa/bbb/g' file.name | 将mmm到nnn的所有行的aaa替换为bbb |
| 下一行 | sed -n '/aaa/{n;p}' file.name | 输出包含aaa的行的下一行 |
| 多重编辑 | sed -e '1,3d' -e 's/aaa/bbb/g' file.name | 删除1-3行,然后把其余行的aaa替换为bbb |
