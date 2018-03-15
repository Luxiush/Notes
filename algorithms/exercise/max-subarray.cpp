/**
## leetcode maximum-subarray
### 题目
求一个数组的最大子数组

### 思路
#### v1 贪心, DP
```
max[i] = a[0] + a[1] + ... + a[i]
max[i+1] = max[i] + a[i+1], if max[i] + a[i+1] > 0
         = 0, otherwise
```

#### v2 分治
```
left_sum = 左半边子数组的最大和
right_sum = 右半边...
cross_sum = 跨越中点的子数组的最大和
max_sum = max(left_sum, right_sum, cross_sum)
```

**/

/*
解法1：贪心
*/
	int maxSubArray(int A[], int n){
		int res = A[0];
		int temp = 0;
		for(int i=0; i<n; ++i){
			temp = (temp<0)? 0: temp;
			temp += A[i];
			res = (res<temp)? temp: res;
		}
		return res;
	}


/*
分治法求解：
	left_sum = 左半边子数组的最大和
	right_sum = 右半边...
	cross_sum = 跨越中点的子数组的最大和
	max_sum = max(left_sum, right_sum, cross_sum)
*/

    int maxSubArray_rec(int A[], int p, int r){
        if(p>=r) return A[p];

        int q = (p+r)/2;
        int left_sum = 0; 	//[p,q]
        int right_sum = 0;	//[p+1,r]
        int cross_sum = 0;

        left_sum = maxSubArray_rec(A,p,q);
        right_sum = maxSubArray_rec(A,q+1,r);

        int cross_left = A[q];
        int cross_right = A[q+1];
        int temp = A[q];
        for(int i=q-1; i>=p; --i){
        	temp += A[i];
            if(temp>cross_left)
                cross_left = temp;
        }
        temp = A[q+1];
        for(int i=q+2; i<=r; ++i){
            temp += A[i];
            if(temp>cross_right)
                cross_right = temp;
        }
        cross_sum = cross_left+cross_right;

        if(cross_sum>=left_sum && cross_sum>=right_sum)
            return cross_sum;
        else if(left_sum>=cross_sum && left_sum>=right_sum)
            return left_sum;
        else
            return right_sum;
    }

    int maxSubArray(int A[], int n) {
        return maxSubArray_rec(A, 0, n-1);
    }
