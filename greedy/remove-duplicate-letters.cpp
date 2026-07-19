class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> idx(26);
        vector<bool> seen(26,false);
        int n = s.length();

        string ans;

        for(int i=0;i<n;i++) {

            idx[s[i]-'a'] = i;
        }

        for(int i=0;i<n;i++) {

            if(seen[s[i]-'a']) continue;

            while(ans.length() > 0 && ans.back() > s[i] && idx[ans.back()-'a'] > i) {

                seen[ans.back()-'a'] = false;
                // cout<<"POP"<<" "<<ans.back()<<endl;
                ans.pop_back();
            }
            seen[s[i]-'a'] = true;
            ans.push_back(s[i]);
            // cout<<"PUSH"<<" "<<ans.back()<<endl;
        }

        return ans;
    }
};


