class Solution {
    string makePal(vector<int>& charCount)
    {
        string half="";
        for(int i=0;i<26;++i)
            {
                if(charCount[i]==0)
                    continue;

                char ch = (char) i+'a';
                while(charCount[i])
                    {
                        half += ch;
                        charCount[i]=charCount[i]-2;
                    }
            }

        string result = half;
        reverse(half.begin(),half.end());
        result += half;
        return result;
    }
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> charCount(26,0);
        for(int i=0;i<n;++i)
            {
                charCount[s[i]-'a']++;
            }
        
        if(n%2==0)
        {
            return makePal(charCount);
        }
        char ch;
        int idx = -1;
        for(int j=0;j<26;++j)
            {
                if(charCount[j]%2==1)
                {
                    ch = j+'a';
                    idx = j;
                }
            }

        charCount[idx]--;
        string result = makePal(charCount);
        int mid = result.size()/2;
        result.insert(result.begin()+mid,ch);
        return result;
    }
};