class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
    
        int temp =n;
        while(temp)
            {
                int dig = temp%10;
                digits.push_back(dig);
                temp = temp/10;                
            }
        int Size = digits.size();
        sort(digits.begin(),digits.end());
        
        return digits[Size-1]*digits[Size-2];
    }
};