#include<iostream>
#include<vector>

using namespace std;

class BinarySearch {
public:
    int binSearch(vector<int> A, int p, int r, int val){
		printf("binSearch: %d, %d, %d\n", p, r, val);
        if(p>=r){
            if(A[p] == val) return p;
            else return -1;
        }
        
        int q = (p+r)/2;
		
        if(A[q] == val) return q;
        else if(A[q] > val){
           return binSearch(A, p,q-1, val);
        }
        else {
            return binSearch(A, q+1,r, val);
        }
    }
    
    int getPos(vector<int> A, int n, int val) {
    	int pos = binSearch(A, 0, n-1, val);
		
		//若元素出现多次，则返回第一次出现的位置。
        while(pos>=1 && A[pos-1] == A[pos]){
            pos --;
        }
        return pos;
        
    }
};

int main(){
	const int MAX_LEN = 200;
	vector<int> A(MAX_LEN, 0);
	int n;
	int val;
	
	cout<< "input n and A:"<< endl;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	cout<< "input val: ";
	cin>> val;
	
	BinarySearch B;
	
	cout<< B.getPos(A, n, val)<< endl;
	
	return 0;
}