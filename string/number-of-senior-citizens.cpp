class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        int i=0;
        while(i<details.size())
        {
            string pass=details[i];
            if(pass[11]=='7'||pass[11]=='8'||pass[11]=='9')
            {
                count++;
            }
            else{
                if(pass[11]=='6' && pass[12]!='0')
                {
                    count++;
                }
            }
            i++; 
        }
        return count;
        
    }
};