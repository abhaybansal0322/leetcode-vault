class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        set<string> s(folder.begin(), folder.end());
        vector<string> result;

        for (auto& currFolder : folder) {
            string temp = currFolder;
            bool toAdd = true;
            while (!currFolder.empty()) {
                int idx = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0, idx);

                if (s.find(currFolder) != s.end()) {
                    toAdd = false;
                    break;
                }
            }

            if (toAdd) {
                result.push_back(temp);
            }
        }

        return result;
    }
};