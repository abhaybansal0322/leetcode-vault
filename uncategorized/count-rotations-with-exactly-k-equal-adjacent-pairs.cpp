class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.length();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == s[(i+1)%n]) {
                cnt++;
            }
        }

        for(int r = 0;r<n;r++) {
            int score = cnt - ((s[(r-1+n)%n]) == s[r] ? 1 : 0);
            if(score == k) ans++;
        }

        return ans;
    }
};