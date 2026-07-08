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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=NULL;
        ListNode *tail =NULL;
        int carry=0;

        ListNode *temp1=l1;
        ListNode *temp2=l2;

        while(temp1!=NULL && temp2!=NULL)
        {
            int value = temp1->val + temp2->val + carry;
            carry = value /10;

            if(ans==NULL)
            {
                ListNode *newNode = new ListNode(value%10);
                ans=newNode;
                tail=ans;
            }
            else{
                ListNode *newNode = new ListNode(value%10);
                tail->next=newNode;
                tail=tail->next;
            }

         
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1!=NULL)
        {
            int value = temp1->val + carry;
            carry = value/10;
            if(ans==NULL)
            {
                ListNode *newNode = new ListNode(value%10);
                ans=newNode;
                tail=ans;
            }
            else{
                ListNode *newNode = new ListNode(value%10);
                tail->next=newNode;
                tail=tail->next;
            }
            temp1=temp1->next;
        }

        while(temp2!=NULL)
        {
            int value = temp2->val + carry;
            carry = value/10;
            if(ans==NULL)
            {
                ListNode *newNode = new ListNode(value%10);
                ans=newNode;
                tail=ans;
            }
            else{
                ListNode *newNode = new ListNode(value%10);
                tail->next=newNode;
                tail=tail->next;
            }
            temp2=temp2->next;
        }

        while (carry > 0) {
                ListNode *newNode = new ListNode(carry % 10);
    tail->next = newNode;
    tail = tail->next;
    carry /= 10;
}


        return ans;

        
        
    }
};