class Solution {
    void solve(int curr,int n,vector<int>& result)
    {
        if(curr > n)
            return;
        
        result.push_back(curr);
        for(int append=0;append<=9;append++)
        {
            int NewNum = curr*10 + append;

            if(NewNum > n)
                return;

            solve(NewNum,n,result);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int start=1;start<=9;start++)
        {
            solve(start,n,result);
        }

        return result;    
    }
};