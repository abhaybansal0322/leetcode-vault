class Solution {
public:
    // vector<vector<string>> helper(string formula)
    // {
    //     vector<vector<string>> m;
    //     int i=0;
    //     while(i < formula.length())
    //     {
    //         int value=formula[i];
    //         string element;
    //         string number;
    //         if(value >= 65 && value <= 90)
    //         {
    //             int nextValue = formula[i+1];
    //             element=formula[i];
    //             if(nextValue >= 97 && nextValue <= 122)
    //             {
    //                 element=element + formula[i+1];
    //             }
    //         }
    //         if(value >=48 && value <=57)
    //         {
    //             while(value >=48 && value <=57)
    //             {
    //                 number = number+formula[i];
    //                 i++;
    //             }
    //             m.push_back({element,number});
    //             element="";
    //             number="";
    //         }
    //         if(formula[i]=='(')
    //         {
    //             int cnt=0;
    //             int init = i;
    //             while(i<formula.length())
    //             {
    //                 if(formula[i]=='(')
    //                 {
    //                     cnt++;
    //                 }
    //                 if(formula[i]==')' && cnt!=1)
    //                 {
    //                     cnt--;
    //                 }
    //                 if(formula[i]==')' && cnt==1)
    //                 {
    //                     break;
    //                 }

    //                 i++;
    //             }
    //             string bkt = formula.substr(init,i);
    //             vector<vector<string>> bracket=helper(bkt);
    //             int x=0;
    //             while(x<bkt.length())
    //             {
    //                 m.push_back(bracket[x]);
    //                 x++;
    //             }
    //         }
    //         i++;
    //     }
       
    //     return m;
        
    // }
    
    string countOfAtoms(string formula) {
        int n = formula.length();
        unordered_map<string, int> result_counter;
        stack<unordered_map<string, int>> parenthesis_stack;
        int cur_ind = 0;

        while (cur_ind < n) {
            char cur_char = formula[cur_ind];

            if (cur_char == '(') {
                cur_ind++;
                parenthesis_stack.push(unordered_map<string, int>());
                continue;
            }

            if (cur_char == ')') {
                string mult_str = "";
                cur_ind++;

                while (cur_ind < n && isdigit(formula[cur_ind])) {
                    mult_str += formula[cur_ind];
                    cur_ind++;
                }

                int mult = mult_str.empty() ? 1 : stoi(mult_str);
                unordered_map<string, int> last_counter = parenthesis_stack.top();
                parenthesis_stack.pop();
                unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();
                
                for (const auto& [elem, counter] : last_counter) {
                    target[elem] += counter * mult;
                }
                continue;
            }

            string cur_elem = "";
            string cur_counter_str = "";
            unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();

            while (cur_ind < n && formula[cur_ind] != '(' && formula[cur_ind] != ')') {
                if (isalpha(formula[cur_ind])) {
                    if (isupper(formula[cur_ind]) && !cur_elem.empty()) {
                        target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
                        cur_elem = "";
                        cur_counter_str = "";
                    }
                    cur_elem += formula[cur_ind];
                } else {
                    cur_counter_str += formula[cur_ind];
                }
                cur_ind++;
            }

            target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
        }

        vector<string> parts;
        for (const auto& [elem, counter] : result_counter) {
            parts.push_back(elem + (counter == 1 ? "" : to_string(counter)));
        }
        sort(parts.begin(), parts.end());

        string result;
        for (const auto& part : parts) {
            result += part;
        }

        return result;
    }
};