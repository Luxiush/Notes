/**
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
**/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if(!pHead || !pHead->next) return 0;
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        do {
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow != fast);
        
        while(slow != pHead){
            pHead = pHead->next;
            slow = slow->next;
        }
        
        return pHead;
    }
};

int main(){
    
    return 0;
}