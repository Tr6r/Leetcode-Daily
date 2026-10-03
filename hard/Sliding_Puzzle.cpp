/*
LC 773 - Sliding Puzzle
Effort: 2:16:04
Solution: BFS
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
    int slidingPuzzle(vector<vector<int>>& board) {
        int row = 2;
        int col = 3;
        int min = INT_MAX;
        Pos pos_s;
        Pos dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 0) {
                    pos_s.x = j;
                    pos_s.y = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int count = 0;
            int dx = pos_s.x + dir[i].x;
            int dy = pos_s.y + dir[i].y;
            if (isBorder(dx, dy, col, row))
                continue;
            queue<Ctx> q;
            vector<vector<int>> board_tmp = board;
            swap(&board_tmp[pos_s.y][pos_s.x], &board_tmp[dy][dx]);
 
            if (isCorrect(board_tmp))
                return 1;
            q.push({.pos = {.x = dx, .y = dy}, .board = board_tmp});
            cout << "______\n";
            // while (!q.empty()) {
            //       Ctx n = q.front();
            //     q.pop();
            //     cout << "AT - y: " << n.pos.y  << " x: " << n.pos.x << "\n";
            //     pr_board(n.board);
            // }
            while (!q.empty()) {
                count++;
                cout << "count: " << count << "\n";

                int count_loop = q.size();
                for (int j = 0; j < count_loop; j++) {
                    Ctx n = q.front();
                    q.pop();
                    cout << "AT - y: " << n.pos.y  << " x: " << n.pos.x
                             << "\n";
                    for (int k = 0; k < 4; k++) {

                        int dx2 = n.pos.x + dir[k].x;
                        int dy2 = n.pos.y + dir[k].y;
                        cout << "reach - dy2: " << dy2 << " dx2: " << dx2
                             << "\n";

                        if (isBorder(dx2, dy2, col, row)) {
                            cout << "skip border" << endl;
                            continue;
                        }
           
                        swap(&n.board[n.pos.y][n.pos.x], &n.board[dy2][dx2]);
                        if (isCorrect(n.board)) {
                            cout<<"DONE"<<endl;
                            if (min > count + 1) min = count + 1;
                            q = queue<Ctx>();
                            j = count_loop;
                            break;
                        }
                        
                        q.push({.pos = {.x = dx2, .y = dy2}, .board = n.board});
                    }
                }
            }
        }
        return -1;
    }
};