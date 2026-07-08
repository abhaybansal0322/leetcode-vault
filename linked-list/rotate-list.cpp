class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: Make it circular
        tail->next = head;

        // Step 3: Find new tail
        k = k % n;
        int stepsToNewTail = n - k - 1;

        ListNode* newTail = head;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // Step 4: Break circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};