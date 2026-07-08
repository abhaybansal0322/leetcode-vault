class Solution {
public:
    int minSwaps(string s) {
        int numOpen = 0;
        int numClose = 0;
        int i = 0;
        int j = s.length() - 1;
        int ans = 0;

        while (i < s.length() && j > 0 && i < j) {
            if (s[i] == '[') {
                numOpen++;
            }
            if (s[i] == ']') {
                numClose++;
            }

            if (numClose > numOpen) {
                while (j > i && j > 0 && s[j] != '[') {
                    j--;
                }
                // s[i] = '[';
                // s[j] = ']';
                numOpen++;
                numClose--;
                ans++;
            }
            i++;
        }
        return ans;
    }
};