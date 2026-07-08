class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> bank(wordList.begin(),wordList.end());
        unordered_set<string> vis;
        int steps = 0;

        if(bank.find(endWord) == bank.end())    return 0;

        queue<string> Q;
        Q.push(beginWord);
        vis.insert(beginWord);

        while(!Q.empty()) {

            int N = Q.size();

            while(N--) {

                string curr = Q.front(); Q.pop();

                if(curr == endWord) return steps+1;

                for(int i=0;i<26;i++) {

                    char ch = 'a' + i;

                    for(int j=0;j<curr.length();j++) {

                        string W = curr;
                        W[j] = ch;

                        if(bank.find(W)!=bank.end() && vis.find(W)==vis.end()) {

                            Q.push(W);
                            vis.insert(W);
                        }

                    }
                }
            }
            steps++;
        }

        return 0;

    }
};