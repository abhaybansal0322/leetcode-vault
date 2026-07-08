class Solution {

    typedef long long ll;

    ll helper(vector<int>& time,ll mid) {

        ll Sum = 0;
        for(int &t : time) {

            Sum += (mid / (ll) t);
        }

        return Sum;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        ll l = 1;
        ll r = 1e14;
        ll Ans;

        while(l <= r) {

            ll mid = l + (r-l)/2;
            if(helper(time,mid) >= totalTrips) {

                r = mid-1;
                Ans = mid;
            }
            else {
                
                l = mid+1;
            }
        }

        return Ans;
        
    }
};