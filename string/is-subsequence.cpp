#include<queue>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char> check;
        for(int i=0;i<s.size();i++)
        {
            check.push(s[i]);
        }

        for(int j=0;j<t.size();j++)
        {
            char val=check.front();
            if(t[j]==val)
            {
                check.pop();
            }
        }

        if(check.size()==0)
        {
            return true;
        }
        return false; 
    }
};