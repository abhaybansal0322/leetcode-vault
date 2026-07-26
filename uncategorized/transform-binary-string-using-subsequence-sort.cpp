class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        int ones = count(s.begin(),s.end(),'1');

        vector<bool> ans;
        ans.reserve(strs.size());

        for(auto& p : strs) {

            int q = count(p.begin(),p.end(),'1');
            int r = count(p.begin(),p.end(),'?');

            int rem = ones - q;
            if(rem < 0 || rem > r) {
                ans.push_back(false);
                continue;
            }

            int bal = 0;
            bool Ok = true;
            int zeroLeft = r - rem;;
            for(int i=0;i<n;i++) {

                bal += (s[i] == '1');
                char c = p[i];
                if (c == '?') c = (zeroLeft-- > 0) ? '0' : '1';
                bal -= (c == '1');
                if (bal < 0) { Ok = false; break; }
            }
            ans.push_back(Ok);
        }
        return ans;
    }
};