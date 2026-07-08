class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        vector<string> words;
        string word;

        while(ss >> word) {

            words.push_back(word);
        }

        string result = "";
        for(int i=words.size()-1;i>=0;i--) {

            result += words[i];

            if(i)   result += " ";

        }

        return result;
    }
};




// class Solution {
// public:
// string reverseWords(string s) {
//     string ans;
//     stack<char> sub;
//     int i=s.length()-1;
//     while(i>=0)
//     {
//         if(s[i]==' ' && s[i+1]!=' ')
//         {
//             while(!sub.empty())
//             {
//                 char ch=sub.top();
//                 ans = ans + ch;
//                 sub.pop();
//             }
//             ans = ans + " " ;
//         }
//         else{
//             if(s[i]!=' ')
//             sub.push(s[i]);
//         }
//         i--;
//     }

//     while(!sub.empty())
//     {
//         char ch=sub.top();
//         ans = ans + ch;
//         sub.pop();
//     }
    
//     int start=0;
//     int end=ans.length()-1;
//     while(ans[start]==' ')
//     {
//         start++;
//     }
//     while(ans[end]==' ')
//     {
//         end--;
//     }

    
//     string final;
//     while(start <= end)
//     {
//         char ch=ans[start];
//         final = final+ch;
//         start++;
//     }
//     return final;
    
// }
// };



