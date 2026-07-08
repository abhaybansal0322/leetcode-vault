class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost=accumulate(cost.begin(),cost.end(),0);
        int totalGas =accumulate(gas.begin(),gas.end(),0);

        if(totalCost > totalGas)
            return -1;
        
        int n = cost.size();
        int tot = 0;
        int idx = 0;

        for(int i=0;i<n;i++)
        {
            tot +=  gas[i] - cost[i];
            if(tot < 0)
            {   tot = 0;
                idx = i+1;
            }
        }

        return idx;

    }
};