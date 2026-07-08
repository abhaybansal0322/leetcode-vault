class Solution {
public:
    int minSteps(string s, string t) {

        vector<int> arr(26,0);
        int res = 0;

        for(int i=0;i<s.length();i++) {

            arr[s[i]-'a']++;
        }

        for(int j=0;j<t.length();j++) {

            if(arr[t[j]-'a'] == 0)  res++;

            else    arr[t[j]-'a']--;

        }

        return res;
        
    }
};