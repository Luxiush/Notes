/*================基本命令================*/
/*执行sql脚本*/
mysql -u[username] -p < E:/test.sql
或者先登录mysql然后
source E:/test.sql

/*===========mysql 权限管理==============*/
/*添加用户*/
create user username@hostname identified by 'password';
/*对mysql.user表进行操作也可以起到相应效果*/
/*修改用户名*/
rename user <user name> to <user name>;
/*删除用户*/
drop user username;
	/*权限管理*/
/*显示某一用户的权限*/
show grants for username@hostname;
/*权限授予*/
grant pri_type on what to username identified by 'password' with grant option;
/*撤销权限*/
revoke priv_type on what from who;

/*========================日志======================*/
/*查看日志是否开启*/
show variables like 'log_%';

/*========================备份与还原=======================*/
/*导出表的数据内容*/
lock tables table_name read;
select * into outfile 'file_name' from table_name;
unlock tables;
/*导入数据*/
lock tables table_name write;
load data [local] infile 'file_name' [replace|ingnore] into table table_name;
alter table table_name convert to character set charset_name;/*更改字符集*/
unlock tables;

/*==使用mysqldump备份与还原数据==*/
/*既可以备份数据库表的结构，也可以备份一个数据库，还可以备份整个数据库系统*/
	/*备份*/
mysqldump -u username -p password schema_name > schema_name.sql;
	/*恢复*/
mysql -u username -p password schema_name < schema_name.sql;

/*差异备份与还原*/
	/*备份*/
mysqldump -u username -p password schema_name -F > schema_name.sql;
	/*还原*/
mysql -u username -p password schema_name < schema_name.sql;



