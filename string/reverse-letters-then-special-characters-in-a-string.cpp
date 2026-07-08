class Solution {
public:
    string reverseByType(string s) {

        vector<char> letters,special;
        for(char c: s) {

            if(c >= 'a' && c <= 'z') letters.push_back(c);
            else special.push_back(c);
        }

        reverse(letters.begin(),letters.end());
        reverse(special.begin(),special.end());

        int i = 0;
        int j = 0;

        for(char& c : s) {

            if(c >= 'a' && c<= 'z') c = letters[i++];
            else c = special[j++];
        }

        return s;
    }
};