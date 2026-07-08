class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ans;
        int i=0;
        while(i<magazine.size())
        {
            ans[magazine[i]]++;
            i++;
        }
        int j=0;
        while(j<ransomNote.size())
        {
            if(ans[ransomNote[j]] > 0)
            {
                ans[ransomNote[j]]--;
            }
            else{
                return false;
            }
            j++;
        }
        return true;
        
    }
};