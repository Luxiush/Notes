/* leetcode candy */
/* http://bookshadow.com/weblog/2015/08/06/leetcode-candy/ */
/*
题意：
    N个孩子站成一排，每个孩子有一个评分，
为每个孩子分配糖果（每个孩子至少有一个），
要求评分高的孩子得到的糖果要多余他的邻居
*/

    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candy(n,1);
        
        for(int i=1; i<n; ++i){
            if(ratings[i]>ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }
        
        for(int j=n-2; j>=0; --j){
            if(ratings[j]>ratings[j+1]){
                if(candy[j]<candy[j+1]+1){
                    candy[j] = candy[j+1]+1;
                }
            }
        }
        
    	int sum = 0;
        for(int i=0; i<n; ++i)
            sum += candy[i];
        return sum;
    }