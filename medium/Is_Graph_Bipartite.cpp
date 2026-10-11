/*
LC 785 - Is Graph Bipartite?
Hours Effort: 01:57:51
Solution: DFS
Time: O(N), Space: O(N)
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> color(n, 'm');
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (color[i] != 'm') continue;

            color[i] = 'a';
            st.push(i);

            while (!st.empty()) {
                int u = st.top();
                st.pop();

                char opposite = (color[u] == 'a') ? 'b' : 'a';

                for (int v : graph[u]) {
                    if (color[v] == 'm') {
                        color[v] = opposite;
                        st.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};