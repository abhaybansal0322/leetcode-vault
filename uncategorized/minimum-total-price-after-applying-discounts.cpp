class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());

        int n = prices.size();
        int m = discounts.size();

        int i = 0;
        int j = 0;
        double res = 0;

        while(i<n && j<m) {
            
            double val = (double)(prices[i] * (100 - discounts[j])) / 100.0;
            res += val;
            j++;
            i++;
        }

        while(i<n) {
            res += prices[i];
            i++;
        }

        return res;
    }
};