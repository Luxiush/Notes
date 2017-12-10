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

### 比较操作符
* $eq   ==
* $nq   !=
* $lt   <
* $gt   >
* $lte  <=
* $gte  >=
* $in

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


### 分页查询
* limit, 指定查询结果数量
```
db.collection.find().limit(n)
```

* skip, 指定查询偏移量
```
db.collec.find().limit(n).skip(m)
```

* sort, 查询结果排序, 1表示生序, -1表示降序
```
db.collection.find().sort({key1:1, key2:-1})
```
