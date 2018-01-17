### [修改器]( https://docs.mongodb.com/manual/reference/operator/update/)

#### Field Update Operator

##### set
- 修改指定的键值, 如果不存在则新建.
```
# 修改指定键值
db.restaurants.update({"name": "abcd"}, {$set: {"zipcode": "1234"}})
# 修改子维度
db.restaurants.update({"name": "abcd"}, {$set: {"address.building": "2222"}})
# 修改数组元素 (grades[0] = -1)
db.restaurants.update({"name": "abcd"}, {$set: {"grades.0": -1}})
```

##### unset
- 删除指定键值
```
db.products.update(
   { sku: "unknown" },
   { $unset: { quantity: ""} }  # 删除quantity键, ""中可以为任意值
)
```

##### setOnInsert
- 当update操作插入新的document时, 才会执行setOnInsert里的操作.
```
db.products.update(
  { _id: 1 },
  {
     $set: { item: "apple" },
     $setOnInsert: { defaultQty: 100 }
  },
  { upsert: true }
)
```

##### inc
- increase,
- 将指定键值增加指定的值
- 如果键值不存在则将键值初始化为指定的值
- 只能对数字(int32, int64, float)执行$inc操作
```
db.restaurants.update(
    {"name": "abcd"},
    {$inc: {
        "coor": 2,   # 将coor增加2, 如果coor不存在则创建该键值,并初始化为2
        "grades.1": -2
        }
    }
)
```

##### mul
- multiply,
- 放大指定倍数
- 如果键值不存在则将键值初始化为0
- 只能对数字(int32, int64, float)执行$inc操作
```
db.products.update(
   { _id: 1 },
   { $mul: { price: 1.5 } }
)
```

##### min
- 如果比原来的值小则更新, 否则不更新
- 即, 在新值和旧值中取小的
- 可以在不同类型的的值之间进行比较, 用的是BSON的比较规则(详见官网api文档)
- 如果键值不存在则将键值初始化为指定的值
```
> db.scores.find({_id: 1})
{ _id: 1, highScore: 800, lowScore: 200 }
> db.scores.update( { _id: 1 }, { $min: { lowScore: 150 } } )  # lowScore = min(200, 150)
> db.scores.find({_id: 1})
{ _id: 1, highScore: 800, lowScore: 150 }

```

##### max
- 在新值和旧值中取大的, 同min

##### rename
- 修改键值的名字
```
db.students.update( { _id: 1 }, { $rename: { "name.first": "name.fname" } } )
```


#### [数组元素修改器]( https://docs.mongodb.com/manual/reference/operator/update-array/ )
##### $
- 标识第一个符合查询条件的数组元素
- 查询条件中必须包含要修改的数组
```
> db.students.insert([
   { "_id" : 1, "grades" : [ 85, 80, 80 ] },
   { "_id" : 2, "grades" : [ 88, 90, 92 ] },
])
> db.students.updateOne(
   { _id: 1, grades: 80 },
   { $set: { "grades.$" : 1111 } }
)
> db.students.find({})
{ "_id" : 1, "grades" : [ 85, 1111, 80 ] }
{ "_id" : 2, "grades" : [ 88, 90, 92 ] }

> db.students.updateOne(
   { _id: 1},
   { $set: { "grades.$" : 3333 } }
)
Cannot apply the positional operator without a corresponding query field containing an array.

```

##### $[]
- 标识符合查询条件的整个数组
```
> db.students.insert([
   { "_id" : 1, "grades" : [ 85, 80, 80 ] },
   { "_id" : 2, "grades" : [ 88, 90, 92 ] },
])
> db.students.updateOne(
   { _id: 1, grades: 80 },
   { $set: { "grades.$[]" : 1111 } }
)
can't append to array using string field name: 0[]
```

##### $[<identifier>]
```
# 将grades数组中大于100的元素置为100
> db.students.update(
   { },
   { $set: { "grades.$[element]" : 100 } },
   { multi: true,
     arrayFilters: [ { "element": { $gt: 100 } } ]
   }
)
```

##### pop
- 删除数组的第一个元素(-1)或最后一个元素(1)
```
> db.students.update({"_id": 1}, {$pop: {"grades": -1}})
```

##### pull
- 删除数组中符合条件的元素
```
> db.students.find({"_id": 1})
{ "_id" : 1, "grades" : [  80,  85,  80 ] }
>
> db.students.update({"_id": 1}, {$pull: {"grades": 80}})
>
> db.students.find({"_id": 1})
{ "_id" : 1, "grades" : [  85 ] }
```

##### push
- 在数组最后追加一个元素
```
> db.students.update({"_id": 1}, {$push: {"grades": 85}})
```

##### each
- 需要配合push或addToSet使用
```
> db.students.find()
{ "_id" : 1, "grades" : [  85 ] }
{ "_id" : 2, "grades" : [  88,  90,  92 ] }
>
> db.students.update({"_id": 1}, {$push: {"grades": {$each: [90, 100, 111]}}})
>
> db.students.find()
{ "_id" : 2, "grades" : [  88,  90,  92 ] }
{ "_id" : 1, "grades" : [  85,  90,  100,  111 ] }
```

##### position
- 指定push插入的位置
```
{ "_id" : 1, "scores" : [  50,  60,  70,  100 ] }
db.students.update(
    { _id: 1 },
    { $push: { scores: {
        $each: [ 1111, 2222 ],
        $position: 2
    } } }
)
{ "_id" : 1, "scores" : [  50,  60,  1111,  2222,  70,  100 ] }
```

##### sort
- 必须和each同时出现
```
> db.students.update(
    {"_id": 3},
    {$push: {"grades":{
        $each: [99, 66],
        $sort: -1
    }}})
```
