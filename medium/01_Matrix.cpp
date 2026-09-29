/*
LC 542 - 01 Matrix
Solution: BFS
Time: O(N^4), Space: O(M)
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
            // cout << "loopCount: " << i << endl;
            Pos tmpP = q.front();
            q.pop();
            int tmpx = tmpP.x;
            int tmpy = tmpP.y;
            // cout << "find " << i << ": x: " << tmpx << " y: " << tmpy << endl;
            int count = 0;
            vector<vector<int>> md(row, (vector<int>(col, 0)));
            queue<Pos> tmp;
            tmp.push(tmpP);

            while (!tmp.empty()) {
                count++;
                // cout << "count: " << count << endl;
                int smallLoopCount = tmp.size();
                // cout<<"smallLoopCount: "<<smallLoopCount<<endl;
                for (int k = 0; k < smallLoopCount; k++) {
                    Pos n = tmp.front();
                    md[n.y][n.x] = 1;

                    tmp.pop();
                    for (int j = 0; j < 4; j++) {
                        int dx = n.x + dir[j].x;
                        int dy = n.y + dir[j].y;
                        // cout << "now " << i << ": x: " << dx << " y: " << dy
                        //      << endl;

                        if (isBorder(dx, dy, col, row))
                            continue;

                        if (md[dy][dx] == 1)
                            continue;
                        // cout << "mat[dy][dx]" << mat[dy][dx] << endl;

                        if (mat[dy][dx] != 0) {
                            md[dy][dx] = 1;
                            tmp.push({.x = dx, .y = dy});
                        } else {
                            // cout << "done" << " x: " << dx << " y: " << dy
                            //      << endl;
                            mat[tmpy][tmpx] = count;
                            // cout << "____" << endl;
                            tmp = queue<Pos>();
                            // cout << "____" << endl;
                            k = smallLoopCount;
                            break;
                        }
                    }
                }
            }
        }

        return mat;
    }
};