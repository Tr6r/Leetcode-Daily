/*
LC 542 - 01 Matrix
Solution: BFS
Time: O(N), Space: O(N)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } Pos;
    bool isBorder(int dx, int dy, int col, int row) {
        return (dx < 0 || dx > col - 1 || dy < 0 || dy > row - 1);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int col = mat[0].size();
        int row = mat.size();
        int count_1 = 0;
        queue<Pos> q;

        Pos dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> md(row, (vector<int>(col, 0)));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    md[i][j] = -1;
                    q.push({.x = j, .y = i});

                } else {
                    count_1 ++;
                }
            }
        }

        int count = 0;
        while (!q.empty()) {
            int loopCount = q.size();
            count++;
            for (int i = 0; i < loopCount; i++) {
                Pos n = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int dx = n.x + dir[j].x;
                    int dy = n.y + dir[j].y;
                    if (isBorder(dx, dy, col, row)) {
                        continue;
                    }
                    if (md[dy][dx] == -1) {
                        continue;
                    }
                    if (mat[dy][dx] == 1) {
                        mat[dy][dx] = count;
                        count_1 --;
                        if (count_1 == 0) return mat;
                    }
                    md[dy][dx] = -1;
                    q.push({.x = dx, .y = dy});
                }
            }
        }
        return mat;
    }
};