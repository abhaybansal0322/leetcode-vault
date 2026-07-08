class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.length();
        int i = 0;
        while (i < n) {
            int cnt = 0;
            char ch = word[i];
            while (i < n && cnt < 9 && word[i] == ch) {
                i++;
                cnt++;
            }
            comp.push_back(cnt + '0');
            comp.push_back(ch);
        }

        return comp;
    }
};