class Solution {
public:
    bool canBeValid(string s, string locked) {

        // if((s.length()&1)==1)
        //     return false;

        // stack<int> openClose;
        // stack<int> open;
        
        // for(int i=0;i<s.length();i++)
        // {
        //     if(locked[i]=='0')
        //     {
        //         openClose.push(i);
        //     }

        //     else if(s[i]=='(')
        //     {
        //         open.push(i);
        //     }

        //     else if(s[i]==')')
        //     {
        //         if(!open.empty())
        //         {
        //             open.pop();
        //         }
        //         else if(!openClose.empty())
        //         {
        //             openClose.pop();
        //         }
        //         else{
        //             return false;
        //         }
        //     }
        // }

        // while(!open.empty() && !openClose.empty() && open.top() < openClose.top())
        // {
        //     open.pop();
        //     openClose.pop();
        // }

        // return open.empty();

        if((s.length()&1)==1)
            return false;

        int open = 0;
        int close = 0;

        int n = s.length();

        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                open++;
            }
            else if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
                open--;
            }

            if(open < 0)
            {
                return false;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                close++;
            }

            else if(s[i]==')')
            {
                close++;
            }

            else if(s[i]=='(')
            {
                close--;
            }

            if(close < 0)
            {
                return false;
            }
        }


        return true;

    }
};