class Solution {

    string revString(string s) {
        
        reverse(s.begin(), s.end());
        return s;
    }
public:
    string processStr(string s) {
        
        int n = s.length();
        string result = "";

        for(int i=0;i<n;i++) {

            if(s[i] == '*') {

                if(result.length() != 0)
                    result.pop_back();

            } else if(s[i] == '#') {

                result += result;

            } else if(s[i] == '%') {

                result = revString(result);
            }
            else {

                result += s[i];
            }

            cout<<result<<endl;
        }

        return result;
    }
};