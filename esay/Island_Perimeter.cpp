/*
LC 463 - Island Perimeter
Time: O(N^2), Space: O(1)
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int w = grid[0].size();
        int h = grid.size();
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int tmp = 4;
                // dp 4 phia L T R B
                if (j != 0 && grid[i][j - 1] == 1) {
                    tmp--;
                }
                if (i != 0 && grid[i - 1][j] == 1) {
                    tmp--;
                }
                if (j != w - 1 && grid[i][j + 1] == 1) {
                    tmp--;
                }
                if (i != h - 1 && grid[i + 1][j] == 1) {
                    tmp--;
                }
                count += tmp;
            }
        }
        return count;
    }
};