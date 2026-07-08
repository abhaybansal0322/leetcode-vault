class Solution {
public:
    string largestEven(string s) {

        int n = s.length()-1;

        for(int i=n;i>=0;i--) {

            if(s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') {

                s.erase(s.begin()+i);
            }
            else {

                return s;
            }
        }

        return s;
    }
};