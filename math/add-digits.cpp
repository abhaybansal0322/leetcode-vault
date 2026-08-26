class Solution {
    int helper(int num) {
        if(num < 10) {
            return num;
        }

        int temp = num;
        int sum = 0;
        while(temp) {
            int dig = temp%10;
            temp /= 10;

            sum += dig;
        }

        return helper(sum);
    }
public:
    int addDigits(int num) {
        return helper(num);
    }
};