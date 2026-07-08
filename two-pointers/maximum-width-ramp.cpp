class Solution {
public:
    // int maxWidthRamp(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> indices(n);

    //     for (int i = 0; i < n; i++) {
    //         indices[i] = i;
    //     }

    //     sort(indices.begin(), indices.end(), [&](int a, int b) {
    //         if (nums[a] == nums[b])
    //             return a < b;

    //         return nums[a] < nums[b];
    //     });

    //     int minI = n;
    //     int ans = 0;

    //     for (int i = 0; i < n; i++) {
    //         ans = max(ans, indices[i] - minI);
    //         minI = min(minI, indices[i]);
    //     }

    //     return ans;
    // }

    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxEl(n);
        int maxElement=-1;

        for(int i=n-1;i>=0;i--){
            maxElement=max(maxElement,nums[i]);
            maxEl[i]=maxElement;
        }

        int i=0;
        int j=0;
        int ans=0;

        while(i < n && j < n)
        {
            if(maxEl[j] >= nums[i])
            {
                ans=max(ans,j-i);
            }
            else{
                i++;
            }
            j++;
        }

        return ans;
        
    }
};