/**
## 删除链表中的重复节点
### 题目: 
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

### 思路: 
#### 递归
只处理重复元素出现在开头的情况，其他情况向后递归。
#### 非递归
http://blog.csdn.net/u011080472/article/details/51286767
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

ListNode* deleteDuplication(ListNode* pHead){
	if(!pHead || !pHead->next) return pHead;
	
	// 重复头节点的情况
	if(pHead->val == pHead->next->val){
		ListNode* tmp = 0;
		while(pHead->next && pHead->val==pHead->next->val){	// 删除与头节点重复的节点
			tmp = pHead->next;
			pHead->next = pHead->next->next;
			delete tmp;
			tmp = pHead;
		}
		pHead = pHead->next;	// 删除头节点
		delete tmp;
		return deleteDuplication(pHead);  // 向后递归
	}
	else{  // 非重复的情况,向后递归.
		// 递归的结果是赋给pHead->next而不是直接返回
		pHead->next = deleteDuplication(pHead->next);  
		return pHead;
	}
}

int main(){
	int list_len = 0;
	cin >> list_len;
	ListNode head(list_len);	// 第一个节点保存链表的长度
	ListNode* tail = &head;
	
	int tmp;
	for(int i=0; i<list_len; ++i){
		cin >> tmp;
		tail->next = new ListNode(tmp);
		tail = tail->next;
	}
	
	head.next = deleteDuplication(head.next);
	for(ListNode* i=head.next; i!=NULL; i=i->next){
		cout<< i->val<< " ";
	}
	cout<< endl;
}