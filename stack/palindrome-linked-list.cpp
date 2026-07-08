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
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;

        while(curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=Next;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        // ListNode* temp=head;
        // int size = 0;
        // while(temp)
        // {
        //     temp=temp->next;
        //     size++;
        // }
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        while(temp1!=NULL && temp1->next!=NULL)
        {
            temp1=temp1->next->next;
            temp2=temp2->next;
        }

        temp2 = Reverse(temp2);
        temp1=head;

        while(temp2)
        {
            if(temp1->val!=temp2->val)
            {
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return true;
    }
};