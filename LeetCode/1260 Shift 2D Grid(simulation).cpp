class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int base = row * col;
        bool vis[2502] = {0};

        k %= base;
        if (k == 0) return grid;

        map<pair<int, int>, int> rowColMap;
        map<int, pair<int, int>> indexMap;

        for(int i = 0, index = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                ++index;
                rowColMap[{i, j}] = index;
                indexMap[index] = {i, j};
            }
        }

        for(int i = 0, index = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int currIndex = rowColMap[{i, j}];
                if (vis[currIndex]) continue;
                int currVal = grid[i][j];
                int nextIndex = (currIndex + k) % base;
                if (nextIndex == 0) nextIndex = base;
                int nextVal = grid[indexMap[nextIndex].first][indexMap[nextIndex].second];
                if (currIndex == nextIndex) continue;

                while(true) {
                    if (vis[currIndex]) break;

                    grid[indexMap[nextIndex].first][indexMap[nextIndex].second] = currVal;
                    vis[currIndex] = true;

                    currIndex = nextIndex;
                    currVal = nextVal;

                    nextIndex = (currIndex + k) % base;
                    if (nextIndex == 0) nextIndex = base;
                    nextVal = grid[indexMap[nextIndex].first][indexMap[nextIndex].second];
                }
            }
        }

        return grid;
    }
};
