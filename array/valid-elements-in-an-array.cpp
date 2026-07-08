class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> lmax(n);
        vector<int> rmax(n);

        for(int i=0;i<n;i++) {
            if(i == 0) lmax[i] = nums[i];
            else lmax[i] = max(nums[i],lmax[i-1]);

        }
        

        for(int i=n-1;i>=0;i--) {
            if(i == n-1) rmax[i] = nums[i];
            else rmax[i] = max(nums[i],rmax[i+1]);
        }

        for(int i=0;i<n;i++) {

            if(i == 0 || i == n-1)  res.push_back(nums[i]);

            else if(nums[i] > lmax[i-1] || nums[i] > rmax[i+1]) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};