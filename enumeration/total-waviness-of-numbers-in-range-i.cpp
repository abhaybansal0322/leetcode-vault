class Solution {
public:
    int totalWaviness(int num1, int num2) {

        
        int result = 0;

        for(int i=num1; i<=num2; i++) {

            string num = to_string(i);
            if(num.length() < 3) continue;
            for(int j = 1;j<num.length()-1;j++) {

                if((num[j]-'0' > num[j-1]-'0' &&
                    num[j]-'0' > num[j+1]-'0') ||
                    (num[j]-'0' < num[j-1]-'0' &&
                    num[j]-'0' < num[j+1]-'0')
                )
                    result++;
            }
        }

        return result;
    }
};