class Solution {
    vector<string> result;

    void Solve(int idx,string digits,string temp,unordered_map<char, string>& mp) {

        if(idx==digits.length()) {

            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string s = mp[ch];

        for(int i=0;i<s.length();i++) {

            temp.push_back(s[i]);
            Solve(idx+1,digits,temp,mp);
            temp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        
        mp['2'] =  "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        
        Solve(0, digits, temp, mp);
        
        return result;
    }
};