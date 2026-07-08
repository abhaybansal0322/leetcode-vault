class Solution {

    int n;

    void backtrack(string& s, vector<string>& result, int start, unordered_set<string>& st, string& currWord) {

        if(start == s.length()) {

            result.push_back(currWord);
            return;
        }

        for(int end = start+1;end <=s.length();end++) {

            string word = s.substr(start, end-start);

            if(st.find(word) != st.end()) {

                string bk = currWord;
                
                if(currWord.length() != 0)  currWord += " ";
                currWord += word;
                backtrack(s,result,end,st,currWord);
                currWord = bk;
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(),wordDict.end());

        n = s.length();

        vector<string> result;
        int start= 0;
        string currWord;

        backtrack(s,result,start,st,currWord);

        return result;


    }
};