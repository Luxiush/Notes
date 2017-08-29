/*leetcode gas-station*/
/* http://blog.csdn.net/kenden23/article/details/14106137 
## 两个结论
1. 如果所有油站的油量小于所有里程的耗油量那么肯定无法走完全程
2. 如果从0到i的剩余油量小于0，则起点一定位于i之后(>=i)

## 思路：
* 当前起点j从0开始一个一个地试，如果走到第i个站时剩余油量小于0则说明j不是要找的起点，将j移到下一个站重复以上过程。
* 由于**结论2**所以在走到第i个站油量小于0时可以直接将j移到i+1，从而加速循环
*/
#include <iostream>
#include <vector>

using namespace std;

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0; 
		for(int i=0; i<gas.size(); ++i){
			sum += gas[i]-cost[i];
		}
		if(sum<0) return -1;
		
		int left = 0;
		int j = 0;
		for(int i=0; i<gas.size(); ++i){
			left += gas[i]-cost[i];
			if(left<0){
				left = 0; 
				j = (i+1)%gas.size();
			}
		}
		return j;
    }

int main(){
	
	return 0;
}
