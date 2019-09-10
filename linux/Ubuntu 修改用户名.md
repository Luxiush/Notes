修改用户名：
1. 登录到root用户：$ su

2. 修改用户名： 
$ gedit /etc/passwd

找到原来的用户名（如：haldaemon）进行修改，但是/home/haldaemon 中的也一并修改 aldaemon:x:107:114:Hardware abstraction layer,,,:/home/haldaemon:/bin/false

3. $ gedit /etc/shadow
同样找到原来的用户名进行修改

4 $ cd ./home
ls 查看新的用户文件夹是否存在，存在则删除。
mv 将原来的用户文件夹重命名为新的用户名 （mv src dest）

5. $ reboot

reference：http://blog.csdn.net/ideaboys/article/details/42559803
	
