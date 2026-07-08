class Solution {
public:
    bool validDigit(int n, int x) {
        bool res = false;
        while(n>=10) {

            int dig = n%10;
            n = n/10;
            if(dig == x) res = true;
        }

        if(n%10 == x) return false;

        return res;
    }
};