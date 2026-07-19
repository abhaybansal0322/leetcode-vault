class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        int xc = 0,xy = 0;
        string t;
        for(auto& ch : s) {

            if(ch == y) {

                t = ch + t;
            }
            else {

                t = t + ch;
            }
        }

        return t;    
    }
};