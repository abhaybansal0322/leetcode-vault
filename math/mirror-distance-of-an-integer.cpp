class Solution {
    
    int reverse(int n) {

        int r = 0;
        while(n) {

            r = r*10 +(n%10);
            n = n/10;
        }
        return r;
    }
public:
    int mirrorDistance(int n) {
        
        return abs(n-reverse(n));
    }
};