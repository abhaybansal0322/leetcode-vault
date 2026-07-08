class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;

        for(int i=0;i<n;i++)
        {
            string curr = "";
            curr += to_string(nums[i]);

            bool flag = false;
            while(i+1 <n && nums[i+1]==nums[i]+1)
            {
                flag=true;
                i++;
            }

            if(flag)
            {
                curr += "->";
                curr += to_string(nums[i]);
                flag=false;
            }

            res.push_back(curr);
        }

        return res;
    }
};