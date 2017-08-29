/*leetcode jump-game*/
/*  https://segmentfault.com/a/1190000003488956
 遍历过程中记录最远能到达的点，如果最后最远能到达的点不小于终点则说明能到达
*/

    bool canJump(int A[], int n) {
        int i = 0;
        int max = 0;//记录能到达的最远的点
        
        for(; i<n && i<=max; ++i){
            if(max<i+A[i]){
                max = i+A[i];
            }
        }
        
        return i==n;
    }