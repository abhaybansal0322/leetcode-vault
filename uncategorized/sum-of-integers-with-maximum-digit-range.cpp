class Solution {

    pair<int,int> getDigRange(int num) {

        int s = INT_MAX;
        int l = INT_MIN;

        while(num) {

            int dig = num%10;
            s = min(dig,s);
            l = max(l,dig);
            num = num/10;
        }

        return {s,l};
    }
public:
    int maxDigitRange(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> temp(n);
        int target = INT_MIN;
        for(int i=0;i<n;i++) {

            int num = nums[i];
            auto [s,l] = getDigRange(num);
            temp[i] = {num,l-s};
            target = max(target,l-s);
        }

        int result = 0;
        for(int i=0;i<n;i++) {

            if(temp[i].second == target) {
                result += temp[i].first;
            }
        }

        return result;
    }
};