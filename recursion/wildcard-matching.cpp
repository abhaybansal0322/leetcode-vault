class Solution {
    int n,m;
    vector<vector<int>> memo;

    bool helper(const string &s, const string &p, int i, int j) {
        if(j == m)  return i == n;
        if(memo[i][j]!=-1)  return memo[i][j];

        bool ok;
        if(p[j] == '*') {
            ok = (helper(s,p,i,j+1)) || (i<n && helper(s,p,i+1,j));
        }
        else if(p[j] == '?') {
            ok = i<n && helper(s,p,i+1,j+1);
        } else {
            ok = (i<n && s[i] == p[j]) ? helper(s,p,i+1,j+1) : false;
        }

        return memo[i][j] = ok;
    }
public:
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        memo.assign(n+1,vector<int>(m+1,-1));

        return helper(s,p,0,0);
    }
};