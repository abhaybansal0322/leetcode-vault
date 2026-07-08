class Solution {
    vector<vector<int>> result;

    void Solve(int &n,int start,int k,vector<int>& vec) {

        if(k==0) {

            result.push_back(vec);
            return;
        }

        for(int i=start;i<=n;i++) {

            vec.push_back(i);
            Solve(n,i+1,k-1,vec);
            vec.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> vec;
        Solve(n,1,k,vec);

        return result;

    }
};