class Solution {
public:
    typedef long long ll;

    bool isPossible(ll mid,vector<int>& ranks,int cars)
    {
        ll carsUsed = 0;
        for(int i=0;i<ranks.size();i++)
        {
            carsUsed += sqrt(mid/ranks[i]);
        }

        return (carsUsed>=cars);
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll l = 1;
        ll maxR = *max_element(ranks.begin(),ranks.end());
        ll r = maxR * cars * cars;
        ll result = -1;

        while(l <= r)
        {
            ll mid = l + (r-l)/2;
            if(isPossible(mid,ranks,cars))
            {
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result;   
    }
};