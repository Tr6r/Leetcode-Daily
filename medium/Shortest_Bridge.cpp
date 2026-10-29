/*
LC 934 - Shortest Bridge
Hours Effort: 01:55:46
Solution: BFS
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
                    q.push({j, i, 0});
                    md_grid[i][j] = 1;
                    island1 = {j, i, 0};
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
                q.push({dx, dy, 0});
            }
        }

        // find sec island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && md_grid[i][j] != 1) {
                    // cout << "sec: i: " << i << " - j: " << j << endl;
                    island2 = {j, i, 0};
                    hasPosisland2 = true;
                    break;
                }
            }
            if (hasPosisland2)
                break;
        }
        cout << "fst is: x: " << island1.x << " - y: " << island1.y << endl;
        cout << "sec is: x: " << island2.x << " - y: " << island2.y << endl;

        
        
        
        vector<vector<int>> md_maze(n, (vector<int>(n, 0)));
        q.push(island1);
        int min_b = 100;
        md_maze[island1.y][island1.x] = 1;
        bool finish = false;
        while (!q.empty()) {
            if (finish) return min_b;
            int count_loop = q.size();
            cout<<"------------"<<endl;
            for (int j = 0; j < count_loop; j++) {
                Pos node = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = node.x + dir[i].x;
                    int dy = node.y + dir[i].y;
                    int count_b = node.count;
                    if (is_borderd(dx, dy, n))
                        continue;
                    if (md_maze[dy][dx] == 1)
                        continue;
                    if (dx == island2.x && dy == island2.y) {
                        cout<<"aaaaaaaaaaa"<<endl;
                        cout << "DONE at: dx: " << dx
                             << " - dy: " << dy << endl;
                        if (min_b > count_b) min_b = count_b;
                        finish = true;
                    }
                    if (grid[dy][dx] == 0) {
                        count_b++;
                         cout << "count: " << count_b << " at: dx: " << dx
                             << " - dy: " << dy << endl;
                    }
                    // if (grid[dy][dx] == 1) {
                    //     cout << "RESET at: dx: " << dx
                    //          << " - dy: " << dy << endl;
                    //     count_b = 0;
                    // }
                    md_maze[dy][dx] = 1;
                    cout << "push at: dx: " << dx
                             << " - dy: " << dy << endl;                    q.push({dx, dy, count_b});
                }
            }
        }

        return -1;
    }
};