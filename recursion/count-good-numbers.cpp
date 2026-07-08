class Solution {
    const int M = 1e9+7;
    typedef long long ll;

    int findPow(ll a , ll b)
    {
        if(b==0)
        {
            return 1;
        }
        ll half = findPow(a,b/2) % M;
        ll res = (half*half) % M;

        if(b%2==1)
        {
            res = (res*a) % M;
        }

        return res; 
    }
public:
    int countGoodNumbers(long long n) {

        return (ll) findPow(5,(n+1)/2) * findPow(4,n/2) % M;

    }
};