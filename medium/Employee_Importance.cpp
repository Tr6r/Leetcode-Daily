/*
LC 690 - Employee Importance
Hours Effort: 00:04:51
Solution: BFS
Time: O(N^2), Space: O(N)
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0;
        queue<Employee*> q;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                q.push(employees[i]);
            }
        }
        while (!q.empty()) {
            Employee* e = q.front();
            q.pop();
            ret += e->importance;
            int ssize = e->subordinates.size();
            if (ssize > 0) {
                for (int j = 0; j < ssize; j++) {
                    for (int i = 0; i < employees.size(); i++) {
                        if (employees[i]->id ==e->subordinates[j] ) {
                            q.push(employees[i]);
                            break;
                        }
                    }
                }
            }
        }
        return ret;
    }
};