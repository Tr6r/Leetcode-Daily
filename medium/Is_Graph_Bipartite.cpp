/*
LC 785 - Is Graph Bipartite?
Hours Effort: 01:57:51
*/

class Solution {
public:
    typedef struct {
        int idx;
        char gr;
    } Node;
    bool isBipartite(vector<vector<int>>& graph) {
        int ns = graph.size();
        queue<Node> q;
        vector<Node> l (ns, {0});
        l[0].idx = 0;
        l[0].gr = 'a';
        
        for (int i = 1; i < ns; i++) {
            q.push({.idx = i, .gr = 'm'});
            l[i].idx = i;
            l[i].gr = 'm';
        }

        for (int i = 0; i < graph[0].size(); i++) {
            l[graph[0][i]].gr = 'b';
        }
        while(!q.empty()) {
            Node n = q.front();
            q.pop();
            char ctmp = 'm';
            for (int j = 0; j < graph[n.idx].size(); j++) {
                // cout<< "node index: "<< graph[n.idx][j]<<endl;
                // cout<< "test: "<< done[1].gr<<endl;

                if (l[graph[n.idx][j]].gr == 'a') {
                    if (l[n.idx].gr == 'a') {
                        return false;
                    } 
                    ctmp = 'b';
                    break;
                }
                else if (l[graph[n.idx][j]].gr == 'b') {
                    if (l[n.idx].gr == 'b') {
                        return false;
                    } 
                    ctmp = 'a';
                    break;
                }

            }
            if (ctmp == 'm') {
                if (graph[n.idx].size() == 0) continue;
                q.push(n);
                continue;
            }
            cout <<"n.idx: "<<n.idx <<" ctmp: "<<ctmp<<endl;
            if (ctmp == 'a') {
                l[n.idx].gr = 'a';
                for (int j = 0; j < graph[n.idx].size(); j++) {
                    if (l[graph[n.idx][j]].gr == 'a') {
                        return false;
                    }
                    l[graph[n.idx][j]].gr = 'b';
                }
            } else {
                l[n.idx].gr = 'b';
                for (int j = 0; j < graph[n.idx].size(); j++) {
                    if (l[graph[n.idx][j]].gr == 'b') {
                        return false;
                    }
                    l[graph[n.idx][j]].gr = 'a';
                }
            }

        }
        return true;
    }
};