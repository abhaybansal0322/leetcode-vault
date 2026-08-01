class Solution {
public:
    int countValidPrefixes(string s) {
        
        int n = s.length();
        int cnt = 0;
        int cnt1 = 0,cnt0 = 0;

        for(int i=0;i<n;i++) {

            if(s[i] == '0') cnt0++;
            if(s[i] == '1') cnt1++;

            if(abs(cnt0-cnt1) <= 1) cnt++;
        }

        return cnt;
    }
};