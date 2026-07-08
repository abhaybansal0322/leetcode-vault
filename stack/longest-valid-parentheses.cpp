class Solution {
public:
    int longestValidParentheses(string s) {
        
        int l = 0;
        int r = 0;
        int ans = 0;

        for(auto& ch : s) {

            if(ch == '(') {

                l++;
            }

            else if(ch == ')') {

                r++;
            }

            if(l == r) {

                ans  = max (ans, 2*l);
            }
            else if(r > l) {

                l=0;
                r=0;
            }
        }

        l=0,r=0;
        for(int i=s.length()-1;i>=0;i--) {

            if(s[i] == '(') {

                l++;
            }

            else if(s[i] == ')') {

                r++;
            }

            if(l == r) {

                ans  = max (ans, 2*l);
            }
            else if(l > r) {

                l=0;
                r=0;
            }

        }

        return ans;
    }
};