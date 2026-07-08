class Solution {
public:
    string lexSmallestAfterDeletion(string s) {

        vector<int> cnt(26,0);
        for(char c : s) {

            cnt[c-'a']++;
        }

        string res = "";
        vector<int> st(26,0);

        for(char c : s) {

            cnt[c-'a']--;

            while(!res.empty() && res.back()>c) {

                char top = res.back();
                if(st[top-'a']>1 || cnt[top-'a']>0) {

                    res.pop_back();
                    st[top-'a']--;
                } else {
                    break;
                }
            }
            res.push_back(c);
            st[c-'a']++;
        }

        while(!res.empty()) {

            char x = res.back();
            if(st[x-'a']>1) {

                res.pop_back();
                st[x-'a']--;
            } else {
                break;
            }
        }

        return res;
    }
};