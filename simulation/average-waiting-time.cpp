class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum=0;
        int i=0;
        int nS=0;
        while(i<customers.size())
        {
            int wT = 0;
            if(nS < customers[i][0])
            {
                wT=customers[i][1];
                nS=customers[i][0]+customers[i][1];
            }
            else{
                wT=nS-customers[i][0]+customers[i][1];
                nS=nS+customers[i][1];
            }
            sum=sum+wT;
            i++;
        }
        double ans =sum/customers.size();
        return ans;

    }
};