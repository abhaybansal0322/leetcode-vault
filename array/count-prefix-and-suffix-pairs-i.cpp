class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n= words.size();
        for(int i=0;i<n;i++)
        {
            string word1 = words[i];
            for(int j=i+1;j<n;j++)
            {
                string word2 = words[j];

                if(word1.size() > word2.size())
                {
                    continue;
                }

                bool isPrefix = word2.substr(0, word1.size()) == word1;
                bool isSuffix = word2.substr(word2.size() - word1.size(),word1.size()) == word1;

                if (isPrefix && isSuffix) {
                    count++;
                }
            }
        }

        return count;
        
    }
};