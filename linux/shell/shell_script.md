## Shell Script

```shell
files=`ls -a`   # 数组
echo "files in current directory: "
for file in ${files}; do
    echo "${file}"
done

```

### 变量

#### 变量声明


#### 字符串
单引号:
- 单引号里的任何字符都会`原样输出`，单引号字符串中的变量是无效的
- 单引号字串中不能出现单引号（对单引号使用转义符后也不行）

双引号:
- 双引号里可以有变量
- 双引号里可以出现转义字符

```shell
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


### 基本语句
#### if-else
...

#### for
- break, continue
```shell
for((i=0;i<10;i++)); do
    echo -e "$i\t\c"
done

###
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

.
