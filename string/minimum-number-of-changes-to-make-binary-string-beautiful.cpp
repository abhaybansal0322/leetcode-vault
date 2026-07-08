class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i=i+2)
        {
            if(s[i]=='1' && s[i+1]=='0')
            {
                s[i+1]='1';
                ans++;
            }
            else if(s[i]=='0' && s[i+1]=='1')
            {
                s[i+1]='0';
                ans++;
            }
            else{
                continue;
            }
        }

        return ans;   
    }
};