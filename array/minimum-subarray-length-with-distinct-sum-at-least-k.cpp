class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long currSum = 0;
        int minLen = INT_MAX;
        int l = 0;
        int n = nums.size();

        vector<int> freq(100001,0);

        for(int r =0;r<n;r++) {

            int val = nums[r];
            if(freq[val]==0) {

                currSum += val;
            }
            freq[val]++;

            while(currSum >= k) {

                minLen = min(minLen,r-l+1);

                int lVal = nums[l];
                freq[lVal]--;

                if(freq[lVal] == 0){

                    currSum -= nums[l];
                }
                l++;
            }   
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }  
};