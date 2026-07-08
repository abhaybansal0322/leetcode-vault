class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {

        long long a=0,b=0;
        long long n = s.length();

        for(int i=0;i<n;i++) {

            if(s[i]!=t[i]) {

                if(s[i]=='0') a++;
                else b++;
            }
        }

        long long pairCost = min((long long)swapCost,2LL*flipCost);
        long long pairs = min(a,b);

        long long cost = pairs*pairCost;

        long long rem = abs(a-b);

        long long costSame = min((long long)crossCost+swapCost,2LL*flipCost);

        cost += (rem/2)*costSame;

        if(rem%2 == 1) {

            cost += flipCost;
        }

        return cost;
    }
};