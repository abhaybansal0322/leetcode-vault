class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0; 
        for(char ch = 'a';ch<='z';ch++) {

            if(s.count(ch) && s.count(ch-'a' + 'A')) ans++;
        }

        return ans;
    }
};