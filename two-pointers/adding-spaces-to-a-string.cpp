class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int i=0;
        long long j=0;
        while(i < s.size())
        {
            if(j<spaces.size() && i==spaces[j])
            {
                result.push_back(' ');
                j++;
            }
            result.push_back(s[i]);
            i++;
        }
        return result;
        
    }
};