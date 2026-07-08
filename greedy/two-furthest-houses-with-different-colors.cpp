class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++) {

            for(int j = n-1;j>i;j--) {

                if(colors[i] != colors[j]) {

                    ans = max(ans,j-i);
                    break;
                }
            }
        }

        return ans;
    }
};