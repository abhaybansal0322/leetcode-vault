class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int i=citations.size()-1;
        int res=0;
        while(i>=0)
        {
            if(citations[i]>=res+1)
            {
                res++;
            } 
            i--;
        }
        return res;
        
    }
};