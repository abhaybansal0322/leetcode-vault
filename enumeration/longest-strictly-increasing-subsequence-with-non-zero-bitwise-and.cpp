class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();

        for(int bit=0;bit<=30;bit++) {

            vector<int> sub;
            sub.reserve(n);

            for(int x : nums) {

                if((x>>bit) & 1) sub.push_back(x);
            }

            if(sub.empty()) continue;
            vector<int> tails;
            for(int x : sub) {
                if(tails.empty() || x > tails.back()) {

                    tails.push_back(x);
                } else {
                    auto it = lower_bound(tails.begin(),tails.end(),x);
                    *it = x;
                }
            }

            if((int)tails.size() > maxLen) maxLen = tails.size();
        }

        return maxLen;
    }
};