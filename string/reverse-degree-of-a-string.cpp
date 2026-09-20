class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++) {
            int idx = s[i]-'a';
            int revIdx = 26-idx;
            int prod = revIdx*(i+1);
            res += prod;
        }

        return res;
    }
};