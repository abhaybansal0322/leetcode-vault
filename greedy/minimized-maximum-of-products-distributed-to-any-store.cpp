class Solution {

    int helper(int idx,vector<int>& q,int n)
    {
        for(int &p : q)
        {
            n -= (p+idx-1)/idx;
        }
        if(n<0)
        {
            return false;
        }

        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l =1;
        int r = *max_element(q.begin(),q.end());
        int res = 0;

        while(l <= r)
        {
            int mid = l+(r-l)/2;

            if(helper(mid,q,n))
            {
                res = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return res;
    }
};