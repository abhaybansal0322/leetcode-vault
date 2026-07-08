class Solution {

    bool isVowel(char ch) {

        return ((ch == 'a') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'e'));
    }
public:
    string trimTrailingVowels(string s) {
        int n = s.length();
        int x = n;
        for(int i=n-1;i>=0;i--) {
            
            if(isVowel(s[i])) x--;
            else break;
        }

        return s.substr(0,x);
    }
};