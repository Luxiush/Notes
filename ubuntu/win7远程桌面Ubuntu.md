#[教程](http://blog.chinaunix.net/uid-26642637-id-4514117.html)
https://askubuntu.com/questions/592537/can-i-access-ubuntu-from-windows-remotely

## 安装xrdp和vnc4server
sudo apt-get install xrdp
sudo apt-get install vnc4server

## 
sudo apt-get install gnome-core #安装gnome桌面组件

## 安装xfce4的桌面（使用xrdp只能登录xfce的远程桌面）
* sudo apt-get install xfce4
* echo “xfce4-session” > ~/.xsession
* 修改/etc/xrdp/startwm.sh文件:
```
	#!/bin/sh

	if [ -r /etc/default/locale ]; then
	  . /etc/default/locale
	  export LANG LANGUAGE
	fi

	startxfce4            # 加上这一行
	. /etc/X11/Xsession
```
* sudo service xrdp restart



## 设置远程桌面
* 搜索“desktop sharing”， 进行相关设置

## [安装dconf-editor](http://www.jianshu.com/p/a915e52dae11) 
* sudo apt-get install dconf-editor
* 在search yoour computer android online sources中查找上一步安装的软件dconf-editor
* 配置路径：org > gnome > desktop > remote-access
* 取消勾选requlre-encryption属性

# 键盘混乱的问题
这个远程连接到Ubuntu上的时候发现，键盘上的tab键有问题，而且很多组合键也是有问题的。
这个问题的来源是xface里面的一个组合快捷键引起的。
在Ubuntu上面打开打开管理键盘快捷键（Setting Editor->xface4-keyboard-shortcuts），然后找到一个super+tab的组合快捷键，取消对应的功能。



sesman-Xvnc: 使用 xrdp 内建的 libvnc.so 模组登入本机，本机不需启动 VNC Server。（默认选这个）
console: 登入本机的 VNC Server。
vnc-any: 登入其它已经启动 VNC Server 的主机。
sesman-any:登入其它有安装 xrdp 的主机。
rpd-any: 登入其它已经启动远端桌面 (RDP Server) 的 Windows 电脑或主机。
sesman-X11rdp: 这个项目我没有测试成功，从字面上的意思来看，应该是连结本机端由 X Server 提供的 RDP，但目前 Linux 的桌面应该还没有具备这样的功能!


