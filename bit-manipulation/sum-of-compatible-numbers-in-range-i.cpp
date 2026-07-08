class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        
        int l = max(n-k,1);
        int r = n+k;
        int ans = 0;

        for(int x=l;x<=r;x++) {
            
            if((abs(n-x) <= k) && ((n&x) == 0)) ans += x;
        }

        return ans;
    }
};