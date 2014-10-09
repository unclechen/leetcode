// Remove Nth Node From End of List
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
	if (NULL == head) return;
	while(head) {
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if (NULL == head || 0 == n) return head;
	int len = 0;
	ListNode *pNode = head;
	while (pNode) {
		++len;
		pNode = pNode->next;
	}
	if (n > len) return head;
	// cout << len << endl;
	int offset = len - n;
	pNode = head;
	if (0 == offset) {
		head = head->next;
		return head;
	}
	while (offset > 1) {
		pNode = pNode->next;
		--offset;
	}
	// 找到要删除节点的前一个节点
	pNode->next = pNode->next->next;
	
	return head; 
} 

int main() {
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	//node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	printList(node1);
	cout << endl;
	printList(removeNthFromEnd(node1, 1)) ; 
	return 0; 
}
