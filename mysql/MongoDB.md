# MongoDB
## [简介](https://docs.mongodb.com/manual/introduction/)
* 介于`关系数据库`和`非关系数据库`之间
* 最像`关系数据库`的`非关系数据库`
* 数据结构为key-value对，类似JSON
* 支持多种查询语言:
* 高可用: 自动故障转移/数据冗余
* 横向扩展
* 多存储引擎: WiredTriger/MMAPv1

database > collection(table) > document(row)

---
## 安装 & 配置
官网教程 https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/

配置文件: /etc/mongod.conf
数据库文件: var/lib/mongodb
日志文件: /var/log/mongodb/mongod.log

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


---
## [常用shell命令](https://docs.mongodb.com/manual/reference/method/)
```
$ mongo # 启动mongo
$ exit  # 退出
$ help  # 获取帮助信息
$ db.help() #
$ show dbs
$ use <db_name> # 设置当前数据库,如果没有则自动创建
$ db.dropDatabase()  # 删除当前数据库
$ db  # 显示当前数据库名
$ show collections  # 查看看当前数据库的collections (show tables)
$ db<col_name>.drop()  # 删除当前collection
```

### find
$ db.<collection_name>.find(query_dict, projection_dict)
```
    query_dict 筛选条件: {"<field1>":<value>, "<field2>":<value>, ...}
    projection_dict 需要的维度: {"<field1>":exist, "<field>":exist, ...}  # 其中exist可取: 0(不包含)/1(包含)
```

### distinct
$ db.<collection_name>.distinct(field_string, query_dict, options)
```
    field_string: 指定的维度(string type)
    query_dictt 筛选条件: {"<field1>":<value>, "<field2>":<value>, ...}

    return: 指定维度的所有取值, list
```

### count
                        $ db.<collection_name>.count(query_dict, options_dict)
```
    query_dict 查询条件: {"<field1>":<value>, "<field2>":<value>, ...}
    option_dict 可选项: {
        "limit": (int type) The maximum number of documents to count.
        "skip": (int type) The number of documents to skip before counting.
        "maxTimeMS": (int type) 本次查询所允许的最长运行时间
        "hint": (string or document) ...
    }
```

### insert
$ db.<collection_name>.insert(dict_arr, options)
```
    dict_arr: dict({})或dict列表([{},{},...])
    options: {
        writeConcern: ... ,
        ordered: true/false   # 是否按顺序插入,默认为true
    }

    return: WriteResult({
        "nInserted" : 1,
        "writeConcernError" : {
            "code" : 64,
            "errmsg" : "waiting for replication timed out at shard-a"
        }
    })

```

### insertOne


### insertMany


### update
$ db.collection.update(query, update, options)
```
    query: 查询条件, 同find
    update: {
        $inc: { <field>: <value> },   # increase, 将<field>的值增加<value>
        $set: {                       # 更新<field1>,<field2>...的值
            <field1>: <new_value>,
            <field2>: <new_value>,
            ...
        }
    }
    options: {
        upsert: <bool>,  # 当查询条件没有匹配到时是否插入新纪录, 默认为false
        multi: <bool>,   # 当查询条件匹配到多条时是否更新多条记录, 默认为false
        ...
    }

```

### updateOne


### updateMany



* 批量操作: bulk


### 用户管理
#### [权限和角色](https://docs.mongodb.com/manual/reference/built-in-roles/)
* 数据库用户权限
  read

  readWrite

* 数据库管理权限
  dbAdmin

  dbOwner

  userAdmin  能创建`用户`和`角色`

* cluster上的权限

* else


#### getUsers

#### auth



#### createUser
```
db.createUser({
  user: "<name>",
  pwd: "<cleartext password>",
  customData: { <any information> },  # 备注信息
  roles: [
    { role: "<role>", db: "<database>" } | "<role>",
    ...
  ]
})
```

#### updateUser
```
db.updateUser(
   "<username>",
   {
     customData : { <any information> },
     roles : [
               { role: "<role>", db: "<database>" } | "<role>",
               ...
             ],
     pwd: "<cleartext password>"
    },
    writeConcern: { <write concern> }
)
```

#### dropUser




---
## pymongo库
MongoDB数据以JSON的格式存储在文件中

### 建立连接 MongoClient
* MongoClient(host='localhost', port=27017, document_class=dict, tz_aware=False, connect=True, \*\*kwargs)
```
from pymongo import MongoClient
c = MongoClient()
c.test_database

```

* MongoClient(mongodbURL)
[mongodbURL 格式](https://docs.mongodb.com/manual/reference/connection-string/):
> mongodb://[username:password@]host1[:port1][,host2[:port2],...[,hostN[:portN]]][/[database][?options]]

其中options的取值参加: [here](https://docs.mongodb.com/manual/reference/connection-string/#connections-connection-options)

### 常用操作
api文档: http://api.mongodb.com/python/current/api/pymongo/
#### [文件查询](https://docs.mongodb.com/manual/tutorial/getting-started/)
* pymongo.collection.Collection.`find()`
```
    cursor = db.inventory.find({}) # select all

    # similar to sql: select * from inventory where status="D"
    cursor = db.inventory.find({"status":"D"})


```

#### [文件更新](https://docs.mongodb.com/manual/tutorial/update-documents/#write-op-update)
###### insert
* insert_many
```python
db.inventory.insert_many(
{"item": "canvas",
     "qty": 100,
     "size": {"h": 28, "w": 35.5, "uom": "cm"},
     "status": "A"},
    {"item": "journal",
     "qty": 25,
     "size": {"h": 14, "w": 21, "uom": "cm"},
     "status": "A"},
    ...
)
```


* insert_one
```

```

###### update


###### replace

##### insert_one()


#### [文件删除]()


#### [索引 index](http://api.mongodb.com/python/current/api/pymongo/collection.html)

##### create_index
* db.collection.create_index()
```
>>> my_collection.create_index([("mike", pymongo.DESCENDING),
...                             ("eliot", pymongo.ASCENDING)])
```

* db.collection.create_indexes(indexes)
```
>>> from pymongo import IndexModel, ASCENDING, DESCENDING
>>> index1 = IndexModel([("hello", DESCENDING),
...                      ("world", ASCENDING)], name="hello_world")
>>> index2 = IndexModel([("goodbye", DESCENDING)])
>>> db.test.create_indexes([index1, index2])
["hello_world"]
```


#### cursor
