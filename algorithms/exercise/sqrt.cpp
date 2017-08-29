/*leetcode sqrtx*/
/*二分查找求x的平方根*/


    int sqrt(int x) {
        if(x<=1) return x;
        int start=0, end=x;
        int mid = 0;
        
        while(start<=end){
            mid = (start+end)/2;
            if(mid==x/mid) return mid;
            else if(mid<x/mid){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return end;
    }