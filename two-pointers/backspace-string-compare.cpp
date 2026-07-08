class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> one;
        vector<char> two;
        int i=0;
        while(i < s.size())
        {
            if(s[i]=='#')
            {
                if(one.size()!=0)
                {
                    one.pop_back();
                }
            }
            else{
                one.push_back(s[i]);
            }
            i++;
        }
        int j=0;
        while(j < t.size())
        {
            if(t[j]=='#')
            {
                if(two.size()!=0)
                {
                    two.pop_back();
                }
            }
            else{
                two.push_back(t[j]);
            }
            j++;
        }

        return (one==two);
        
    }
};