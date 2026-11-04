/*
LC 547 - Number of Provinces
Hours Effort: 00:25:58
Solution: DFS
Time: O(N^2), Space: O(N)
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ret = 0;
        stack<int> st;
        // ? tìm từng item - BFS cho tới hết các connect
        for (int i = 0; i < n; i++) {
            if (isConnected[i][i] == 2)
                continue;
            isConnected[i][i] = 2;
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 2 || isConnected[i][j] == 0) {
                    continue;
                } else {
                    isConnected[i][j] = 2;
                    st.push(j);
                }
            }
            while (!st.empty()) {
                int tmp = st.top();
                st.pop();
                isConnected[tmp][tmp] = 2;
                for (int z = 0; z < n; z++) {
                    if (isConnected[tmp][z] == 2 || isConnected[tmp][z] == 0) {
                        continue;
                    } else {
                        isConnected[tmp][z] = 2;
                        st.push(z);
                    }
                }
            }
            ret++;
        }
        return ret;
    }
};