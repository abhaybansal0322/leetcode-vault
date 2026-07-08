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
    ListNode* reverseKGroup(ListNode* head, int k) {
    
    int size = 0;
    ListNode* temp = head;  
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    
    return helper(head, k, size);
}

ListNode* helper(ListNode* head, int k, int size) {
    
    if (head == NULL || k == 0 || k > size) {
        return head;
    }

    
    int count = 0;
    ListNode *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL && count < k) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;         
        curr = next;
        count++;
    }

    
    if (next != NULL) {
        head->next = helper(next, k, size - k);
    }

    
    return prev;
}
};