class Solution {
public:
    bool isPalindromic(string s) {
        string s1;
        for(auto& ch : s) {
            int ascii = (int)(ch);
            string bin = bitset<8>(ascii).to_string();
            s1 += bin;
        }

        int i = 0;
        int j = s1.length()-1;

        while(i<j) {
            if(s1[i]!=s1[j])    return false;
            i++;
            j--;
        }

        return true;
    }
};