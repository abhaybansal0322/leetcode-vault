class Solution {

    bool helper(int mid,vector<int>& piles,int h)
    {
        long long int curr = 0; 
        for(int &pile : piles){
            
            curr = curr + (pile+mid-1)/mid;
        }
        
        return curr <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = 0;

        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(helper(mid,piles,h))
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