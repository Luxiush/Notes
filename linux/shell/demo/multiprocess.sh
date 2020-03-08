#!/bin/bash
#!/bin/bash
# 多进程并发demo, 通过fifo控制并发数
# 主进程每次从fifo读出一行就创建一个子进程, 如果fifo为空则主进程阻塞
# 子进程执行完成时向fifo写入一行

if [ $# -ne 2 ]; then
    echo "Usage: `basename $0` [parallel_cnt] [cmd_list.txt]"
    exit -1
fi

parallel_cnt=$1 # 并发数
cmd_list=$2     # 需要并发执行的命令文件

fifotmp="tmp.fifo"
mkfifo $fifotmp
exec 9<>$fifotmp
rm -f $fifotmp

seq $parallel_cnt >&9

function subprocess()
{
    _id=$1
    shift 1 # 整个参数列表左移1位
    _cmd="$*"
    
    echo "task$_id: $_cmd"
    # $_cmd
    sleep $((1+$RANDOM%10))
    echo "task$_id: done"
}

while read cmd; do
    if [ -z "$cmd" ]; then  # 记得加引号, 否则读到"#"开头的行就出问题了
        continue
    elif [ "${cmd:0:1}" == "#" ]; then  # 字符串截取: <http://c.biancheng.net/view/1120.html>
        continue
    fi
    
    read -u9 taskid
    {
        subprocess $taskid $cmd
        echo $taskid >&9
    }&
    sleep 1
done < $cmd_list

echo "Waiting"
wait
exec 9>&-

echo "Done"

