class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int curr = 0;
        int res = INT_MIN;

        for(auto&num : gain) {

            curr += num;
            res = max(res,curr);
        }

        return max(res,0);
    }
};