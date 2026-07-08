class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        vector<int> fact(10,1);
        for(int i=2;i<=9;i++) fact[i] = fact[i-1]*i;

        vector<int> digits(10,0);

        long long total = 0;
        string s = to_string(n);

        for(auto ch : s) {

            int dig = ch - '0';
            digits[dig]++;
            total += fact[dig];
        }

        string t = to_string(total);

        for(auto ch : t) {

            int dig = ch - '0';
            if(digits[dig] <= 0) return false;
            else {
                digits[dig]--;
            }
        }
        
        for(auto num : digits) {

            if(num != 0) return false;
        }

        return true;
        
    }
};