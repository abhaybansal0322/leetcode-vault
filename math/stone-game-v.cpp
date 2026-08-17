class Solution {
    vector<int> pref;
    vector<vector<int>> memo;

    int helper(int l,int r) {
        if(l>=r)    return 0;

        if(memo[l][r] != -1)    return memo[l][r];

        int score = 0;
        for(int mid=l;mid<r;mid++) {
            int ls = pref[mid] - ((l-1 >= 0) ? pref[l-1] : 0);
            int rs = pref[r] - ((mid >= 0) ? pref[mid] : 0);

            if(rs > ls) {
                score = max(score,ls+helper(l,mid));
            }
            else if(ls > rs) {
                score = max(score,rs+helper(mid+1,r));
            }
            else {
                score = max({score,ls+helper(l,mid),rs+helper(mid+1,r)});
            }
        }

        return memo[l][r] = score;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.assign(n,0);
        pref[0] = stoneValue[0];
        memo.assign(n+1,vector<int>(n+1,-1));
        for(int i=1;i<n;i++) {
            pref[i] = stoneValue[i]+pref[i-1];
        }

        return helper(0,n-1);
    }
};