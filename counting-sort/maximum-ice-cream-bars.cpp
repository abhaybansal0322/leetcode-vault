class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int n = costs.size();
        int maxVal = *max_element(costs.begin(),costs.end());
        vector<int> cntArr(maxVal+1,0);

        for(int i=0;i<n;i++) {
            cntArr[costs[i]]++;
        }

        for(int i=1;i<=maxVal;i++) {
            cntArr[i] += cntArr[i-1];
        }

        vector<int> ans(n);
        for(int i=n-1;i>=0;i--) {

            ans[cntArr[costs[i]]-1] = costs[i];
            cntArr[costs[i]]--;
        }

        int numcoins = 0;
        for(int i=0;i<n;i++) {
            
            if(coins >= ans[i]) {
                numcoins++;
                coins = coins - ans[i];
            } else break;
        }

        return numcoins;
    }
};