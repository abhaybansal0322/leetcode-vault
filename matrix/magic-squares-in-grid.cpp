class Solution {
public:

//     bool isMagic(int i, int j, vector<vector<int>>& grid) {
    
//     if (i <= 0 || j <= 0 || i >= grid.size() - 1 || j >= grid[0].size() - 1)
//         return false;


//     int sum = grid[i][j] + grid[i-1][j-1] + grid[i+1][j+1];


//     if (grid[i-1][j-1] + grid[i+1][j+1] != sum || grid[i-1][j+1] + grid[i+1][j-1] != sum)
//         return false;

    
//     if (grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] != sum ||
//         grid[i][j-1] + grid[i][j] + grid[i][j+1] != sum ||
//         grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1] != sum)
//         return false;

    
//     if (grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1] != sum ||
//         grid[i-1][j] + grid[i][j] + grid[i+1][j] != sum ||
//         grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1] != sum)
//         return false;

    
//     vector<int> values = {
//         grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1],
//         grid[i][j-1], grid[i][j], grid[i][j+1],
//         grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]
//     };

//     sort(values.begin(), values.end());
//     for (int k = 0; k < 9; k++) {
//         if (values[k] != k + 1)
//             return false;
//     }

//     return true;
// }

// int numMagicSquaresInside(vector<vector<int>>& grid) {
//     int rows = grid.size();
//     int cols = grid[0].size();
//     int count = 0;

//     for (int i = 1; i < rows - 1; i++) {
//         for (int j = 1; j < cols - 1; j++) {
//             if (grid[i][j] == 5 && isMagic(i, j, grid)) {
//                 count++;
//             }
//         }
//     }

//     return count;
// }
bool isMagic(int i, int j, vector<vector<int>>& grid) {
    // Extract the 3x3 grid centered at (i, j)
    vector<int> values = {
        grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1],
        grid[i][j-1], grid[i][j], grid[i][j+1],
        grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]
    };
    
    // Check if all values are distinct and in the range 1-9
    sort(values.begin(), values.end());
    for (int k = 0; k < 9; k++) {
        if (values[k] != k + 1)
            return false;
    }
    
    // Check the sums of rows, columns, and diagonals
    int sum1 = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1];  // top row
    int sum2 = grid[i][j-1] + grid[i][j] + grid[i][j+1];        // middle row
    int sum3 = grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];  // bottom row
    int sum4 = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1];  // left column
    int sum5 = grid[i-1][j] + grid[i][j] + grid[i+1][j];        // middle column
    int sum6 = grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];  // right column
    int sum7 = grid[i-1][j-1] + grid[i][j] + grid[i+1][j+1];    // main diagonal
    int sum8 = grid[i-1][j+1] + grid[i][j] + grid[i+1][j-1];    // anti-diagonal

    // All sums must be equal to 15
    return (sum1 == 15 && sum2 == 15 && sum3 == 15 &&
            sum4 == 15 && sum5 == 15 && sum6 == 15 &&
            sum7 == 15 && sum8 == 15);
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Start checking from index 1 and end at index rows-2 or cols-2
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (grid[i][j] == 5 && isMagic(i, j, grid)) {
                count++;
            }
        }
    }

    return count;
}


};