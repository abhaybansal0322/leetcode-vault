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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* dummy = new ListNode(-1,head);
        ListNode* temp  = head;
        ListNode* prev = NULL;

        while(temp)
        {
            if(temp->next==NULL)
            {
                if(prev)
                prev->next=temp;
                temp=temp->next;
            }

            else if(temp->val != temp->next->val)
            {
                prev = temp;
                temp=temp->next;
            }
            else
            {
                int value = temp->val;
                while(temp && temp->val == value)
                {
                    temp=temp->next;
                }

                if(prev==NULL)
                {
                    dummy->next = temp;
                }
                else
                {
                    prev->next = temp;
                }
                
            }
        }

        return dummy->next;
        
    }
};