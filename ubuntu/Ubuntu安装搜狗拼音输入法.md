# Ubuntu14.04安装搜狗拼音输入法
* 安装fcitx框架：sudo apt-get install fcitx
* Restart系统
* System Setting --> Language Support 将 输入法框架改为 fcitx
* Restart系统 
* 官网下载Linux版搜狗安装包
* 找到双击打开安装即可
* 搜索 Fcitx Configuration， 
	左下角“+”号，Add input method，
	去掉 Only show current language 前面的选勾，
	找到刚刚安装的Sogou
	OK，返回
* Input Method 对话框中多了 Sogou Pinyin 一项，将其移到第一位即可

* PS：
** 如果老是不成功，就先把fcitx卸掉：sudo apt-get remove fcitx* ，Restart后再试试
** System Setting 里面没有 Language Support 选项：
	sudo apt-get install language-selector-gnome

* 折腾了差不多一天几乎所有教程都看了，老是不行（可能是fcitx或sogou没装好），没办法只好把之前装的fcitx、sogou都卸了，重装。

# [Ubuntu14 搜狗输入法无法输入中文等问题](http://www.cnblogs.com/cursorhu/p/6564793.html)
* ctrl+shift 切不出搜狗图标
	重新配置一次输入法框架：system settings->language support->keyboard input method system->fcitx

* 有搜狗输入法备选词框，但是英文
	配置文件出问题，
	删除 ~/.config 下的SogouPY、SogouPY.users、sogou-qimpanel三个文件夹，
	重启系统