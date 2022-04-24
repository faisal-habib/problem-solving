class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int totalLayer = (n + 1) / 2;
        int currValue = 0;

        for(int currLayer = 0; currLayer < totalLayer; currLayer++) {
            // left to right
            for(int col = currLayer; col < n - currLayer; col++) {
                matrix[currLayer][col] = ++currValue;
            }

            // top to bottom
            for(int row = currLayer + 1; row < n - currLayer; row++) {
                matrix[row][n - currLayer - 1] = ++currValue;
            }

            // right to left
            for(int col = n - currLayer - 2; col >= currLayer; col--) {
                matrix[n - currLayer - 1][col] = ++currValue;
            }

            // bottom to top
            for(int row = n - currLayer - 2; row > currLayer; row--) {
                matrix[row][currLayer] = ++currValue;
            }
        }

        return matrix;
    }
};
