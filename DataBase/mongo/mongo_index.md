## 索引
*from官方文档*


### 索引类型

#### default \_id
* 唯一强制字段`_id`, 如果用户没有指定则自动生成, 并默认在该字段上建立索引
* \_id的值是唯一的

#### Single Field
* 对单个字段建立索引
```
db.collection.ensureIndex({title: 1}) # 1:升序, -1:降序
```

#### Compound Index
* 多字段索引
```
db.collection.ensureIndex({userid: 1, score: -1})
```

#### MultiKey Index
* 多键索引
* 为一个键的子键建立索引
```
{
    userid:"marker",
    address:[
        {zip:"618255"},
        {zip:"618254"}
    ]
}

db.collection.ensureIndex({address.zip: 1})
```

#### Geospatial Indx
* 地理空间索引
```
db.places.ensureIndex( { loc : "2dsphere" } )
```

#### Text Index
*  文本索引
* 支持对document中的字符串进行搜索

#### Hashed Index
* 对字段的哈希值建立索引
* 不支持范围查询
```
db.collection.ensureIndex({name: "hashed"})
```

### 索引的属性
#### 唯一索引
unique

#### 稀疏索引
sparse


### 基本语句
```
# 添加/修改索引
db.users.ensureIndex({name:"text"});

# 删除集合所有索引
db.users.dropIndexes();

# 删除特定索引 (删除id字段升序的索引)
db.users.dropIndex({"id":1})

# 获取集合索引
db.users.getIndexes();

# 重构索引
db.users.reIndex();
```
