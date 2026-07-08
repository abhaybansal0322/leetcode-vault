class Solution {
    struct Node {
        int freq;
        int first;
        char ch;
    };

    bool isVowel(char ch) {
        return string("aeiou").find(ch) != string :: npos;
    }
public:
    string sortVowels(string s) {
        
        int n = s.length();
        vector<Node> vec;
        unordered_map<char,pair<int,int>> mp; // char ---> freq,first
        for(int i=0;i<n;i++) {
            char ch = s[i];
            if(isVowel(ch)) {
                mp[ch].first++;
                if(mp[ch].first == 1) mp[ch].second = i;
            }
        }

        for(auto& M : mp) {
            int freq = M.second.first;
            int first = M.second.second;
            char ch = M.first;

            vec.push_back({freq,first,ch});
        }

        sort(vec.begin(),vec.end(),[&](Node a, Node b) {

            if(a.freq == b.freq) {

                return a.first < b.first;
            }
            return a.freq > b.freq;
        });

        int j = 0;
        for(int i=0;i<n;i++) {
            char ch = s[i];
            if(isVowel(ch)) {
                s[i] = vec[j].ch;
                vec[j].freq--;
                if(vec[j].freq == 0) j++;
            }
        }

        return s;
    }
};