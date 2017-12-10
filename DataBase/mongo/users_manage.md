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
