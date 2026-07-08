class Solution {

    bool checkInvalid(int x) {

        return x == 3 || x == 4 || x == 7;
    }

    bool checkNotSame(int x) {

        return x == 2 || x == 5 || x == 6 || x == 9;
    }

    bool solve(int num) {

        bool flag = false;
        while(num) {

            int dig = num%10;
            if(checkInvalid(dig)) return false;

            if(checkNotSame(dig)) {
                flag = true;
            }

            num = num/10;
        }
        return flag;
    }

public:
    int rotatedDigits(int n) {
        
        int res = 0;
        for(int i=1;i<=n;i++) {

            if(solve(i)) {

                res++;
            }
        }

        return res;
    }
};