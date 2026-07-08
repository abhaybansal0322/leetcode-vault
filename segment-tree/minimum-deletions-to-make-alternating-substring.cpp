class Solution {

    vector<int> b;
    int n;

    void update(int i,int val) {

        for(;i<=n;i += i & -i) {

            b[i] += val;
        }
    }

    int query(int i) {

        int sum = 0;
        for(;i>0;i -= i&-i) {

            sum+=b[i];
        }
        return sum;
    }
    
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        n = s.length();
        b.assign(n+1,0);
        vector<int> adj(n,0);

        for(int i=0;i<n-1;i++) {

            if(s[i] == s[i+1]) {

                adj[i] = 1;
                update(i+1,1);
            }
        }

        vector<int> res;
        res.reserve(queries.size());
       
        for(auto& q : queries) {

            if(q[0] == 1) {

                int i = q[1];
                s[i] = (s[i] == 'A') ? 'B' : 'A';

                if(i > 0) {

                    int j = i-1;
                    int old = adj[j];
                    int New = (s[j]==s[j+1]) ? 1 : 0;

                    if(old != New) {

                        update(j+1,New-old);
                        adj[j] = New;
                    }  
                }

                if(i < n-1) {

                    int j = i;
                    int old = adj[j];
                    int New = (s[j]==s[j+1]) ? 1 : 0;

                    if(old != New) {

                        update(j+1,New-old);
                        adj[j] = New;
                    }  
                }
            }
            else {

                int l = q[1];
                int r = q[2];

                if(l >=r) res.push_back(0);
                else res.push_back(query(r)-query(l));
            }
        }
        return res;
    }
};