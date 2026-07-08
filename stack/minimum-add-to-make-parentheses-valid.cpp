class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> openB;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openB.push(s[i]);
            }
            else{
                if(openB.empty()){
                    ans++;
                }
                else{
                    openB.pop();
                }
            }
        }

        while(!openB.empty()){
            openB.pop();
            ans++;
        }

        return ans;
    }
};