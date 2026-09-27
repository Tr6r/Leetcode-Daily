/*
LC 994 - Rotting Oranges
Solution: BFS
Time: O(N), Space: O(N)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } Pos;
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = -1;
        queue<Pos> q;
        bool hasfruit = false;
        if (row == 1 && col == 1){
            if (grid[0][0] == 0) return 0;
            else if (grid[0][0] == 1) return -1;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({.x = j, .y = i});
                } else if (grid[i][j] == 1) {
                    hasfruit = true;
                }
            }
        }
        if (!hasfruit) return 0;
        // L T R B
        Pos dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            count++;
            int loopCount = q.size();
            for (int j = 0 ; j < loopCount; j++) {
                Pos node = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = node.x + dir[i].x;
                    int dy = node.y + dir[i].y;
                    if (dx < 0 || dx > col - 1 || dy < 0 || dy > row - 1)
                        continue;
                    if (grid[dy][dx] == 1) {
                        grid[dy][dx] = 2;
                        q.push({.x = dx, .y = dy});
                    }
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
};