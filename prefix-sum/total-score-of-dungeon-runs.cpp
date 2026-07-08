using ll = long long;
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    template <typename T>
    using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
    public:
    
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {

        int n = damage.size();
        vector<int> pre(n);
        pre[0] = damage[0];

        for(int i=1;i<n;i++)    pre[i] = damage[i]+pre[i-1];

        ll ans=0;
        ordered_multiset<ll> st;

        for(int i=n-1;i>=0;i--) {

            st.insert((ll)hp - pre[i] - requirement[i]);
            ll v = (i>0) ? -pre[i-1] : 0;

            ans += ((ll)st.size() - st.order_of_key(v));
        }

        return ans; 
    }
};