class Solution {
    // bool check(int i,int n,vector<bool>& vis)
    // {
    //     if(i>=n || i < 0 || vis[i])
    //         return false;

    //     return true;
        
    // }
public:
    long long calculateScore(vector<string>& ins, vector<int>& values) {
        long long n = ins.size();
        vector<bool> vis(n,false);
        long long i = 0;
        long long ans = 0;

        while(i<n && i >= 0)
            {
                if(vis[i])
                {
                    break;
                }
                
                if(ins[i]=="add")
                {
                    ans += values[i];
                    vis[i]=true;
                    i++;
                }
                else{
                    vis[i]=true;
                    i = i + values[i];
                }
            }

        return ans;
    }
};