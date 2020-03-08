## Shell Script
- See [Advanced Bash-Scripting Guide]( https://www.tldp.org/LDP/abs/html/ ) for more information

### shel调用调用脚本的几种方式
#### 1. fork
- 默认, 生成一个子进程去执行, 但是父进程会等子进程执行完成后再继续
```
./filename.sh

/bin/bash ./filename.sh
```

#### 2. source
- 在当前进程中执行脚本中的命令(类似于`c`里面的`include`), pid不变, 环境变量也会继承.

- 例: 
```
$ source <file_name>
$ . <file_name>
```

#### 3. exec
- 替换当前进程的镜像, pid不变, 但是环境环境变量会重置.
- 新脚本执行完后直接退出, 不再返回exec调用的地方
- (除此之外, exec还可以用于io重定向)


```shell
files=`ls -a`   # 数组
echo "files in current directory: "
for file in ${files}; do
    echo "${file}"
done

```

### 关于子shell
- 执行外部命令时会创建子shell, 内部命令则不会
- 外部命令: 用户自定义脚本, 系统的可执行文件比如`/bin/`目录下的
- 内部命令: shell自己的一些`语句`, 如: for, let, shift等.

- `$BASH_SUBSHELL`: 查看从当前进程开始的子shell层数
- `$BASHPID`: 当前所处bash的pid


### 多进程
- `(cmd1)`, 将一组cmd放到子shell中执行, 会继承父shell打开的文件(fdtable)
- `cmd&`, 将cmd放到后台去执行
- `jobs`, 查看当前的各个任务
- `fg [jobid]`, 将jobid放到前台执行
- `bg [jobid]`, 将jobid放到后台执行
- `ctrl-z`, 暂停当前job


#### 多进程并发
##### 方案1: fifo
- [multiprocess.sh]( ./demo/multiprocess.sh )
- [multiprocess2.sh]( ./demo/multiprocess.sh )

##### 方案2: xargs -p


##### 方案3: pallel
- 略



---
### 变量
#### 变量的作用域
- 全局变量, **默认**, 只能在当前shell进程中使用
- 局部变量, local, 只能在函数内部使用
- 环境变量, export, 在子进程中还可以使用
- unset, 取消某个变量

```
var="global"
local var_local="local"
export var_env="env"
```

- shell定义的变量默认为全局变量, 这就意味着, 在函数里面定义的变量出了函数还可以访问.


#### 字符串
单引号:
- 单引号里的任何字符都会`原样输出`，单引号字符串中的变量是无效的
- 单引号字串中不能出现单引号（对单引号使用转义符后也不行）

双引号:
- 双引号里可以有变量
- 双引号里可以出现转义字符

```
string="abcdefg"

# 获取字符串长度
echo ${#string} # 4

# 提前子字符串
echo ${string:1:4} # bcde

# 提取最后几个字符
echo ${string: -3} # dfg

# 字符串查找替换
FILE="example.tar.gz"
echo "${FILE%%.*}"     # 取头: example
echo "${FILE%.*}"      # 去尾: example.tar
echo "${FILE#*.}"      # 去头: tar.gz
echo "${FILE##*.}"     # 取尾: gz
```

#### 数组
- `只支持`一维数组

```shell
arr=("00" "aa" "bb" "cc" "dd")
arr[5]="ee"
arr[6]="ff"

echo "arr: ${arr[@]}"
echo "arr[3]: ${arr[3]}"
echo "length of arr: ${#arr[@]}"
```


### 参数传递

| 参数 | 说明 |
|:---|:---|
| $0 | 当前脚本名 |
| $i | 第i个参数 |
| $@, $* | 传递给本脚本/函数的所有所有参数 |
| $# | 传递给脚本的参数个数(不包括$0) |
| $$ | 当前脚本的进程ID |
| $? | 最后命令的退出状态 |

##### `$@` & `$*`
- 不被引号`""`包含时, 都以`"$1" "$2" … "$n"` 的形式输出所有参数
- 被引号`""`包含时, 前者会将各个参数分开: `"$1" "$2" … "$n" `, 而者则将各个参数作为一个整体: `"$1 $2 … $n"`

### 运算符
- 算术运算符: 原生bash不支持数学运算, 但是可以用`expr`命令来完成表达式求值
- 逻辑运算符: `&&`(AND), `||`(OR)
- 布尔运算符: `!`(not), `-o`(or), `-a`(and)
- 关系运算符(只支持数字): -eq(==), -ne(!=), -gt(>), -lt(<), -ge(>=), -le(<=)
- 字符串运算符: =(相等), !=(不等), -z(长度为0), -n(长度不为0)

- `[[` & `[`: 前者是后者的扩充, 前者中的的`>`和`<`不需要转义, 前者的逻辑运算用`||`和`&&`, 而后者用的是`-o`和`-a`

```shell
a="aaaa"
b="bbbb"
if [ -z $a ]; then
    echo "a 的长度为0"
else
    echo "a 的长度不为0"
fi

if [ $b ]
then
    echo "b不为空"
else
    echo "b为空"
fi
```

- 文件测试运算符:
-e(文件存在), -s(文件不为空), -d(目录), -f(普通文件), -r(可读), -w(可写), -x(可执行), -L(软连接)
```shell
file_name=$1
if [ ! -e ${file_name} ]; then
    echo "file ${file_name} is not exist."
elif [ ! -s ${file_name} ]; then
    echo "file ${file_name} is empty."
fi
```


### 常用命令

#### echo
```shell
# -e开启转义

echo -e "aaa\nbbb"
# aaa
# bbb

echo -e "aaa\c"
echo "bbb"
# aaabbb
```

#### printf
- 与c中的基本一致
```shell
printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg   # - 表示左对齐
printf "%-10s %-8s %-4.2f\n" 郭靖 男 66.1234
printf "%-10s %-8s %-4.2f\n" 杨过 男 48.6543
printf "%-10s %-8s %-4.2f\n" 郭芙 女 47.9876
# 姓名     性别   体重kg
# 郭靖     男      66.12
# 杨过     男      48.65
# 郭芙     女      47.99

```

#### seq
- 用于生成序列
```
$ seq [last]
$ seq [first] [last]
$ seq [first] [increment] [last]

```

- 例:
```
for i in $(seq 10); do
    echo "hello $i" # 1 2 3 4 5 6 7 8 9 10
done
```

#### shift
- 将整个参数列列表左移
```
function test_shift()
{
    echo "before shift: $*"
    shift 2                 # shift [n], 整个参数列表左移n位
    echo "after shift: $*"

    # $ test_shift a b c d
    # before shift: a b c d
    # after shift: c d
}
```

---

### 基本语句
#### if-else
...

#### for
- break, continue
```shell
for((i=0;i<10;i++)); do
    echo -e "$i\t\c"
done


arr=(aa bb cc dd)
for s in $arr; do
    echo -e "$s\t\c"
done

```

#### while
```shell
i=1
while (( $i <= 5 )); do
    echo -e "$i \c"
    i=$(($i+1))
done
```

#### case
```shell
read aNum
case $aNum in
    1)  echo '你选择了 1';;
    2)  echo '你选择了 2'
    ;;
    3)  echo '你选择了 3'
    ;;
    4)  echo '你选择了 4'
    ;;
    *)  echo '你没有输入 1 到 4 之间的数字'
    ;;
esac
```

#### 函数
```
function func()
{
    echo $*
}

func aa bb cc
```

.
