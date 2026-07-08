class Solution {
public:
    int minOperations(string s) {
        int mx=0;

        for(int i=0;i<s.length();i++) {

            if(s[i] == 'a') continue;

            mx = max(mx , ('z'-s[i])+1);
        }

        return mx;
    }
};