class Solution {

    bool isVowel(char ch) {

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string reverseWords(string s) {

        int n =s.length();
        int i=0;
        int target = 0;

        while(i<n && s[i]!=' ') {

            if(isVowel(s[i])) target++;

            i++;
        }
        i++;

        while(i<n) {

            int st = i;
            int curr = 0;

            while(i<n && s[i]!=' ') {

                if(isVowel(s[i])) curr++;
    
                i++;
            }

            if(curr == target) {

                reverse(s.begin()+st, s.begin()+i);
            }

            i++; 
        }

        return s;
    }
};