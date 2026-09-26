/*
LC 1926 - Nearest Exit from Entrance in Maze
Solution: BFS
Time: O(N), Space: O(N)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } pos;
    bool isEntry(int x, int y, vector<int> entrance) {
        return (entrance[1] == x && entrance[0] == y);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int col = maze[0].size();
        int row = maze.size();
        vector<vector<int>> done_maze(row, vector<int>(col, 0));
        queue<pos> q;
        long count = -1;
        q.push({.y = entrance[0], .x = entrance[1]});

        while (!q.empty()) {

            pos node = q.front();
            q.pop();

            if (node.y == row - 1 && !isEntry(node.x, node.y, entrance)) {
                count = done_maze[node.y][node.x];
                break;
            }
            if (node.x == 0 && !isEntry(node.x, node.y, entrance)) {
                count = done_maze[node.y][node.x];
                break;
            }
            if (node.y == 0 && !isEntry(node.x, node.y, entrance)) {
                count = done_maze[node.y][node.x];
                break;
            }
            if (node.x == col - 1 && !isEntry(node.x, node.y, entrance)) {
                count = done_maze[node.y][node.x];
                break;
            }
            // check L T R B
            int dx = node.x - 1;
            int dy = node.y;
            if (node.x != 0 && done_maze[dy][dx] == 0 &&
                !isEntry(dx, dy, entrance)) {
                if (maze[dy][dx] == '.') {
                    if (dx == 0) {
                        count = done_maze[node.y][node.x] + 1;
                        break;
                    } else {
                        done_maze[dy][dx] = done_maze[node.y][node.x] + 1;
                        q.push({.x = dx, .y = dy});
                    }
                }
            }
            dx = node.x;
            dy = node.y - 1;
            if (node.y != 0 && done_maze[dy][dx] == 0 &&
                !isEntry(dx, dy, entrance)) {
                if (maze[dy][dx] == '.') {
                    if (dy == 0) {
                        count = done_maze[node.y][node.x] + 1;
                        break;
                    } else {
                        done_maze[dy][dx] = done_maze[node.y][node.x] + 1;
                        q.push({.x = dx, .y = dy});
                    }
                }
            }
            dx = node.x + 1;
            dy = node.y;
            if (node.x != col - 1 && done_maze[dy][dx] == 0 &&
                !isEntry(dx, dy, entrance)) {
                if (maze[dy][dx] == '.') {
                    if (dx == col - 1) {
                        count = done_maze[node.y][node.x] + 1;
                        break;
                    } else {
                        done_maze[dy][dx] = done_maze[node.y][node.x] + 1;
                        q.push({.x = dx, .y = dy});
                    }
                }
            }
            dx = node.x;
            dy = node.y + 1;
            if (node.y != row - 1 && done_maze[dy][dx] == 0 &&
                !isEntry(dx, dy, entrance)) {
                if (maze[dy][dx] == '.') {
                    if (dy == row - 1) {
                        count = done_maze[node.y][node.x] + 1;
                        break;
                    } else {
                        done_maze[dy][dx] = done_maze[node.y][node.x] + 1;
                        q.push({.x = dx, .y = dy});
                    }
                }
            }
        }
        return count;
    }
};