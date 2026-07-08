class Solution {
public:
    

    int maxProfit(vector<int>& prices) {
        // int mini=prices[0];
        // int profit=INT_MIN;
        // int i=0;
        // while(i<prices.size())
        // {
        //     int diff=prices[i]-mini;
        //     profit=max(profit,diff);
        //     mini=min(mini,prices[i]);
        //     i++;
        // }
        // return profit;

        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;

    }
};