class Solution {
public:
    string generateTag(string caption) {
        int n = caption.size();

        string ans = "#";

        for(int i=0;i<n;i++)
        {
            if(caption[i]==' ')
                continue;
            
            if(i > 0 && caption[i-1]==' ')
            {
                caption[i]=toupper(caption[i]);
            }
            else if(isupper(caption[i])){
                caption[i]=tolower(caption[i]);
            }

            ans.push_back(caption[i]);
        }

        ans[1]=tolower(ans[1]);

        return ans.substr(0,100);
    }
};