class Solution {

    int helper(int num) {
        int prod = 1;
        while(num) {
            int dig = num%10;
            num /= 10;
            prod *= dig;
        }

        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<=n+10;i++) {
            int prod = helper(i);
            if(prod%t == 0) return i;
        }

        return -1;
    }
};