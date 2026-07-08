class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto str : words)
        {
            size_t pos = str.find(pref);
            if(pos == 0){
                count++;
            }
        }

        return count;
        
    }
};