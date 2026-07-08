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

    ListNode* mergeTwoList(ListNode* list1,ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 && list2) {

            if(list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }

            else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1) temp->next = list1;
        else    temp->next = list2;

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {

            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* MS(ListNode* head) {

        if(!head || !head->next)    return head;

        ListNode* mid = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL;

        leftHead = MS(leftHead);
        rightHead = MS(rightHead);

        return mergeTwoList(leftHead,rightHead);
    }
public:
    ListNode* sortList(ListNode* head) {
        return MS(head);
    }
};