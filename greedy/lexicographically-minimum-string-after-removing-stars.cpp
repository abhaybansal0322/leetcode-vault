class Solution {
    struct CustomCompare{
        bool operator()(const pair<char,int> &a,const pair<char,int> &b){
            if(a.first==b.first)
            {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, CustomCompare> minHeap;

        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                if(!minHeap.empty())
                {
                    auto val = minHeap.top();
                    minHeap.pop();
                    int it = val.second;
                    s[it]='*';
                }
            }
            else{
                minHeap.push({s[i],i});
            }
        }

        string res;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
                res.push_back(s[i]);
        }
        
        return res;
    }
};