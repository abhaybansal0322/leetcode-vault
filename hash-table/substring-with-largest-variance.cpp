class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26,0);
        int res = 0;

        for(char &ch : s)
        {
            count[ch-'a']=1;
        }

        for(char first='a';first<='z';first++)
        {
            for(char second='a';second<='z';second++)
            {
                if(count[first-'a']==0 || count[second-'a']==0)
                {
                    continue;
                }
                
                int Fcnt = 0;
                int Scnt = 0;
                bool pastS = false;

                for(char &ch : s)
                {
                    if(ch==first)
                    {
                        Fcnt++;
                    }
                    if(ch==second)
                    {
                        Scnt++;
                    }

                    if(Scnt > 0 )
                    {
                        res = max(res,Fcnt-Scnt);
                    }
                    else{
                        if(pastS)
                        {
                            res = max(res,Fcnt-1);
                        }
                    }

                    if(Scnt > Fcnt)
                    {
                        Fcnt = 0;
                        Scnt = 0;
                        pastS = true;
                    }

                }
            }

        }

        return res;
    }
};