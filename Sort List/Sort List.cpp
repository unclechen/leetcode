#include <iostream>
#include <algorithm>
//链表的归并排序，复杂度在O(nlogn)级别 
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addNode(ListNode*& head, int val) //因为会改变head指针的值，所以head要用引用传递 
{   
    if ( head == NULL )
    {
        //ListNode* newNode = new ListNode(val);
        head = new ListNode(val);
        return;
    }
    ListNode* pNode = head;
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
    }
    pNode->next = new ListNode(val);
}

void printList( ListNode* head )
{
    ListNode* pNode = head;
    if (head == NULL) return ;
    while (pNode != NULL)
    {
          cout << pNode->val << " ";
          pNode = pNode->next;
    }
    cout << endl;
}
ListNode* merge(ListNode* lh, ListNode* rh)
{
    ListNode *temp=new ListNode(0);  
    ListNode *p=temp;  
    while(lh&&rh)
    {  
        if(lh->val<=rh->val)
        {  
            p->next=lh;  
            lh=lh->next;  
        }  
        else
        {  
            p->next=rh;  
            rh=rh->next;  
        }  
        p=p->next;  
    }  
    if(!lh)  
        p->next=rh;  
    else  
        p->next=lh;  
    p=temp->next;  
    temp->next=NULL;  
    delete temp;  
    return p; 
}

ListNode* mergeSort(ListNode *head)
{
    if(!head||!head->next)   //just one element  
        return head; 
    ListNode *p=head, *q=head, *pre=NULL;  
    while(q&&q->next!=NULL)
    {  
        q=q->next->next;  
        pre=p;  
        p=p->next;  //divide into two parts  
    } 
    pre->next = NULL;  
    ListNode *lhalf = mergeSort(head);  
    ListNode *rhalf = mergeSort(p);  //recursive  
    return merge(lhalf, rhalf);   //merge  
} 

ListNode *sortList(ListNode *head) 
{
    if (head == NULL || head->next == NULL) 
        return head;
    return mergeSort(head);
}
/*
1.写了一个单链表的添加元素功能函数addNode()
2.然后实现了单链表的归并排序，要求时间复杂度O(logn)，空间复杂度是常数级别。 
*/
int main()
{
    ListNode *head = NULL;//new ListNode(2);
    addNode(head, 2);
    addNode(head, 4);
    addNode(head, 6);
    addNode(head, 1);
    addNode(head, 3);
    addNode(head, 5);
    //ListNode* pNode = sortList(head); 
    printList(head);
    printList(sortList(head)); 
    
    system("pause");
    return 0;
}
