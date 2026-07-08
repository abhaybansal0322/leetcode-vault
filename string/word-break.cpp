class Solution {

    unordered_map<string,bool> mp;

    bool helper(string s, unordered_set<string>& st) {

        if(st.find(s) != st.end())  return mp[s] = true;

        if(mp.find(s) != mp.end())  return mp[s];
        
        int n = s.length();
        if(s.length() <= 0) {

            return false;
        }

        for(int i=0;i<n;i++) {

            string word = s.substr(0,i);

            if(st.find(word) != st.end()) {

                if(helper(s.substr(i),st)) {

                    return mp[s] = true;
                }
            }
        }   

        return mp[s] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(),wordDict.end());

        return helper(s,st);
    }
};