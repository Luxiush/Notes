## [常用shell命令](https://docs.mongodb.com/manual/reference/method/)
```
$ mongo # 启动mongo
$ exit  # 退出
$ help  # 获取帮助信息
$ db.help() #
$ show dbs  # or: show databases
$ use <db_name> # 设置当前数据库,如果没有则自动创建
$ db.dropDatabase()  # 删除当前数据库
$ db  # 显示当前数据库名
$ show collections  # 查看看当前数据库的collections, or: show tables
$ db<col_name>.drop()  # 删除当前collection
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

### find, findOne
$ db.<collection_name>.find(query_dict, projection_dict)
```
    query_dict 筛选条件: {"<field1>":<value>, "<field2>":<value>, ...}
    projection_dict 需要的维度: {"<field1>":exist, "<field>":exist, ...}  # 其中exist可取: 0(不包含)/1(包含)
```


#### 查询语句
* $eq       ==
* $nq       !=
* $lt       <
* $gt       >
* $lte      <=
* $gte      >=
```
db.collection.find({age:{$gt:18}}, {name: 1, city: 1});  // age > 18
db.collection.find({age:{$gt:18, $lte:25}});  // 18 < age <= 25
```

* $in       in
* $nin      not in
```
db.collection.find({id:{$in:[1,2,3,4]}})
```

* $exists   
```
db.collection.find({title:{$exists:false}}); // 不包含title属性的document
```

* 正则表达式查询
```
db.customers.find( { name : /acme.*corp/i } );  // i 表示区分大小写
```

* not       
```
db.customers.find( { name : { $not : /acme.*corp/i } } );
```

* 查询子维度
```
db.restaurants.find({"address.building": {$in: ["1007", "469"]}}, {"name": 1, "address.building": 1, "address.street": 1})
```

#### 分页查询
* limit, 指定查询结果数量
```
db.collection.find().limit(n)
```

* skip, 指定查询偏移量
```
db.collec.find().skip(m).limit(n)
```

* sort, 查询结果排序, 1表示升序, -1表示降序
```
db.collection.find().sort({key1:1, key2:-1})
```


### insert
$ db.<collection_name>.insert(dict_arr, options)
```
    dict_arr: dict({})或dict列表([{},{},...])
    options: {
        writeConcern: ... ,
        ordered: true/false   # 是否按顺序插入,如果为true则在某条插入失败后就立即退出, 默认为true
    }

    return: WriteResult({
        "nInserted" : 1,
        "writeConcernError" : {
            "code" : 64,
            "errmsg" : "waiting for replication timed out at shard-a"
        }
    })

db.products.insert(
   [
     { _id: 20, item: "lamp", qty: 50, type: "desk" },
     { _id: 21, item: "lamp", qty: 20, type: "floor" },
     { _id: 22, item: "bulk", qty: 100 }
   ],
   { ordered: false }
)

```

### insertOne
...

### insertMany
...


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

db.books.update(
   { _id: 1 },
   {
     $inc: { stock: 5 },
     $set: {
       item: "ABC123",
       "info.publisher": "2222",
       tags: [ "software" ],
       "ratings.1": { by: "xyz", rating: 3 }
     }
   }
)

```

### updateOne, updateMany
...


### remove
- 删除document
```
db.collection.remove(
   <query>,
   {
     justOne: <boolean>,        # 只删除一条记录
     writeConcern: <document>,
     collation: <document>
   }
)
```
