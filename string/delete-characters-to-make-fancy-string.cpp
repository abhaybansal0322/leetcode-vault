class Solution {
public:
    string makeFancyString(string s) {

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (i + 1 < s.length() && i + 2 < s.length() && s[i + 1] == ch &&
                s[i + 2] == ch) {
                int cnt = 0;
                int idx = i + 2;
                while (idx < s.length() && s[idx] == ch) {
                    cnt++;
                    idx++;
                }
                s.erase(i, cnt);
            }
        }
        return s;
    }
};