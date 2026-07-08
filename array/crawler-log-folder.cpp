class Solution {
public:
    int minOperations(vector<string>& logs) {
        int i=0;
        int count=0;
        while(i<logs.size())
        {
            if(logs[i]=="../" && count!=0)
            {
                count--;
            }
            else if(logs[i]!="../" && logs[i]!="./")
            {
                count++;
            }
            i++;

            
        }
        return count;
        
    }
};