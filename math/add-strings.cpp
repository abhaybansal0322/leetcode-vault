class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int n1 = num1.length();
        int n2 = num2.length();

        int i = n1-1;
        int j = n2-1;
        int carry = 0;
        string result;

        while(i >= 0 || j >= 0) {

            int sum = carry;
            
            if(i >= 0) {
                
                int dig = num1[i] - '0';
                sum+=dig;
                i--;
            }

            
            if(j >= 0) {

                int dig = num2[j] - '0';
                sum+=dig;
                j--;
            }

            result.push_back(sum%10 + '0');
            carry = sum/10;
        }

        if(carry)   result.push_back(carry + '0');

        reverse(result.begin(),result.end());
        return result;
    }
};