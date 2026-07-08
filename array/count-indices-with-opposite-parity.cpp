class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++) {
            int checkRem = nums[i]%2;
            int cnt = 0;
            for(int j=i+1;j<n;j++) {
             if(nums[j]%2 != checkRem) {
                 cnt++;
             }   
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};