class Solution {
    int helper(string s ,char ch)
    {
        int swaps = 0;
        for(int i=0;i<s.size();i++)
        {
            if(ch!=s[i])
            {
                swaps++;
            }
            ch ^=1;
        }

        return swaps/2;
    }
public:
    int minSwaps(string s) {
        int one=0,zero=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
        }

        if(abs(one-zero)>1)
        {
            return -1;
        }

        if(one>zero)
        {
            return helper(s,'1');
        }
        if(zero>one)
        {
            return helper(s,'0');
        }

        return min(helper(s,'1'),helper(s,'0'));
        
    }
};