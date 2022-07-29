class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};


// class Solution {
// public:

//     int floorMod(int x, int y) {
//         return ((x % y) + y) % y;
//     }

//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> result (n, vector<int>(n));
//         int cnt = 1;
//         int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//        int d = 0;
//         int row = 0;
//         int col = 0;
//         while (cnt <= n * n) {
//             result[row][col] = cnt++;
//             int r = floorMod(row + dir[d][0], n);
//             int c = floorMod(col + dir[d][1], n);
//             // change direction if next cell is non zero
//             if (result[r][c] != 0) d = (d + 1) % 4;
//             row += dir[d][0];
//             col += dir[d][1];
//         }
//         return result;
//     }
// };