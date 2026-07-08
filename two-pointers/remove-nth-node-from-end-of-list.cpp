/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findSize(ListNode *head)
    {
        int size=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=findSize(head);
        if(size==1)
        {
            return NULL;
        }
        if(n==size)
        {
            ListNode *newHead=head->next;
            head=NULL;
            return newHead;
        }

        ListNode *temp=head;
        int i=0;
        while(i < size-n-1)
        {
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
       
        return head;
    }
};