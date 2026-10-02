/*
LC 200 - Number of Islands
Solution: BFS
Time: O(N), Space : O(N)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } Pos;
    bool is_border(int x, int y, int row, int col) {
        return x < 0 || x > col - 1 || y < 0 || y > row - 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> island(row, (vector<int>(col, 0)));
        queue<Pos> q;
        queue<Pos> tmp;
        Pos dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0')
                    continue;
                q.push({.x = j, .y = i});
            }
        }
        while (!q.empty()) {
            Pos n = q.front();
            q.pop();
            if (island[n.y][n.x] == 2) 
                continue;
            count++;
            tmp.push({.x = n.x, .y = n.y});
            while (!tmp.empty()) {
                Pos t = tmp.front();
                tmp.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = t.x + dir[i].x;
                    int dy = t.y + dir[i].y;
                    if (is_border(dx, dy, row, col))
                        continue;
                    if (island[dy][dx] == 2) 
                     continue;
                    if (grid[dy][dx] == '1') {
                        tmp.push({.x = dx, .y = dy});
                        island[dy][dx] = 2;
                    }
                }
            }
        }
        return count;
    }
};