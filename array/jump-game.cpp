// class Solution {
//     bool solve(int idx,vector<int>& nums,vector<int>& dp)
//     {
//         if(idx >= nums.size()-1)
//             return true;

//         if(dp[idx] != -1)
//         {
//             return dp[idx] ? true : false;
//         }
        
//         bool ans = false;
//         for(int i=1;i<=nums[idx];++i)
//         {
//             ans = ans | solve(idx+i,nums,dp);
//             if(ans)
//             {
//                 break;
//             }
//         }

//         dp[idx] = ans ? 1 : 0;
//         return ans;
        
//     }
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1)
//             return true;
//         vector<int> dp(n+1,-1);
//         return solve(0,nums,dp);
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for(int i=0;i<n;++i)
        {
            if(i > farthest)
                return false;

            if(farthest >= n-1)
                break;

            farthest = max(farthest,i+nums[i]);
        }

        return true;  
    }
};