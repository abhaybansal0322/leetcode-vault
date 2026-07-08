class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> subWords;
        int n = word.length();

        for(int i=0;i<n;i++) {

            for(int j=i;j<n;j++) {

                subWords.insert(word.substr(i,j-i+1));
            }
        }

        int res = 0;
        for(auto& s : patterns) {

            if(subWords.find(s) != subWords.end()) res++;
        }

        return res;
    }
};