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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(),nums.end());
    
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL)
        {
            int checkVal = curr->val;
            if(s.find(checkVal)!=s.end())
            {
                if(curr==head)
                {
                    head=head->next;
                    curr=curr->next;
                }
                else{
                    prev->next=curr->next;
                    curr=NULL;
                    curr=prev->next;
                }
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
        
    }
};