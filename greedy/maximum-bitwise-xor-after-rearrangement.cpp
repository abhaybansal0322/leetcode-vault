class Solution {
public:
    string maximumXor(string s, string t) {
        
        int cnt0 = 0;
        int cnt1 = 0;

        for(auto ch : t) {

            if(ch == '0') cnt0++;
            if(ch == '1') cnt1++;
        }

        string res="";

        for(auto ch : s) {

            if(ch == '0') {

                if(cnt1 > 0) {

                    res.push_back('1');
                    cnt1--;
                } else {
                    res.push_back('0');
                }
            }

            if(ch == '1') {

                if(cnt0 > 0) {

                    res.push_back('1');
                    cnt0--;
                } else {
                    res.push_back('0');
                }
            }

        }

        return res;
    }
};