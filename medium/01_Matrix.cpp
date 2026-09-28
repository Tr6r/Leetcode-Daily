/*
LC 542 - 01 Matrix
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
        queue<Pos> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    q.push({.x = j, .y = i});
                }
            }
        }
        int loopCount = q.size();
        Pos dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < loopCount; i++) {
            Pos tmpP = q.front();
            q.pop();
            int tmpx = tmpP.x;
            int tmpy = tmpP.y;
            cout << "find " << i << ": x: " << tmpx << " y: " << tmpy << endl;
            int count = 0;
            vector<vector<int>> md(row, (vector<int>(col, 0)));
            queue<Pos> tmp;
            tmp.push(tmpP);

            while (!tmp.empty()) {
                Pos n = tmp.front();
                count++;
                tmp.pop();
                for (int j = 0; j < 4; j++) {
                    int dx = n.x + dir[j].x;
                    int dy = n.y + dir[j].y;
                    cout << "count: " << count << endl;
                    cout << "now " << i << ": x: " << dx << " y: " << dy
                         << endl;

                    if (isBorder(dx, dy, col, row) ) continue;

                    if (md[dy][dx] == 1) continue;

                    if (mat[dy][dx] == 1) {
                        md[dy][dx] = 1;
                        tmp.push({.x = dx, .y = dy});
                    } else {
                        cout << "done" << " x: " << dx << " y: " << dy << endl;
                        mat[tmpy][tmpx] = count;
                        tmp = queue<Pos>();
                        break;
                    }
                }
            }
        }

        return mat;
    }
};