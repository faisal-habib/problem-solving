class Solution {
public:
    ///8 direction
    int dir_x[8]={-1,-1,-1,1,1,1,0,0};
    int dir_y[8]={0,-1,1,0,-1,1,-1,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] || grid[row-1][col-1]) return -1;

        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        grid[0][0] = 1; // using grid as visited array & length of the path array (level)

        while(!q.empty()) {
            pair<int,int>curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            if(x==row-1 && y==col-1) return grid[x][y]; // already reached the destination

            for(int d=0; d<8; d++) {
                int xx = x+dir_x[d], yy = y+dir_y[d];

                if(xx>=0 && xx<row && yy>=0 && yy<col && grid[xx][yy]==0) {
                    grid[xx][yy] = grid[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
        return -1;
    }
};
