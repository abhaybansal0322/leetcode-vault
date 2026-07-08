class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long int score = 0;
        priority_queue<int> q;

        for (int i = 0; i < n; i++) {
            q.push(nums[i]);
        }

        while (k--) {
            int element = q.top();
            q.pop();
            score += element;
            q.push(ceil(element / 3.0));
        }

        return score;
    }
};