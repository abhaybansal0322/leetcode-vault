class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) {
            return false;
        }

        unordered_map<char, int> m;

        for (auto c : s) {
            m[c]++;
        }

        int count = 0;

        for (auto i : m) {
            if ((i.second & 1) == 1) {
                count++;
            }
        }

        if (count > k) {
            return false;
        }

        return true;
    }
};