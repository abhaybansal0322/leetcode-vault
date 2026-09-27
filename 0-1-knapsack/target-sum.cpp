class Solution {
    int dp[21][1001];
    
    int solve(int n, int target, vector<int>& arr) {
        if(n == 0) {
            return (target == 0) ? 1 : 0;
        }
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int skip = solve(n-1,target,arr);
        int take = 0;
        if(arr[n-1] <= target) {
            take = solve(n-1,target-arr[n-1],arr);
        }
        
        return dp[n][target] = skip+take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        target = abs(target);

        int sum = accumulate(begin(nums),end(nums),0);
        if((sum+target)%2 != 0) return 0;
        int targetNew = (sum+target)/2;

        return solve(n,targetNew,nums);
    }
};