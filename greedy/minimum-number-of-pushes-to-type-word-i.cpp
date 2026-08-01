class Solution {
public:
    int minimumPushes(string word) {

        vector<int> letters(26,0);
        for(auto ch : word) {
            letters[ch-'a']++;
        }   

        sort(letters.rbegin(), letters.rend());

        int res = 0;
        for(int i=0;i<26;i++) {

            int freq = letters[i];
            int press = i/8 + 1;

            res += freq*press;
        }

        return res;
    }
};