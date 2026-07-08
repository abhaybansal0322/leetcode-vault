class Solution {
    bool isPrime(int x) {
        if(x<2) return false;
        for(int i=2;i*i<=x;i++) {
            if(x%i == 0) return false;
        }
        return true;
    }

    int rev(int n) {
        int rev = 0;
        while(n) {
            rev =rev*10 + (n%10);
            n /= 10;
        }
        return rev;
    }
public:
    int sumOfPrimesInRange(int n) {
        int r = rev(n);
        int l = min(n,r);
        int h = max(n,r);

        int sum = 0;
        for(int x=l;x<=h;x++) {
            if(isPrime(x)) sum += x;
        }
        return sum;
    }
};