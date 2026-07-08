class Solution {

    int rev(int num) {

        int r = 0;
        while(num) {

            r = r*10 + (num%10);
            num = num/10;
        }

        return r;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = INT_MAX;

        for(int i=n-1;i>=0;i--) {

            int r = rev(nums[i]);
            if(mp.count(r)) {

                ans = min(mp[r]-i,ans);
            }
            
            mp[nums[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};