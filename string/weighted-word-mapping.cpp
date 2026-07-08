class Solution {
    char getChar(int x) {
        int n = 26-x;
        return ('a'+ n-1);
    }
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string res = "";
        for(auto& word : words) {
            int curr = 0;
            for(char ch : word) {
                curr += weights[ch - 'a'];
            }

            res += (getChar(curr%26));
        }

        return res;
    }
};