class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {

        vector<int> L(n,1000000000);
        L[0] = 0;

        for(auto& res : restrictions) {

            L[res[0]] = min(L[res[0]],res[1]);
        }

        for(int i=0;i<n-1;i++) {

            L[i+1] = min(L[i+1],L[i]+diff[i]);
        }

        for(int i=n-2;i>=0;i--) {

            L[i] = min(L[i],L[i+1]+diff[i]);
        }

        int maxi = 0;

        for(int val : L) {

            maxi = max(maxi,val);
        }

        return maxi;
    }
};