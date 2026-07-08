class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        map<char, int> m;
        for (char ch : allowed) {
            m[ch]++;
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (m[words[i][j]] < 1) {
                    ans--;
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};