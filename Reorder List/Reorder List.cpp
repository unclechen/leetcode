#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head)
{
	if (head == NULL)
		return;
	ListNode *p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next; 
	}
	cout << endl;
}

ListNode* reverseList(ListNode* head)  
{  
    if(head==NULL || head->next==NULL)  
        return head;  
    ListNode* tmphead = reverseList(head->next);  
    head->next->next = head;  
    head->next = NULL;  
    return tmphead;  
}  

void reorderList(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return;
	ListNode *slow = head;
	ListNode *fast = head;
	//divide List into two subList,subList1 is longer than or equal to subList2
	while (fast && fast->next!= NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *right_head = slow->next;
	slow->next = NULL;
	//printList(head);
	right_head = reverseList(right_head);
	//printList(right_head);
	//merge two subList 
	ListNode *left_head = head;
	ListNode *left_next = left_head;
	ListNode *right_next = right_head;
	while (left_head != NULL && right_head != NULL)
	{
		left_next = left_head->next;
		right_next = right_head->next;
		left_head->next = right_head;
		right_head->next = left_next;
		left_head = left_next;
		right_head = right_next;
		
	}
}
/*
下面注释里是我原来写的最简单的方法，没有什么算法其实。
用的就是遍历，复杂度为n方。因此直接超时了。。
思路是：每次找到最后一个节点，插入到前面的节点中去。 
*/

void reorderList2(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return;
	ListNode *ptr = head;
	
	while (ptr != NULL && ptr->next != NULL)
	{
		ListNode *pre = NULL;
		ListNode *last = ptr;
		while (last != NULL && last->next != NULL)
		{
			pre = last;
			last = last->next;
		}
		pre->next = NULL;
		
		last->next = ptr->next;
		ptr->next = last;
		ptr = last->next;
	} 
} 


int main()
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5; 
	printList(node1);
	reorderList(node1);
	//reorderList2(node1);
	printList(node1);
	
	return 0;
}
