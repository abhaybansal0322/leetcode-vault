class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result = INT_MIN;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int root = (int) sqrt(nums[i]);
            if(root*root == nums[i] && mp.find(root)!=mp.end())
            {
                mp[nums[i]] = mp[root] + 1;
            }
            else{
                mp[nums[i]]=1;
            }

            result = max(result,mp[nums[i]]);
        }

        return result == 1 ? -1 : result;
        
    }
};