class Solution {
public:
    int vowelConsonantScore(string s) {

        int n = s.length();
        int c = 0;
        int v = 0;

        for(char ch : s) {

            if(isalpha(ch)) {

                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') v++;
                else c++;
            }
        }

        if(c == 0) return 0;

        int score = floor(v/c);

        return score;
    }
};