## tmux
-  终端复用, 在一个连接中开启多个控制台. 即使非正常掉线，也能保证当前的任务运行，这一点对于 远程SSH访问特别有用，网络不好的情况下仍然能保证工作现场不丢失!
> 使用它最直观的好处就是，通过一个终端登录远程主机并运行tmux后，在其中可以开启多个控制台而无需再“浪费”多余的终端来连接这台远程主机

| 单元模块 |  |
|:---|:---|
| server | 一个tmux命令一个server |
| session会话 | 一个server包含多个session |
| window窗口 | 一个session包含多个window |
| pane面板 | 一个window包含多个pane |


| 常用命令(默认) |  |
|:---|:---|
| ctrl-b | 激活控制台 |
| ? | 显示帮助 |
| 面板 |  |
| 方向键 | 在各个面板之间切换 |
| ctrl-方向键 | 调整面板大小 |
| ; | 切换到上一个使用的面板 |
| " | 横向分屏 |
| % | 纵向分屏 |
| exit | 关闭面板,直接在shell中输入 |
| { | 上下交换两个面板 |
| } | 左右交换两个面板 |
| ! | 把当前面板变成一个新窗口 |
| 窗口 |  |
| c | 新窗口 |
| & | 确认后关闭当前窗口 |
| p | 上一个窗口 |
| n | 下一个窗口 |
| 会话 |  |
| d | 暂时脱离当前会话, `tmux a`返回 |


### 复制模式
- copy-mode将快捷键设置为vi模式.()可以像vi那样移动光标,也可以像vi一样查找)
```
setw -g mode-keys vi
```
步骤:
    - prefix-[, 进入复制模式
    - space开始复制
    - 移动光标选择区域
    - Enter复制并退出复制模式
    - prefix-], 粘贴


### [个性化配置](http://mingxinglai.com/cn/2012/09/tmux/)
- 配置文件: `~/.tmux.conf`
- 重新设置前缀
```
# 设置前缀为Ctrl + x
set -g prefix C-x

# 解除Ctrl+b 与前缀的对应关系
unbind C-b
```
> 配置完以后，重启tmux起效，或者先按C+b，然后输入：，进入命令行模式， 在命令行模式下输入：source-file ~/.tmux.conf

- 面板切换
```
# up
bind-key k select-pane -U
# down
bind-key j select-pane -D
# left
bind-key h select-pane -L
# right
bind-key l select-pane -R
```

- 调整面板大小
```
# resize pane
bind -r ^k resizep -U 10    # upward (prefix Ctrl+k)
bind -r ^j resizep -D 10    # downward (prefix Ctrl+j)
bind -r ^h resizep -L 10    # to the left (prefix Ctrl+h)
bind -r ^l resizep -R 10    # to the right (prefix Ctrl+l)
```

- 上一个窗口
```
#select last window
bind-key / select-window -l
```


### 关于tmux乱码
tmux, 乱码已成往事: <http://popozhu.github.io/2013/11/06/tmux%EF%BC%8C%E4%B9%B1%E7%A0%81%E5%B7%B2%E6%88%90%E5%BE%80%E4%BA%8B/>

.
