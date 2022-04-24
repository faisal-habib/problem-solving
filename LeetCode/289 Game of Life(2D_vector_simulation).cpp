class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int totalRow = board.size();
        int totalColumn = board[0].size();
        vector<vector<int>> tempOutput(totalRow + 1, vector<int>(totalColumn + 1));
        ///8 direction
        int dir_x[8]={-1,-1,-1,1,1,1,0,0};
        int dir_y[8]={0,-1,1,0,-1,1,-1,1};

        for(int i = 0; i < totalRow; i++) {
            for(int j = 0; j < totalColumn; j++) {
                tempOutput[i][j] = board[i][j];
                int liveCellCount = 0;
                int deadCellCount = 0;
                for(int d = 0; d < 8; d++) {
                    int ii = i + dir_x[d];
                    int jj = j + dir_y[d];

                    if (ii < 0 || ii >= totalRow || jj < 0 || jj >= totalColumn) continue;

                    if (board[ii][jj]) liveCellCount++;
                    else deadCellCount++;
                }

                if (board[i][j]) {
                    // current cell is a live cell
                    if (liveCellCount < 2) {
                        // 1. Any live cell with fewer than two live neighbors dies
                        tempOutput[i][j] = 0;
                    }
                    else if (liveCellCount == 2 || liveCellCount == 3) {
                        // 2. Any live cell with two or three live neighbors lives
                        tempOutput[i][j] = 1;
                    }
                    else if (liveCellCount > 3) {
                        // 3. Any live cell with more than three live neighbors dies
                        tempOutput[i][j] = 0;
                    }
                }
                else {
                    // current cell is a dead cell
                    if (liveCellCount == 3) {
                        // 4. Any dead cell with exactly three live neighbors becomes a live cell
                        tempOutput[i][j] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < totalRow; i++) {
            for(int j = 0; j < totalColumn; j++) {
                board[i][j] = tempOutput[i][j];
            }
        }
    }
};
