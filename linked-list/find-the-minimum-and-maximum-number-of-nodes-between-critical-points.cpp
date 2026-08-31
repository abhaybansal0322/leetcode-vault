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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        vector<int> cp;
        int idx = 0;
        int prev = -1;
        while(temp) {
            if(temp->next && prev!=-1) {
                int val = temp->val;
                int nxt = temp->next->val;

                if(((val > nxt) && (val > prev)) || ((val < nxt) && (val < prev))) {
                    cp.push_back(idx);
                }
            }
            prev = temp->val;
            temp = temp->next;
            idx++;
        }

        if(cp.size() < 2)   return {-1,-1};
        int mini = INT_MAX;
        for(int i=1;i<cp.size();i++) {
            mini = min(mini,cp[i]-cp[i-1]);
        }

        return {mini,cp[cp.size()-1]-cp[0]};
    }
};