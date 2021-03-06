## C++ STL

---
### STL是什么
* STL --- 标准模板库, 包括算法,容器,迭代器.
* 常用容器: vector, list, map, set, queue, priority_queue, stack,

### 好处
标准化组件, 代码重用, 避免重复开发, 提高编程效率


---
### vector的内存管理
* vector包含着一系列`连续存储`的元素, 其行为和数组类似.
在不超过其最大容量的情况下它可以自动增长到足以容纳放进去的元素, 而一旦超出其最大容量就会发生一次`内存重新分配`将`容量翻番`.
内存的重新分配`很耗时`,并且一旦发生内存重新分配,和vector相关的所有`reference`,`pointer`,`iterator`都会`失效`.
因此在使用vector时要尽量避免内存的重新分配.可以通过`reserve`函数预留相当大的容量,最小化内存重新分配的次数.


---
### map
map的底层实现机制为红黑树, 红黑树的每个节点为一个pair对象保存`key`和`value`两个值, 节点之间根据key进行排序.
map的大部分操作都是直接调用红黑树的接口来完成, 需要额外提供的就是一个key值之间的比较函数(operator<).


---
### unordered_map
* 基于hash实现
* 需要定义hash_value函数并且重载operator==.

#### [map和unordered_map]( https://www.zhihu.com/question/24506208 )
* 首先map是基于红黑树实现的, 而hash map是基于哈希实现的, 所以map是`有序`的而hash map是`无序`的(根据哈希值进行排序).
> the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values.

* unordered_map由于是基于hash的,所以其查找复杂度是O(1), 但是在最坏情况下会达到O(N)(很少见), 同时哈希函数也需要额外的时间特别是在key值非常长的时候, 而map基于红黑树, 其查找复杂度都是O(logN).

* unordered_map需要维护一张hash表, map也需要通过额外的指针来维持树形结构. 如何选择需要就需要根据实际情况而定. 

* map由于需要维护内部的有序性, 频繁的插入和删除操作会导致内存碎片化, 使得性能降低. 

* 总的来说, unordered_map除了空间消耗较大, 不能自动排序外, 其他的都优于map. (仅个人观点)

* [Is there any advantage of using map over unordered map in case of trivial keys]( https://stackoverflow.com/questions/2196995/is-there-any-advantage-of-using-map-over-unordered-map-in-case-of-trivial-keys )


#### 关于hash
##### hash算法:
* 空间映射函数(将一个非常大的取值空间映射到一个非常小的取值空间),
* 摘要算法

1. 用来加快数据的查询速度(通过哈希函数将关键字映射成索引, 根据索引访问数组)
2. 数字签名

##### 冲突处理
1. 链表法
将具有相同hash值的键放在一个链表中.

2. 开放地址法
当一个键的哈希值被另一个键占用时, 则通过另外的规则再次进行哈希, 寻找下一个哈希值

--
### 迭代器
> 迭代器是封装了指针、重载了 -> 、* 、++等操作符的类模板，具有类似指针的行为。迭代器的设计是对数据结构的泛化，`使不同容器具有相同的访问方式`，让代码不必依赖于特定的数据结构.
#### [迭代器失效]( http://lib.csdn.net/article/cplusplus/33184 )
* 什么是迭代器失效?
<p> 迭代器失效是指迭代器指向错误的元素或无效的内存地址。 </p>
<p> 插入、删除容器中元素的操作会导致内部数据结构`内存布局的改变`，那么就可能引起迭代器失效。 </p>

* STL迭代器的失效原则
| 容器类 | 插入 | 删除 |
|:--- |:--- |:--- |
| list | 所有迭代器不失效 | 仅被删除的节点的迭代器失效 |
| vector | 当 vector的容量(不是size)不改变时, 只失效之后的迭代器, 否则全部失效 | 被删除节点之后的迭代器全部失效 |
| set, map | 所有迭代器不失效 | 仅被删除的节点的迭代器失效 |


---
### 问题
* vector内部是怎样实现的,与list有什么区别,插入删除是怎样的

* 当不停地向vector中插入元素时其空间时怎样增长的 --- 两倍

* map查找,插入的复杂度 --- 红黑树, logN

* 列举迭代器失效的情况 --- (见迭代器失效原则)

* 迭代器访问相比下标访问的优势
--- 通过迭代器可以为不同容器提供一个统一的方式, 从而可以将算法与底层的具体数据结构解耦, 使得算法不必过于依赖底层的数据结构. 并且对于有些容器像list,map,set则不支持下标访问.

* STL sort平均复杂度,最坏情况复杂度 --- 用快排实现, 时间复杂度: 最好 O(NlogN), 平均 O(NlogN), 最坏: 在所有元素几乎有序的情况下 O(N^2)

* STL里面的容器是不是线程安全的
--- 不是,
> [STL语义上不提供任何强度的线程安全保证, 如果写者触发了内存重新分配, 那么写着之前的迭代器就会失效. 并发编程的核心问题从来就不是`并发容器`或者`同步原语,而是`并发模式`,根据具体问题选择合适的语义.]( https://www.zhihu.com/question/29987589/answer/46509882 )
