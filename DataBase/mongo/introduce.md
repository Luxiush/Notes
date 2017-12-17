## [简介](https://docs.mongodb.com/manual/introduction/)
* 介于`关系数据库`和`非关系数据库`之间
* 最像`关系数据库`的`非关系数据库`
* 数据结构为key-value对，BSON
* 支持多种查询语言:
* 高可用: 自动故障转移/数据冗余
* 横向扩展
* 多存储引擎: WiredTriger/MMAPv1
* 采用预分配空间的方式来防止文件碎片, 导致mongo的数据文件通常很大
* 基于js的存储过程
* database > collection(table) > document(row)

---
## 安装 & 配置
官网教程 https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/

配置文件: /etc/mongod.conf
数据库文件: var/lib/mongodb
日志文件: /var/log/mongodb/mongod.log

### 索引
* 唯一强制字段`_id`, 并且会默认在该字段上建立索引
* 支持唯一索引, 不能创建在具有重复值的键上.
* 稀疏索引:只索引至包含被索引字段的document, 即, 缺失被索引字段的document无法通过索引找到.

---
## SQL vs NoSQL
* nosql 采用key-value的方式存储数据, sql采用结构化数据

### nosql的优势
* nosql去结构化, 容易扩展
* nosql无关系, 数据库结构简单, 在数据量大的时候仍然有较高的性能
* 灵活, nosql无需事先建立字段, 随时可以存储自定义的数据格式. 而sql增删字段非常麻烦, 尤其在数据量非常大的时候

* 为什么要使用nosql: http://www.infoq.com/cn/news/2011/01/nosql-why
> nosql系统是被设计用于成百上千台机器集群中的, 而非共享型数据库的架构. 

---
## MongoDB v.s. MySql

### MongoDB的特点
* 非关系数据库, 采用Bson的数据结构来存储数据, 基于文档
* 不需要预先定义schema, 更灵活
* 可以轻松实现分布式数据中心和高扩展性.
* 高可用

### MySql的特点
* 关系型数据库, 采用结构化的sql语句来处理数据
* 需要预先定义数据结构schema. 
* 有主键,外键等约束. 
* 年代久远, 成熟, 配套设施(研发人员,社区等)完善. 
