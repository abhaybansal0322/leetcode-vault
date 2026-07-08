class Solution {
    // Helper function to move the matching character towards position j
    int moveToMatch(vector<char>& s, int i, int j) {
        int k = j;

        // Find the matching character for s[i] starting from j and moving backwards
        while (k > i && s[k] != s[i]) {
            k--;
        }

        if (k == i) {
            // No match found; need to swap s[i] with its next neighbor
            swap(s[i], s[i + 1]);
            return 1; // One move to swap the lonely middle character
        } else {
            // Move matching character to position j
            for (int l = k; l < j; l++) {
                swap(s[l], s[l + 1]);
            }
            return j - k; // Number of swaps done
        }
    }

public:
    int minMovesToMakePalindrome(string str) {
        int steps = 0;
        int i = 0, j = str.size() - 1;

        // Convert string to vector<char> for easier swapping
        vector<char> s(str.begin(), str.end());

        while (i < j) {
            if (s[i] == s[j]) {
                // Characters match, move inward
                i++;
                j--;
            } else {
                // Use helper to move the matching character into place
                steps += moveToMatch(s, i, j);
            }
        }

        return steps;
    }
};
