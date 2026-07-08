class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.rbegin(),cost.rend());
        int n = cost.size();
        int res = 0;

        for(int i=0;i<n;i+=3) {

            res += cost[i];
            if(i+1<n) res += cost[i+1];
        }

        return res;
    }
};