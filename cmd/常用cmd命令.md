### 常用cmd命令

#### runas
	- 以某一用户的身份运行


##### takeown
	- 该工具以重新分配文件所有权的方式允许管理员重新获取先前被拒绝访问
    的文件访问权。
	- TAKEOWN /S system /U user /P password /F Myshare\directory /R /A   
		- /R: recursively
		- /A: all

##### cacls
	- 显示或者修改文件的访问控制列表(ACL)
	- cacls filename [/G]
	- /G user:perm  赋予指定用户访问权限. Perm可取: R(读取),W(写入),C(更改/写入),F(完全控制)
