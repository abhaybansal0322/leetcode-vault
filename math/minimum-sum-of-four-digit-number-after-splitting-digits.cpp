class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while(num >0)
        {
            int last=num%10;
            num=num/10;
            v.push_back(last);
        }
        sort(v.begin(),v.end());
    
        return (v[0]*10)+v[3]+(v[1]*10)+v[2];

        
    }
};