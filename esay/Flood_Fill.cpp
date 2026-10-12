/*
LC 733 - Flood Fill
Solution: BFS
Hours Effort: 00:12:48
Time: O(N), Space: O(N)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } Pos;
    bool isBorder(int x, int y, int col, int row) {
        return (x < 0 || x > col - 1 || y < 0 || y > row-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<Pos> q;
        int col = image[0].size();
        int row = image.size();
        int type = image[sr][sc];
        image[sr][sc] = color;
        q.push({.x = sc, .y = sr});
        Pos dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()){
            Pos n = q.front();
            q.pop();
            for (int i =0; i< 4 ; i++) {
                int dx = n.x + dir[i].x;
                int dy = n.y + dir[i].y;
                if (isBorder(dx, dy, col,row)) continue;
                if (image[dy][dx] == color || image[dy][dx] !=  type) continue;
                image[dy][dx]  = color;
                q.push({dx,dy});
            }
        }
        return image;
    }
};