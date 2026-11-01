/*
LC 934 - Shortest Bridge
Hours Effort: 03:02:21
Solution: BFS
Time: O(N), Space: O(N) | n = all items in maze
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
        int count;
    } Pos;
    bool is_borderd(int x, int y, int n) {
        return (x > n - 1 || x < 0 || y > n - 1 || y < 0);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<int>> md_grid(n, (vector<int>(n, 0)));
        queue<Pos> q;
        queue<Pos> il1;

        bool hasPosisland1 = false;
        Pos dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        // find fist island

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // cout << "i: " << i << " - j: " << j << endl;
                    q.push({j, i, 0});
                    md_grid[i][j] = 1;

                    il1.push({j, i, 0});
                    hasPosisland1 = true;
                    break;
                }
            }
            if (hasPosisland1)
                break;
        }

        while (!q.empty()) {
            Pos node = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = node.x + dir[i].x;
                int dy = node.y + dir[i].y;
                if (is_borderd(dx, dy, n))
                    continue;
                if (md_grid[dy][dx] == 1 || grid[dy][dx] == 0)
                    continue;
                // cout << "fst is: dx: " << dx << " - dy: " << dy << endl;
                md_grid[dy][dx] = 1;
                il1.push({dx, dy, 0});
                q.push({dx, dy, 0});
            }
        }
        // find sec island

        while (!il1.empty()) {
            Pos node = il1.front();
            il1.pop();
            for (int i = 0; i < 4; i++) {
                int dx = node.x + dir[i].x;
                int dy = node.y + dir[i].y;
                int count_b = node.count;
                if (is_borderd(dx, dy, n))
                    continue;
                if (md_grid[dy][dx] == 1)
                    continue;
                if (grid[dy][dx] == 1 && md_grid[dy][dx] == 0) {
                    return count_b;
                }
                if (grid[dy][dx] == 0) {
                    count_b++;
                }
                md_grid[dy][dx] = 1;
                il1.push({dx, dy, count_b});
            }
        }
        return -1;
    }
};