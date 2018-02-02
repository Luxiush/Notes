## pymongo库
api文档: <http://api.mongodb.com/python/current/api/pymongo/>


### MongoClient
* MongoClient(host='localhost', port=27017, document_class=dict, tz_aware=False, connect=True, \*\*kwargs)
```python
from pymongo import MongoClient
client = MongoClient()
db = client['my_db']
collection = db['my_collection']
documents_cursor = collection.find()
for d in documents_cursor:
    print json.dumps(d)
```

* MongoClient(mongodbURL)
[mongodbURL 格式](https://docs.mongodb.com/manual/reference/connection-string/):
> mongodb://[username:password@]host1[:port1][,host2[:port2],...[,hostN[:portN]]][/[database][?options]]

其中options的取值参数: <https://docs.mongodb.com/manual/reference/connection-string/#connections-connection-options>


### DataBase
class pymongo.database.Database(client, name, codec_options=None, read_preference=None, write_concern=None, read_concern=None)


### Collection
class pymongo.collection.Collection(database, name, create=False, \*\*kwargs)


### 常用操作
* find, find_one, insert, insert_one, update, update_many, remove ...

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
