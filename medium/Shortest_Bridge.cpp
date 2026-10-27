/*
LC 934 - Shortest Bridge
Hours Effort: 00:49:39
Solution: BFS
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } Pos;
    bool is_borderd(int x, int y, int n) {
        return (x > n - 1 || x < 0 || y > n - 1 || y < 0);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<int>> md_grid(n, (vector<int>(n, 0)));
        queue<Pos> q;
        Pos island1;
        Pos island2;
        bool hasPosisland1 = false;
        bool hasPosisland2 = false;
        Pos dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        // find fist island

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cout << "i: " << i << " - j: " << j << endl;
                    q.push({j, i});
                    md_grid[i][j] = 1;
                    island1 = {i, j};
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
                cout << "fst is: dx: " << dx << " - dy: " << dy << endl;
                md_grid[dy][dx] = 1;
                q.push({dx, dy});
            }
        }

        // find sec island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && md_grid[i][j] != 1) {
                    cout << "sec: i: " << i << " - j: " << j << endl;
                    island2 = {i, j};
                    hasPosisland2 = true;
                    break;
                }
            }
            if (hasPosisland2)
                break;
        }

        cout << "fst is: x: " << island1.x << " - y: " << island1.y << endl;
        cout << "sec is: x: " << island2.x << " - y: " << island2.y << endl;

        return 0;
    }
};