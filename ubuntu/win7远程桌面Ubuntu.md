#[�̳�](http://blog.chinaunix.net/uid-26642637-id-4514117.html)
https://askubuntu.com/questions/592537/can-i-access-ubuntu-from-windows-remotely

## ��װxrdp��vnc4server
sudo apt-get install xrdp
sudo apt-get install vnc4server

## 
sudo apt-get install gnome-core #��װgnome�������

## ��װxfce4�����棨ʹ��xrdpֻ�ܵ�¼xfce��Զ�����棩
* sudo apt-get install xfce4
* echo ��xfce4-session�� > ~/.xsession
* �޸�/etc/xrdp/startwm.sh�ļ�:
```
	#!/bin/sh

	if [ -r /etc/default/locale ]; then
	  . /etc/default/locale
	  export LANG LANGUAGE
	fi

	startxfce4            # ������һ��
	. /etc/X11/Xsession
```
* sudo service xrdp restart



## ����Զ������
* ������desktop sharing���� �����������

## [��װdconf-editor](http://www.jianshu.com/p/a915e52dae11) 
* sudo apt-get install dconf-editor
* ��search yoour computer android online sources�в�����һ����װ�����dconf-editor
* ����·����org > gnome > desktop > remote-access
* ȡ����ѡrequlre-encryption����

# ���̻��ҵ�����
���Զ�����ӵ�Ubuntu�ϵ�ʱ���֣������ϵ�tab�������⣬���Һܶ���ϼ�Ҳ��������ġ�
����������Դ��xface�����һ����Ͽ�ݼ�����ġ�
��Ubuntu����򿪴򿪹�����̿�ݼ���Setting Editor->xface4-keyboard-shortcuts����Ȼ���ҵ�һ��super+tab����Ͽ�ݼ���ȡ����Ӧ�Ĺ��ܡ�



sesman-Xvnc: ʹ�� xrdp �ڽ��� libvnc.so ģ����뱾���������������� VNC Server����Ĭ��ѡ�����
console: ���뱾���� VNC Server��
vnc-any: ���������Ѿ����� VNC Server ��������
sesman-any:���������а�װ xrdp ��������
rpd-any: ���������Ѿ�����Զ������ (RDP Server) �� Windows ���Ի�������
sesman-X11rdp: �����Ŀ��û�в��Գɹ����������ϵ���˼������Ӧ�������᱾������ X Server �ṩ�� RDP����Ŀǰ Linux ������Ӧ�û�û�о߱������Ĺ���!


