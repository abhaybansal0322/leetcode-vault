class Solution {
public:
    int calculate(string s) {
        int n = s.length();

        int res = 0;
        int num = 0;
        int sign = 1;
        stack<int> st; // sign,result

        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                num = num*10 + (s[i]-'0');
            }
            else if(s[i]=='+')
            {
                res += num*sign;
                num=0;
                sign=1;
            }
            else if(s[i]=='-')
            {
                res += num*sign;
                num=0;
                sign=-1;
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                num=0;
                res=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                res += num*sign;
                num=0;

                int sign_ = st.top(); st.pop();
                int res_ = st.top(); st.pop();

                res *= sign_;
                res +=res_;
            }
        }
        res += num*sign;
        return res;

    }
};