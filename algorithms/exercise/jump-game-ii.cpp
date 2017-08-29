/*
lettcode jump-game-ii
http://www.cnblogs.com/grandyang/p/4373533.html
*/
#include <iostream>
#include <vector>

using namespace std;

	int jump2(int A[], int n) {
		if(n<2) return 0;
		
		int cur = 0; 
		int next = 0;
		int max = A[0];
		int steps = 0; 
		
		while(next<n){
			++steps;
			start = next;
			next = max;
			for(int i=star+1; i<next; ++i){
				if(max < i+A[i]){
					max = i+A[i];
				}
			}
			
		}
	}

    int jump(int A[], int n) {
        if(n<2) return 0;
        
		int cur = 0; 
		int next = 0;
		int steps = 0;
		int i = 0;
		
		for(; i<n; ++i){
			if(i>next){
				++ steps;
				next = cur;
			}
			
			if(cur<i+A[i]){
				cur = i+A[i];
			}
		}
		return steps;
    }

int main(){
	int A[100];
	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin>> A[i];
	
	cout<< jump(A,n)<< endl;
	
	
	return 0;
}