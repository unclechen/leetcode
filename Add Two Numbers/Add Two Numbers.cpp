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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	if ( l1 == NULL || l2 == NULL )
		return l1;
	ListNode *head = l1;
	ListNode *tail = NULL; //保存尾巴，尾巴有两个作用，一个是用来处理两个链表长度不一样时，保存List1的尾巴；一个是用来处理最后一个进位，当两个链表都遍历完成后，flag最后还为1的话，链表中要增加一个新的节点 
	int flag = 0; //保存进位 
	while (l1 && l2)
	{
		l1->val = l1->val + l2->val + flag;
		if (l1->val >= 10)
		{
			l1->val -= 10; 
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		tail = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		l1->val = l1->val + flag;
		if (l1->val >= 10)
		{
			l1->val -= 10;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		tail = l1;
		l1 = l1->next;
	}
	while (l2)
	{
		tail->next = l2;
		l2->val = l2->val + flag;
		if (l2->val >= 10)
		{
			l2->val -= 10;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		tail = l2;
		l2 = l2->next;
	}
	if (flag == 1)
	{ 
		ListNode *newNode = new ListNode(1);
		tail->next = newNode;
	} 
	return head;
} 

int main()
{
	ListNode *head1 = new ListNode(1);
	ListNode *node1 = new ListNode(4);
	ListNode *node2 = new ListNode(3);
	head1->next = node1;
	node1->next = node2;
	ListNode *head2 = new ListNode(9);
	ListNode *node3 = new ListNode(9);
	ListNode *node4 = new ListNode(4);
	head2->next = node3;
	node3->next = node4;
	printList(head1);
	printList(head2);
	ListNode *head = addTwoNumbers(head1, head2);
	printList(head);
	
	return 0;
}
