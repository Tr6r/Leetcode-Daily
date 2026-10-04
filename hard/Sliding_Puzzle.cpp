/*
LC 773 - Sliding Puzzle
Hours Effort: 2:54:38
Solution: BFS
Time: O(1), Space: O(1)
*/

class Solution {
public:
    typedef struct {
        int x;
        int y;
    } Pos;
    typedef struct {
        Pos pos;
        vector<vector<int>> board;
    } Ctx;
    bool isBorder(int x, int y, int col, int row) {
        return (x < 0 || x > col - 1 || y < 0 || y > row - 1);
    }
    bool isCorrect(const vector<vector<int>>& board) {
        int samp[2][3] = {{1, 2, 3}, {4, 5, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != samp[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    void swap(int* value1, int* value2) {
        int tmp = *value2;
        *value2 = *value1;
        *value1 = tmp;
    }

    void pr_board(const vector<vector<int>>& board) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool isExist(vector<vector<int>>& board, unordered_map<string, int> &hashTable) {
        string str_maze;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                str_maze += to_string(board[i][j]);
            }
        }
        int count_ex  =hashTable.count(str_maze);

        if (count_ex != 0) 
            return true;
        
        hashTable[str_maze] = 1;
        return false;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        if (isCorrect(board)) return 0;
        int row = 2;
        int col = 3;
        int min = INT_MAX;
        Pos dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<Ctx> q;
        unordered_map<string, int> hashTable;
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 0) {
                    q.push({.pos.x = j, .pos.y = i, .board = board});
                    break;
                }
            }
        }
         
        while (!q.empty()) {
            int count_l = q.size();
            
            count++;
            for (int j = 0; j < count_l; j++) {
                Ctx c = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = c.pos.x + dir[i].x;
                    int dy = c.pos.y + dir[i].y;
                    if (isBorder(dx,dy,col,row))
                        continue;
                    vector<vector<int>> board_tmp = c.board;
                    swap(&board_tmp[c.pos.y][c.pos.x], &board_tmp[dy][dx]);
                    if (isExist(board_tmp,hashTable))
                        continue;
                    if (isCorrect(board_tmp))
                        return count;
                    q.push({.pos.x = dx, .pos.y = dy, .board = board_tmp});
                }
            }
        }
        return -1;
    }
};