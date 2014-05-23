#include <iostream>

using namespace std;

struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) 
{
	if (!head || !head->next)
		return false;
	ListNode *slow = head;
	ListNode *fast = head;
	while (slow && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == NULL) 
		{
			return false;
		}
		if (fast == slow)
			return true;
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
	//node3->next = node4;
	//node4->next = node5; 
	//node5->next = node3; 
	bool ret = hasCycle(node1);
	if (ret == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	return 0;
}
