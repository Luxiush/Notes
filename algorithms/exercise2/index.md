# 剑指offer
 
---
binary_tree2list.cpp
## 二叉搜索树转双向链表
### 题目
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
### 思路
#### v1
* 先对二叉树进行中序遍历, 得到相应序列, 再依次序列进行转换.

#### v2 递归

 
---
delete_duplication.cpp
## 删除链表中的重复节点
### 题目: 
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

### 思路: 
#### 递归
只处理重复元素出现在开头的情况，其他情况向后递归。
#### 非递归
http://blog.csdn.net/u011080472/article/details/51286767
 
---
duplication.cpp
## 数组中的重复数字
### Description
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

### Solution
* 由于题目已经明确指出所有数字都在0到n-1的范围内, 因此可以借鉴桶排序的思想. 具体思路如下: 
遍历数组, 判断当前位置上的值和下标的值是否相等: 1)如果相等则遍历下一位;2)如果不相等则将当前位置上的值num和a[num]做比较如果不相等则对调,使其满足"1)"的条件,如果相等则说明该元素为重复元素. 

 
---
find_first_common_list_node.cpp
输入两个链表, 找到它们的第一个公共节点.
 
---
find_numbers_with_sum.cpp
## 和为S的俩个数
### 题目
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的**乘积最小的**。

### 思路
双指针:
if 和小于S: 小指针++
if 和大于S: 大指针--
直到两个指针的和等于S

* 当量指针离得最远时, 就是乘积最小的时候. 所以通过以上方法最先找到的就是乘积最小的. 

 
---
has_path.cpp
## 矩阵中的路径
### 题目:
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
### 思路: 递归
 
---
list_loop_entry.cpp
## 链表中换的入口节点
### Description: 
一个链表中包含环，请找出该链表的环的入口结点。

### [Solution:]( http://blog.csdn.net/crazy__chen/article/details/45100007 ) 
当fast指针(每次走两步)等于slow指针(每次走一步)时, slow指针肯定还没有遍历完整个链表, 而此时fast指针已经在环内循环了n圈(n>=1). 假定从链表头指针开始slow走了s步 ,则fast走了2s步, fast所走的步数还等于s加上fast指针比slow指针在环内多走的n圈. 
设环长为r, 则: 2s = s + nr; => s = nr;
设整个链表长度为L, 环的入口结点到相遇结点的距离为x, 起点到环的入口结点的距离为a, 则: 
a + x = s;
=> a + x = nr;
=> a + x = (n-1)r + L - a;
=> a = (n-1)r + (L - a - x);
即: 由链表的头结点到环入口结点的距离 = n-1圈环的长度 + 相遇点到环入口结点的距离 于是，当我们在`链表头部`和`相遇处`分别设一指针，每次各走一步，则两指针必定相遇，且相遇的第一个结点即为环的入口结点.
 
---
matrix_search.cpp
## 查找二维数组
### 题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
### 解法
#### 解法1:
对每行进行二分查找
#### 解法2:
从左下角开始, 如果大于目标值就向上走, 小于则向右走. 
 
---
max_dist.cpp
## 最大差值
### 题目
有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。max给定数组A及它的大小n，请返回最大差值。

### 思路
- 动态规划: 遍历一遍数组, 记录当前最小值和最大差值.

 
---
min_k.cpp
## 最小的k个数
### 题目
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
### Solution:
基于小根堆
 
---
min_stack.cpp
## 包含min函数的栈
### 题目:
设计一个能够得到最小元素的栈
### 思路:
用一个栈保存数据, 同时再构建一个辅助栈用来保存当前栈中的最小元素. 
 
---
number_of_1.cpp
## 二进制中1的个数
### 题目:
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

### hint:
把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.

 
---
numbers_appear_once.cpp
## 数组中只出现一次的数据
### 题目
>> 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

### 思路
注意所给数组的特殊性, `除了两个数字之外其他的数字都出现两次`. 进而联想到`异或`运算的性质: 任何一个数和自己做异或最终的结果都为0.
因此, 如果对整个数组做异或那么最终得到的就是两个不同的数的异或结果. 
可以利用这个异或的结果将数组分成两组,每组只包含一个出现一次的数. 由于两个不同的数一定不相等, 所以整个数组的异或结果一定不为0, 也就是说异或结果的二进制表示中一定至少有一位为1. 将异或结果中第一个为1的位记为第N位, 从而根据第N位是否为1将整个数组划分成两组.

 
---
path_sum.cpp
## 二叉树中和为某一值的路径
### 题目
> 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
### 思路
递归.
注意空树的情况.
注意叶节点只需递归一次. 
                10              
            /        \          
          5           12        
        /  \                    
       4    7                   
 
---
print_matrix_clockwise.cpp
## 顺时针打印矩阵
## 题目
输入一个矩阵, 按从外到里以顺时针的顺序输出矩阵的每个元素,
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
## 思路
按要求输出即可, 没什么难度. 
注意只有一行或只有一列的特殊情况下不要重复输出就好. 
 
---
R_and_G.cpp
## 红R和绿G:
### 题目大意
有一个值为R或G的字符串, 现需要改变其中某些项的值使得每个R都比每个G距离最左侧近. 
问至少需要改变多少项的值.

### 思路 
* 题目可理解为:找到一个点将数组切分，使得左边全是R，右边全是G，并且改动数最小.
* 这无外乎有n+1中切法: 0:n, 1:n-1, ...., n:0.
可以分别用两个数组arr_R和arr_G统计到目前R和G的数量, 
对于每种分割, 将左边的所有G变为R, 右边的所有R变为G. 
所以, 颜色改变数 = 左边G的数量 + 右边R的数量
 
---
replace_space.cpp
## 替换空格
### 题目:
将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy. 
### 解:
一个空格只需要占一个char,但是替换成"%20"后需要占用3个char. 所以需要在替换的时候用一个变量来记录偏移量. 
 
---
stack_pop_order.cpp
## 栈的压入, 弹出序列
### 题目
> 输入两个整数序列，第一个序列(A)表示栈的压入顺序，请判断第二个序列(B)是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

### 思路 
借助一个辅助栈, 依次将A序列入栈, 如果碰到与B序列的第一个相等的则弹栈并将B序列指针后移直到不相等. 

 
---
subtree.cpp
## 数的子结构
### 题目
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 
---
sum_n.cpp
## 求1+2+3+...+n
### 题目:
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
### [解法]( http://blog.csdn.net/shoulinjun/article/details/20564095 ):
#### 递归:
* A||B: 当 A为true时，B不再执行.
* 利用这一性质模拟选择语句,实现递归.

#### 模板
...

#### 类
* 采用C++类中的static变量,以及构造函数在对象构造时会被自动调用的性质。
int Sum(int n) {
	int res = 0;
	// A || B: 当 A为true时，B不再执行也就起到了选择的作用
	(n==0)||(res=Sum(n-1));
	return res+n;
}

class MyClass{
	static int n;
	static int sum;

	MyClass(){
		n += 1;
		sum += n;
	}
};



int main(){
	cin>> n;

	cout<< "Solutioon 1: "<< Sum(n)<< endl;

	int MyClass::n = 0;
	int MyClass::sum = 0;
	MyClass a[n];  // 调用n次构造函数
	cout<< "Solutioon 2: "<< MyClass::sum<< endl;

	return 0;
}
 
---
sum_s_continue_sequence.cpp
## 和为S的连续整数序列
### 题目
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

### 思路
双指针问题:
if 和小于S: 大指针++
if 和大于S: 小指针++
 
---
sum_without_plus.cpp
## 求两个数的和
### 题目
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

### 思路
1. 各位相加不计进位 (^)
2. 只记下各位相加后的进位 (&)
3. 将前面两步的结果相加(递归), 直到不再产生进位

 
---
ugly_number.cpp
## 丑数
### 题目
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

### 思路
* 动态规划
当前的丑数一定是之前的某个丑数的2,3或5倍.
 
---
verify_postoder_sequence.cpp
## 二叉搜索树的后序遍历序列
### Description
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
### Solution
* 根据`二叉搜索树`的定义可知, 一个二叉搜索树的后序遍历结果应该是前半段(左子树节点)都小于根节点,而后半段(右子树节点)都大于根节点. 因此对于给定序列只要是验证以上特征,然后再递归对其左右子数组验证即可.
* 递归过程中需要注意只存在左子树和只存在右子树的特殊情况. 
