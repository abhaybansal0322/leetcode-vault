// //Approach (Khandani Backtracking template and all possible options)
// //T.C : O(1), fixed frid size
// //S.C : O(1), fixed grid size
// class Solution {
// public:

//     bool isValid(vector<vector<char>>& board, int row, int col, char d) {
//         for(int i = 0; i < 9; i++) {
//             if(board[i][col] == d)
//                 return false;
            
//             if(board[row][i] == d) {
//                 return false;
//             }
//         }

//         int start_i = row/3 * 3;
//         int start_j = col/3 * 3;

//         for(int k = 0; k < 3; k++) {
//             for(int l = 0; l < 3; l++) {
//                 if(board[start_i+k][start_j+l] == d) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }

//     //2^9
//     //O(9 ^ 81)
//     bool solve(vector<vector<char>>& board) {
//         for(int i = 0; i < 9; i++) { //O(9)
//             for(int j = 0; j < 9; j++) { //O(9)
//                 if(board[i][j] == '.') {

//                     for(char d = '1'; d <= '9'; d++) { 

//                         if(isValid(board, i, j, d)) {
//                             board[i][j] = d;

//                             if(solve(board) == true) {
//                                 return true;
//                             }

//                             board[i][j] = '.';
//                         }

//                     }

//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
// };

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rowMask(9, 0), colMask(9, 0), boxMask(9, 0);
        vector<pair<int, int>> emptyCells;

        // Step 1: Initialize masks and collect empty cells
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    emptyCells.push_back({r, c});
                } else {
                    int digit = board[r][c] - '1';  // digit index 0-8
                    setMask(rowMask, colMask, boxMask, r, c, digit, true);
                }
            }
        }

        // Step 2: Backtracking
        backtrack(board, rowMask, colMask, boxMask, emptyCells, 0);
    }

private:
    // Convert (row,col) → box index (0–8)
    int getBoxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    // Set or unset a digit in masks
    void setMask(vector<int>& rowMask, vector<int>& colMask, vector<int>& boxMask,
                 int r, int c, int digit, bool set) {
        int bit = 1 << digit;
        if (set) {
            rowMask[r] |= bit;
            colMask[c] |= bit;
            boxMask[getBoxIndex(r, c)] |= bit;
        } else {
            rowMask[r] &= ~bit;
            colMask[c] &= ~bit;
            boxMask[getBoxIndex(r, c)] &= ~bit;
        }
    }

    // Backtracking function
    bool backtrack(vector<vector<char>>& board, vector<int>& rowMask, vector<int>& colMask,
                   vector<int>& boxMask, vector<pair<int, int>>& emptyCells, int idx) {
        if (idx == emptyCells.size()) return true; // All cells filled → solved

        auto [r, c] = emptyCells[idx];
        int boxIdx = getBoxIndex(r, c);

        for (int digit = 0; digit < 9; digit++) {
            int bit = 1 << digit;

            // Skip if digit already used
            if ((rowMask[r] & bit) || (colMask[c] & bit) || (boxMask[boxIdx] & bit)) 
                continue;

            // Place digit
            board[r][c] = '1' + digit;
            setMask(rowMask, colMask, boxMask, r, c, digit, true);

            // Recurse
            if (backtrack(board, rowMask, colMask, boxMask, emptyCells, idx + 1)) 
                return true;

            // Backtrack
            board[r][c] = '.';
            setMask(rowMask, colMask, boxMask, r, c, digit, false);
        }

        return false; // No valid digit → backtrack
    }
};
