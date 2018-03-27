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

##### 多表联合查询(join)
MySQL的JOIN（一）：用法 <https://www.cnblogs.com/fudashi/p/7491039.html>
mysql的几种join: <http://blog.csdn.net/u012410733/article/details/63684663>

```
create table t1 (id int not null,name varchar(20));
create table t2 (id int not null,name varchar(20));
```

1. 笛卡尔积: 把左表和右表的列通过笛卡尔积的形式表达出来
```
select * from t1 join t2;
```

2. inner join: 从笛卡尔积中选出on子句条件成立的记录
```
select * from t1 inner join t2 on t1.id = t2.id;
```

3. left join: inner join的结果加上`左`表中剩余的记录

4. right join: inner join的结果加上`右`表中剩余的记录

5. outer join: 相当于inner join和outer join做union操作, **mysql不支持**

6. natural join: 相当于inner join, 但是把两个表中**名字相同的列**作为连接条件.
```
select A1, A2 ... from r1 natural join r2 ... where <Pf1>;
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
###### 并(union)
union运算自动去重, 使用union all保留重复, 且效率要高于nion.

- 每个查询必须包含相同的列, 顺序不一定要一致.
- 列的数据必须兼容, 即可以进行隐式类型转换.

```
(select course_id from section where semester='Fall' and year=2009)
union
(select course_id from section where semester='Spring' and year=2010);
```

- Union不允许对部分结果集进行排序, 只能对最终检索出来的结果集进行排序.

```
(select user_id, user_name, grade from students where grade>60)
union
(select user_id, user_name, grade from students where user_id>100)
order by grade desc;
```

###### 交(intersect)
intersect运算自动去重, 用intersect all保留重复

###### 差(except)
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
