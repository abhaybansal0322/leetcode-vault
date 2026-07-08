class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long ans = 0;

        int pair = min(need1,need2);
        int pairCost = min(costBoth,cost1+cost2);

        ans += 1LL*(1LL*pairCost*pair);

        need1 -= pair;
        need2 -= pair;

        ans += 1LL*need1*(min(cost1,costBoth));
        ans += 1LL*need2*(min(cost2,costBoth));

        return ans;
    }
};