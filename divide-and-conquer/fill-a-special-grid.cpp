class Solution {
    void fillGrid(vector<vector<int>>& grid, int N, int rowStart, int colStart, int size, int& num) {
    if (size == 1) {
        grid[rowStart][colStart] = num++;
        return;
    }

    int newSize = size / 2;

    fillGrid(grid, N, rowStart, colStart + newSize, newSize, num);          // TR
    fillGrid(grid, N, rowStart + newSize, colStart + newSize, newSize, num); // BR
    fillGrid(grid, N, rowStart + newSize, colStart, newSize, num);           // BL
    fillGrid(grid, N, rowStart, colStart, newSize, num);                      // TL
}
public:
    vector<vector<int>> specialGrid(int N) {
        int size = pow(2, N);
        vector<vector<int>> grid(size, vector<int>(size));
        int num = 0;
        fillGrid(grid, N, 0, 0, size, num);
        return grid;  
    }
};