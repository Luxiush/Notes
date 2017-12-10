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
