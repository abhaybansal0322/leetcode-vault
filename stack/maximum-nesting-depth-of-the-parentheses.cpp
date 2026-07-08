class Solution {
public:
    int maxDepth(string s) {
        
        int res = 0;
        int curr = 0;
        for(auto& ch : s) {

            if(ch == '(') {

                curr++;
            }
            else if(ch == ')') {

                curr--;
            }

            res = max(res,curr);
        }

        return res;
    }
};