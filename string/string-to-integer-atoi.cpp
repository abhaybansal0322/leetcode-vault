class Solution {

    const int MAX = INT_MAX;
    const int MIN = INT_MIN;
public:
    int myAtoi(string s) {

        int n = s.length();
        long long num = 0;
        int sign = 1;

        int i=0;
        while(i<n && s[i] == ' ') {

            i++;
        }

        if(i == n)  return 0;
        if(s[i] == '-') {

            sign = -1;
            i++;
        }

        else if(s[i] == '+') {

            i++;
        }

        while(i < n && isdigit(s[i])) {

            int digit = s[i] - '0';
            num = num*10 + digit;

            if(num*sign <= MIN) return MIN;

            if(num*sign >= MAX) return MAX;

            i++;
        }

        return static_cast<int>(sign*num);


    
    }
};