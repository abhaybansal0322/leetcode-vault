class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vec(5,0);
        for(auto& ch : text) {

            if(ch == 'b') vec[0]++;
            else if(ch == 'a') vec[1]++;
            else if(ch == 'l') vec[2]++;
            else if(ch == 'o') vec[3]++;
            else if(ch == 'n') vec[4]++; 
        }

        int result = vec[0];

        result = min(result,vec[1]);
        result = min(result,vec[2]/2);
        result = min(result,vec[3]/2);
        result = min(result,vec[4]);

        return result;
    }
};