## SQL
### 初级
#### SQL语言组成部分
1. 数据定义语言(Data-Define Language): 提供定义关系模式,删除关系以及修改关系模式的命令. 
2. 数据操纵语言(Data-Manipulation Language): 提供从数据库中查询信息,以及在数据库中插入,删除,修改元组的能力. 
3. 完整性(Integrity): 保存在数据库中的数据必须满足所定义的完整性约束, 破坏完整性约束的更新是不允许的. 
4. 视图定义(View Define)
5. 嵌入式SQL和动态SQL 
6. 授权(Authorization): 定义对关系和视图的访问权限. 

#### 基本数据类型
* char(n): 定长字符串
* varchar(n): 变长字符串, 最大长度为n
* int: 整型
* smallint: 小整型
* numeric:(p,d): 定点数, 总共p位(包括符号位), 其中d位数字在小数点右边. 
* real: 浮点数
* double precision: 双精度 
* float(n): 至少为n为的浮点数 

#### SQL基本查询语句
##### 单关系查询
##### 多关系查询

##### 自然连接(natural join)
* 将第一个关系的每个元组与第二个关系的所有元组都进行连接,但是只保留在两个关系中都出现的属性上取值相同的元组对. 
```
select A1, A2 ... from r1 natural joi r2 ... where Pf1;
```

##### 更名运算(as)
old-name as new-name
```
select T.name, S.course_id form instructor as T, teaches as S where T.ID = S.ID;
```

##### order by
```
/*按salary的降序排列输出整个instructor关系*/
select * from instructor order by salary desc, name asc;
```

##### 集合运算 
* 并(union)
union运算自动去重
```
(select course_id from section where semester='Fall' and year=2009)
union 
(select course_id from section where semester='Spring' and year=2010);
```

* 交(intersect)
intersect运算自动去重, 用intersect all保留重复

* 差(except)
从第一个输入中输出不出现在第二个输入中的元组


#### 聚集函数
##### 基本聚集
* 平均值: avg
* 最小值: min
* 最大值: max
* 综合: sum
* 计数: count

##### group by 
* 将聚集函数作用到一组元组集上, 在group by 子句中的所有属性上取值相同的元组将被分在一个组中

##### having
* 对分组进行限定
```
/*教师平均工资超过42000的院系*/
select dept_name, avg(salary) as avg_salary from instructor group by dept_nam having avg(salary)>42000;
```

#### 嵌套子查询


##### with 
* 定义临时关系

##### 标量子查询


### 中级


### 高级