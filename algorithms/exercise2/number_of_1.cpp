/*
## 二进制中1的个数
### 题目:
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

### hint:
把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.

*/

/*solution 1*/
int NumberOf1(int n) {
	int res = 0;
	for(int i=0; i<8*sizeof(int); ++i){
		res += (n>>i)&1;
	}

	return res;
 }

/*solution 2*/
int NumberOf1_(int n) {
	int count = 0;
	while(n!= 0){
		count++;
		// 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0. 依次可以统计1的个数.
		n = n & (n - 1);
	 }
	return count;
}
