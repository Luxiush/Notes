#!/bin/bash
# 多进程并发demo, 进程池, 通过fifo向子进程分配任务

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

function subprocess()
{
    _id=$1

    echo "task$_id: start"
    
    while read -u9 _cmd; do
        echo "task$_id: $_cmd"
        
        if [ "$_cmd" == "EOF" ]; then
            echo "$_cmd" >&9
            break
        fi
        
        # $_cmd
        sleep $((1+$RANDOM%10))
    done
    
    echo "task$_id: finish"
}

cat $cmd_list >&9

for taskid in $(seq $parallel_cnt); do
    {
        subprocess $taskid
    }&
    sleep 1
done

echo "Waiting"
wait
exec 9>&-

echo "Done"

