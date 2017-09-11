/*
## ��������1�ĸ���
### ��Ŀ:
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

### hint:
��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1���0.

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
		// ��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1���0. ���ο���ͳ��1�ĸ���.
		n = n & (n - 1);
	 }
	return count;
}