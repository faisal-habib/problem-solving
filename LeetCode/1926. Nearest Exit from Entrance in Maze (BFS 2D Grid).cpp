class Solution {
public:

    int dx[4]= {1,-1,0,0},dy[4]= {0,0,1,-1};
    int row, col;
    bool vis[105][105];
    int level[105][105];

    bool _isValid(int r, int c) {
        if(r>=0 && r<row && c>=0 && c<col) return true;
        return false;
    }

    bool _isBorder(int r, int c) {
        if(r==0 || c==0 || r==row-1 || c==col-1) return true;
        return false;
    }

    int _bfs(vector<vector<char>>& maze, int srcR, int srcC) {

        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));

        queue< pair<int,int> >q;
        q.push({srcR, srcC});
        int minDistance = INT_MAX;

        while( !q.empty() ) {
            int ux = q.front().first;
            int uy = q.front().second;
            q.pop();
            vis[ux][uy] = true;

            for(int i=0; i<4; i++) {
                int vx = ux + dx[i];
                int vy = uy + dy[i];

                if(_isValid(vx, vy) && maze[vx][vy]=='.' && !vis[vx][vy]) {
                    level[vx][vy] = 1 + level[ux][uy];
                    vis[vx][vy] = true;

                    if(_isBorder(vx, vy)) {
                        minDistance = minDistance <= level[vx][vy] ? minDistance : level[vx][vy];
                    }
                    else q.push({vx, vy});
                }
            }
        }
        return minDistance==INT_MAX ? -1 : minDistance;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        row = maze.size();
        col = maze[0].size();

        int r = entrance[0], c = entrance[1];

        int distance = _bfs(maze, r, c);

        return distance;
    }
};
