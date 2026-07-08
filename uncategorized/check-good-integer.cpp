class Solution {
public:
    bool checkGoodInteger(int n) {
        
        int temp = n;
        long long digitSum = 0, squareSum = 0;
        while(temp) {
            int dig = temp%10;
            temp /= 10;

            digitSum += dig;
            squareSum += (dig*dig);
        }

        return squareSum - digitSum >= 50;
    }
};