class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long result = 0;
        long long mul = 1;
        long long sum = 0;

        while(n) {

            int dig = n%10;
            n = n/10;

            if(dig == 0)    continue;

            sum += dig;

            result = dig*mul + result;
            mul = mul*10;
        }

        return (sum*result);
    }
};