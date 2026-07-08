class Solution {
    ListNode* getReversed(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = getReversed(slow);
        ListNode* first = head;

        int maxSum = 0;

        while (second) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};