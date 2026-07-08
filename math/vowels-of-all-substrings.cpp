class Solution {
    // typedef long long long long;

public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.length();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; ++i) {
            if (vowels.count(word[i]))
                ans += (long long)(i + 1) * (n - i);
        }
        return ans;
    }
};