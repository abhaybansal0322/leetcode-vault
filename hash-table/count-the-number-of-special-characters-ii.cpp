class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.length();
        vector<int> firstUpper(26,-1);
        vector<int> lastLower(26,-1);

        for(int i=0;i<n;i++) {
            char ch = word[i];
            if(islower(ch)) lastLower[ch-'a'] = i;
            else {
                if(firstUpper[ch-'A'] == -1) {
                    firstUpper[ch-'A'] = i;
                }
            }
        }

        int ans = 0;
        for(char ch = 'a';ch<='z';ch++) {

            if(firstUpper[ch-'a']!=-1 && lastLower[ch-'a']!=-1) {
                if(lastLower[ch-'a'] < firstUpper[ch-'a']) ans++;
            }
        }

        return ans;
    }
};