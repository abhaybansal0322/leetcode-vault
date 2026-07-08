class Solution {
public:
    string removeStars(string s) {
    string res = "";
    for(char ch : s) {
        if(ch == '*' && !res.empty()) {
            // Remove the last character from the result if a star is found. 
            res.pop_back();
        } else {
            // Append the current character to the result.
            res += ch;
        }
    }
    return res;
}

};