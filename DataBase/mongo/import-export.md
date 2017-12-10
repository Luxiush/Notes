## 数据导入与导出, 备份与还原
### 导入导出
#### mongoexport
* 导出数据
```
$ mongoexport -h IP -u 用户名 -p 密码 -d 数据库 -c 表名 -o <file_out>
```
参数说明

| 参数 | 说明 |
|:--- |:--- |
| -f | 指定导出的字段,以','分割 |
| -q | 按条件导出(数据库的查询语句) |
| --port | 端口号 |
| --host | hostname:port |
| --csv | 指定导出文件的格式为csv |


#### mongoimport
* 导入数据
```
$ mongoimport -h IP -u 用户名 -p 密码 -d 数据库 -c 表名 --file <file_in>
```

参数说明

| 参数 | 说明 |
|:--- |:--- |
| --port | 端口号 |
| --host | hostname:port |
| --upsert | 插入或者更新现有数据 |
| --drop | 如果表格已经存在则先删除 |


### 备份还原
#### mongodump
* 备份数据库
```
$ mongodump -h IP --port 端口 -u 用户名 -p 密码 -o 输出路径
```
参数说明

| 参数 | 说明 |
|:--- |:--- |
| -d | 指定数据库 |
| -c | 指定表名 |
| -f | 指定导出的字段,以','分割 |
| -q | 按条件导出(数据库的查询语句) |
| --port | 端口号 |
| --host | hostname:port |
| --csv | 指定导出文件的格式为csv |

#### mongorestore
* 还原数据库
```
$ mongorestore <-h IP --port 端口 -u 用户名 -p 密码> <备份文件所在路径>
```

参数说明

| 参数 | 说明 |
|:--- |:--- |
| -d | 数据库名 |
| -c | 表名 |
| --port | 端口号 |
| --host | hostname:port |
| --upsert | 插入或者更新现有数据 |
| --drop | 如果表格已经存在则先删除 |
