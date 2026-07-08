class Solution {
    long long memo[16][2][10];

    long long helper(int idx, bool isLess, int lastDig, string& S, vector<bool>& inPath) {

        if(idx == 16) return 1;

        if(memo[idx][isLess][lastDig] != -1) return memo[idx][isLess][lastDig];

        long long res = 0;
        int lim = isLess ? 9 : (S[idx]-'0');

        for(int d=0;d<=lim;d++) {

            if(inPath[idx]) {

                if(d >= lastDig) {

                    res += (helper(idx+1,isLess || (d<lim),d,S,inPath));
                }
            } else {

                res += (helper(idx+1,isLess || (d<lim),lastDig,S,inPath));
            }
        }

        return memo[idx][isLess][lastDig] = res;
    }
    
    long long solve(long long maxVal, string &directions) {

        if(maxVal < 0) return 0;

        string s = to_string(maxVal);
        string S = string(16 - s.length(),'0')+s;

        vector<bool> inPath(16,false);
        int r=0,c=0;
        inPath[0] = true;

        for(char ch : directions) {

            if(ch == 'D') r++;
            else c++;

            inPath[4*r+c] = true;
        }
        memset(memo,-1,sizeof(memo));

        return helper(0,false,0,S,inPath);
    }
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        return solve(r,directions) - solve(l-1,directions);
    }
};