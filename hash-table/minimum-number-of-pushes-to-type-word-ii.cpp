class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> m;
        vector<vector<int>> v;
        for(int i=0;i<word.size();i++)
        {
            m[word[i]]++;
        }
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.rbegin(), v.rend());
        int key=2;
        int mul=1;
        int cnt=0;
        int ans=0;
       
        for(int i=0;i<v.size();i++)
        {
            if(key > 9)
            {
                key=2;
                mul++;
            }
            ans=ans+v[i][0]*mul;
            key++;
        }  
        return ans;

    }
};