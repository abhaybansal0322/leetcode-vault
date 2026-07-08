class Solution {

    int BS(int val,int idx,vector<int>& nums2) {

        int n = nums2.size();
        int l = idx;
        int r = n-1;
        int res = -1;

        while(l<=r) {

            int mid = l + (r-l)/2;
            if(nums2[mid] < val) {

                r = mid-1;
            } else {
                res = mid;
                l = mid+1;
            }
        }
        return res;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = INT_MIN;
        int n = nums1.size();

        for(int i=0;i<n;i++) {

            int j = BS(nums1[i],i,nums2);
            ans = max(ans,j-i);
        }

        return ans == -1 ? 0 : ans;
    }
};