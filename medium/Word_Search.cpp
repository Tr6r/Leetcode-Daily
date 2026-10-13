/*
LC 79 - Word Search
Hours Effort: 00:50:58
Solution: DFS
Time: O(N), Space: O(N^2)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;

    } Pos;
    typedef struct {
        Pos pos;
        int nw_idx;
        vector<vector<int>> md;
    } CTX;
    bool is_border(int dx, int dy, int row, int col) {
        return (dx < 0 || dx > col - 1 || dy < 0 || dy > row - 1);
    }
    bool exist(vector<vector<char>>& board, string word) {
        stack<CTX> st;
        int row = board.size();
        int col = board[0].size();
        // find base - first word
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> tmp(row, vector<int>(col, 0));
                    tmp[i][j] = 1;
                    st.push({.pos = {.x = j, .y = i}, .nw_idx = 1, .md = tmp});
                }
            }
        }
        Pos dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while (!st.empty()) {
            // cout << "____new_path___: " << endl;
            CTX ctx = st.top();
            st.pop();
            if (ctx.nw_idx == word.size()) return true;
            int target_idx = ctx.nw_idx + 1;
            for (int j = 0; j < 4; j++) {
                int dx = ctx.pos.x + dir[j].x;
                int dy = ctx.pos.y + dir[j].y;
                if (is_border(dx, dy, row, col))
                    continue;
                if (ctx.md[dy][dx] == 1 || board[dy][dx] != word[ctx.nw_idx])
                    continue;
                vector<vector<int>> tmp = ctx.md;
                tmp[dy][dx] = 1;
                // cout << "dx: " << dx << " - dy: " << dy << endl;
                // cout << "---------------" << endl;
                st.push({.pos = {dx, dy}, .nw_idx = target_idx ,.md = tmp});
            }
        }
        return false;
    }
};