class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        while(temp) {
            int dig = temp%10;
            temp /= 10;

            sum += dig;
            prod *= dig;
        }

        return (n%(sum+prod) == 0);
    }
};