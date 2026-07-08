class Solution {
public:
    typedef pair<int,int> P;
    typedef long long ll;
    long long numberOfWays(string s) {
        int n=s.length();
        vector<P> left(n);
        vector<P> right(n);

        int c_zero = 0;
        int c_one = 0;
        for(int i=0;i<n;i++)
        {
            left[i]={c_zero,c_one};
            
            if(s[i]=='0')
            {
                c_zero++;
            }
            else{
                c_one++;
            }
        }
        c_zero = 0;
        c_one = 0;
        for(int i=n-1;i>=0;i--)
        {
            right[i]={c_zero,c_one};
            if(s[i]=='0')
            {
                c_zero++;
            }
            else{
                c_one++;
            }
        }
        ll ans = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ans += (ll)left[i].second * right[i].second;
            }
            else{
                ans +=(ll) left[i].first * right[i].first;
            }
        }

        return ans;
    }
};