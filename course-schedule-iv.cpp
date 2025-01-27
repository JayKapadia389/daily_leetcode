class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Adjacency list for the graph
        vector<vector<int>> graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        // Reachability matrix (to store transitive closure)
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // Perform BFS for each course to compute reachability
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int next : graph[curr]) {
                    if (!reachable[i][next]) {
                        reachable[i][next] = true;
                        q.push(next);
                    }
                }
            }
        }

        vector<bool> answer;
        for (auto& query : queries) {
            answer.push_back(reachable[query[0]][query[1]]);
        }

        return answer;
    }
};
