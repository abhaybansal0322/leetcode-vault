class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();
        map<int,int> mA;
        map<int,int> mB;
        int num=0;

        for(int i=0;i<n;i++)
        {
            mA[A[i]]++;
            mB[B[i]]++;

            if(A[i]==B[i])
            {
                num++;
            }
            else{
                if(mA[B[i]]>0)
                {
                    num++;
                }
                if(mB[A[i]]>0)
                {
                    num++;
                }
            }

            ans.push_back(num);
        }
        
        return ans;
    }
};