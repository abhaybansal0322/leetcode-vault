class Solution {
    typedef long long ll;
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        
        int n = prices.size();
        vector<ll> pre(n),orig(n);
        pre[0] = prices[0];
        orig[0] = strategy[0]*prices[0];

        for(int i=1;i<n;i++) {

            pre[i] = pre[i-1] + prices[i];
            orig[i] = orig[i-1] + strategy[i]*prices[i];
        }

        ll change = 0;

        for(int i=k-1;i<n;i++) {

            ll origSum = orig[i];
            if(i-k >= 0) {

                origSum = origSum - orig[i-k];
            }
            ll newSum = pre[i] - pre[i-(k/2)];

            change = max(change, newSum-origSum);
        }

        return orig[n-1]+change;


    }
};