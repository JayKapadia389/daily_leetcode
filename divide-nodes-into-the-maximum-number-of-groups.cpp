class Solution {
public:

    bool isBipartite(int n, vector<vector<int>>& adjList, vector<int>& color) {
        queue<int> q;

        for (int start = 1; start <= n; ++start) {
            if (color[start] == -1) {  // Start a new component BFS
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (auto i : adjList[curr]) {
                        if (color[i] == -1) {
                            color[i] = 1 - color[curr];
                            q.push(i);
                        }
                        else if (color[i] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    int getLongestShortestPath(vector<vector<int>>& adjList, int src, int n) {
        queue<int> q;
        vector<int> dist(n + 1, -1);
        q.push(src);
        dist[src] = 0;
        int maxDist = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto j : adjList[curr]) {
                if (dist[j] == -1) {
                    dist[j] = dist[curr] + 1;
                    q.push(j);
                    maxDist = max(maxDist, dist[j]);
                }
            }
        }

        return maxDist + 1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n + 1);
        for (auto edge : edges) {
            int f = edge[0], s = edge[1];
            adjList[f].push_back(s);
            adjList[s].push_back(f);
        }

        vector<int> color(n + 1, -1);
        if (!isBipartite(n, adjList, color)) {
            return -1;
        }

        vector<bool> visited(n + 1, false);
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                queue<int> q;
                vector<int> component;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    component.push_back(curr);

                    for (auto neighbor : adjList[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Find max shortest path in this component
                int maxPath = 0;
                for (int node : component) {
                    maxPath = max(maxPath, getLongestShortestPath(adjList, node, n));
                }

                ans += maxPath;
            }
        }

        return ans;
    }
};
