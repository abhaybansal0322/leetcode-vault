class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long long temp=0;
        if(x < 0)
        {
            return false;
        }
        if(x < 10)
        {
            return true;
        }
        while(num)
        {
            temp = temp*10 + num%10;
            num=num/10;
        }
        if(temp==x)
        {
            return true;
        }
        return false;
        
    }
};