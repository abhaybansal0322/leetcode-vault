class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        set<char> vowels = {'a','e','i','o','u'};
        int ans = 0;

        for(int i=0;i<n;++i)
        {
            if(vowels.count(word[i])==0)
                continue;
            set<char> curr;
            for(int j=i;j<n;++j)
            {
                if(vowels.count(word[j])==0)
                    break;
                curr.insert(word[j]);
                if(curr.size() >=5)
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};