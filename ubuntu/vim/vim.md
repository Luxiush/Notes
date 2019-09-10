## vim
### 常用插件:
 * vim-colors-solarized   配色
 * vim-ariline            增强的状态栏（类似powerline）
 * vim-tagbar             tag显示列表
 * ctrlp.vim              模拟sublime的ctrl-p快捷键，支持模糊搜索打开文件
 * ctrlp-cmatcher         对ctrlp.vim模糊搜索算法改进的插件
 * delimitMate            <(["等括号自动补全插件（模拟sublime）
 * vim-surround           快速修改括号的插件 例：<abc> 变为 (abc) 或 "abc"
 * vim-commentary         批量注释的插件
 * vim-easymotion         快速跳转光标的插件
 * vim-easy-align         进行缩进对齐的插件


### Overview
Ctrl+s 锁定屏幕
Ctrl+q 解锁
### vi工作模式
1. 普通模式:
由Shell进入vi编辑器时，首先进入普通模式。在普通模式下，从键盘输入任何字符都被当作命令来解释。
2. 编辑模式:
编辑模式主要用于文本的编辑。该模式下用户输入的任何字符都被作为文件的内容保存起来，并在屏幕上显示出来。
3. 命令模式:
命令模式下，用户可以对文件进行一些高级处理。尽管普通模式下的命令可以完成很多功能，但要执行一些如字符串查找、替换、显示行号等操作还是必须要进入命令模式。

* 工作模式切换：
```
普通模式 -- i, c, o --> 编辑模式
   | <------ Esc ---------|
普通模式 ------ : ----> 命令模式
   | <------ Esc ---------|
```

> 在普通模式下输入 i(插入)、c(修改)、o(另起一行) 命令时进入编辑模式；按 esc 键退回到普通模式。

> 在普通模式下输入冒号(:)可以进入命令模式。输入完命令按回车，命令执行完后会自动退回普通模式。

> 提示：如果不确定当前处于哪种模式，按两次 Esc 键将回到普通模式。


### vi 常用命令
#### 普通模式

| 命令 | 说明 |
|:---|:---|
| 光标移动 | . |
| h,j,k,l | 左,下,上,右 |
| 0,$ | `行首`,行末 |
| ^ | 移动光标到本行的`第一个非空字符` |
| w | 到下一个词的第一个字母 |
| e | 到当前词的最后一个字母 |
| b | 上一个单词的开头 |
| ngg | 文件第n行 |
| G | 文件最后一行 |
| H,M,L | 屏幕第一行,中间,最后一行 |
| {,} | 上一空行, 下一空行 |
| 翻屏 | . |
| zz,zt,zb| 将`当前行`移动到屏幕中间,顶(top)端,底(bottom)端|
| ctrl-u,d | 上,下滚半屏 |
| ctrl-e,y | 上下滚一行 |
| 插入 | . |
| i,a | 在当前位置之前,后插入 |
| I,A | 在当前行的行首,末插入 |
| o,O | 在当前行的上,下一行插入 |
| 替换 . |
| r | 替换当前字母 |
| nr | 替换n个字母 |
| 删除/剪切 | . |
| dd | 删除(剪切)整行 |
| d$,dw | ...... |
| x | 剪切光标指向字符 |
| nx | 剪切光标指向的后n个字符 |
| J | 删除本行换行符, 和下一行合并 |
| 改动(change) | 删除并进入插入模式 |
| cw,c0,cG | ...... |
| 复制 | . |
| yy | 复制当前行到缓冲区 |
| ye,yw,yb | ...... |
| nyy | 复制n行到缓冲区 |
| "y | 复制到操作系统剪贴板 |
| "ny | 复制n行到操作系统剪贴板 |
| 粘贴 | . |
| p | 将缓冲区中的内容粘贴到光标`后面` |
| P | 粘贴到光标`前面` |
| 搜索 | . |
| * | 当光标停留在一个单词上，* 键会在文件内搜索该单词，并跳转到下一处 |
| # | 当光标停留在一个单词上，# 在文件内搜索该单词，并跳转到上一处 |
| /pattern | 从光标开始处向`后`搜索pattern |
| ?pattern | 从光标开始处向`前`搜索pattern |
| n | 在同一方向重复上一次搜索命令(下一个) |
| N | 在反方向上重复上一次搜索命令(前一个) |
| \<, \> | 匹配一个单词的开头,结尾 |
| 撤销,恢复 | . |
| u | `撤消`前一条命令的结果 |
| Ctrl-r | `恢复`刚刚撤销的动作 |
| . | `重复`最后一条修改正文的命令 |
| 排版 | . |
| <<,>> | 向左,右缩进一个shiftwidth |


#### 命令模式

| 命令 | 说明 |
|:---|:---|
| :e! | edit, 重新加载当前文档, 并放弃已做的改动 |
| :e! <file | 放弃修改, 打开新的文件 |
| :q | 退出 |
| :q! | 放弃修改,强制退出 |
| :qa | 关闭所有文件(a:all) |
| :wq | 保存并退出 |
| :w | write,将修改写入原始文件 |
| :m,nw <file> | 将第m行至第n行的内容写入<file> |
| :r | read |
| :r <file_name> | 插入文件 |
| :r! <command> | 插入<command>的输出 |
| 可视化 | . |
| :v | 可视化选择 |
| 查找替换 | . |
| :s/p1/p2/g | 将当前行中所有p1均用p2替代 |
| :n1,n2s/p1/p2/g | 在n1到n2行内执行替换操作 |
| :%s/p1/p2/g | 将文件中所有p1均用p2替换 |
| :g/p1/s//p2/g | 同上 |
| :%s/p1/p2/gc | 将文件中所有p1均用p2替换, 在替换的时候需要确认 |
| :%s/cout/\/\/ &/gc | 将cout注释掉,(&标记整个表达式) |
| :%s/aaa_\(bbb\)/\1/gc | 将aaa_bbb替换成bbb,(\1标记第一个子表达式) |
| :g/^".*/d | 删除以"开头的行 |
| shell切换 | . |
| :!<shell_command> | 执行完 <shell_command> 后回到vim |
| 分屏 | . |
| :split | 上下分屏 |
| :vs | 左右分屏 |
| Ctrl-w-w | 按逆时针顺序在各个分屏之间跳转 |
| Ctrl-w-k,j,h,l | 在各个分屏之间跳转 |
| Ctrl-w-<, Ctrl-w-> | 左右扩展 |
| Ctrl-w-+, Ctrl-w-- | 上下扩展 |
| Ctrl-w-= | 让所有分屏高度一致 |
| 多标签 | . |
| :tabnew | 新建一个tab |
| :tabs | 查看所有tab列表, ngt跳转到第n个tab |
| gt(:tabp) | 前一个tab |
| gT(:tabn) | 下一个tab |
| 目录 | . |
| :E, :Ve, Se | 打开目录 |
| 标记 | . |
| ma,mb...mz | 标记光标所在位置 |
| `a,`b,`,`z | 回到标记位置 |
| ctrl+^ | 在最近两个缓冲区间切换 |
| ctrl+i,o | go back, go forward |

- [标记]( http://blog.csdn.net/u010956473/article/details/74087608 )

- [gf]( https://stackoverflow.com/questions/3554719/find-a-file-via-recursive-directory-search-in-vim ): find-a-file-via-recursive-directory-search



### vim 宏
- 在正常模式下（非insert模式、非visual模式）按下q键盘
- 选择a-z或0-9中任意一个作为缓冲器的名字，准备开始录制宏
- 正常的操作，此次所有的操作都会被记录在上一步中定义的缓冲器中
- 在非insert模式下输入q停止宏的录制
- 使用@ + 第二步中定义的缓冲器的名字即可

### [自动补全]( https://easwy.com/blog/archives/advanced-vim-skills-auto-complete/ )
- Ctrl-p, Ctr-n: 在当前缓冲区,其它缓冲区,以及当前文件所包含的头文件中查找以光标前关键字开始的单词, Ctrl-p(previous)向上选择, Ctrl-n(next)向下选择.


### vim粘贴时格式混乱
```
:set paste
:set nopaste
```

### 配置
- 全局配置: /etc/vimrc
- 用户配置: ~/.vimrc

- 使配置文件生效: source ~/.vimrc

```
"高亮显示当前行
set cursorline

"高亮显示匹配的括号
set showmatch

"显示行号
set nu

"在缩进和遇到Tab键时使用空格替代
set expandtab   "不替代: noexpandtab  

"设置tba的宽度为4
set tabstop=4

"自动缩进
set ai
set smartindent " 开启新行时使用智能自动缩进
set backspace=indent,eol,start

"统一缩进为4
set softtabstop=4
set shiftwidth=4


"代码补全 <https://zhuanlan.zhihu.com/p/26156186>
set completeopt=preview,menu   
"如果你喜欢回车完成补全，而不是蛋疼的 <c-y> 只需要设置：
inoremap <expr> <CR> pumvisible() ? "\<C-y>" : "\<C-g>u\<CR>"
"如果你需要补全完成时预览窗口自动消失，可以设置：
augroup complete
    autocmd!
    autocmd CompleteDone * pclose
augroup end

```

### Ref
自带教程: `$ vimtutor`

vim-galore-zh_cn: <https://github.com/wsdjeg/vim-galore-zh_cn#%E4%BB%80%E4%B9%88%E6%98%AF-vim>

<https://www.jianshu.com/p/bcbe916f97e1>

vim使用笔记: <http://www.cnblogs.com/jiqingwu/archive/2012/06/14/vim_notes.html>
