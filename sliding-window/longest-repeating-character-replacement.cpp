class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> vec(26);
        for(int i=0;i<n;i++) {

            char ch = s[i];
            vec[ch-'A'].push_back(i);
        }

        int ans = 0;
        for(auto& V : vec) {

            int m = V.size();
            int i = 0, j = 0;
            while(j < m) {

                while(i<m && (V[j] - V[i]) - (j-i) > k) {
                    i++;
                }
                ans = max(ans,min(n, (j - i + 1) + k));
                j++;
            }
        }

        return ans;
    }
};