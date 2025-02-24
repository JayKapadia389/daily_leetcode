class Solution {
public:
    int bob_, n_;

    bool findPath(vector<int>& path, vector<bool>& visited, map<int, vector<int>>& adjList, int curr) {
        if (curr == bob_) return true;
        visited[curr] = true;

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                path.push_back(neighbor);
                if (findPath(path, visited, adjList, neighbor)) return true;
                path.pop_back();
            }
        }

        return false;
    }

    void rewrite(vector<bool>& visited, vector<int>& amount, queue<int>& q, map<int, vector<int>>& adjList) {
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int node : adjList[curr]) {
                if (!visited[node]) {
                    visited[node] = true;
                    amount[node] += amount[curr];
                    q.push(node);
                }
            }
        }
    }

    void maximizeLeaf(vector<int>& amount, map<int, vector<int>>& adjList, vector<bool>& visited, int& ans, int curr) {
        visited[curr] = true;
        bool isLeaf = true;

        for (int i : adjList[curr]) {
            if (!visited[i]) {
                isLeaf = false;
                maximizeLeaf(amount, adjList, visited, ans, i);
            }
        }

        if (isLeaf) ans = max(ans, amount[curr]);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n_ = edges.size() + 1;
        map<int, vector<int>> adjList;
        bob_ = bob;

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> path = { 0 };
        vector<bool> visited(n_, false);
        findPath(path, visited, adjList, 0);

        int pathSize = path.size();
        vector<int> bobPath(n_, -1);

        for (int i = 0; i < pathSize; ++i) bobPath[path[i]] = i;

        int bobIdx = pathSize - 1;
        while (bobIdx >= 0) {
            if (bobIdx > pathSize / 2) {
                amount[path[bobIdx]] = 0;
            }
            else if (bobIdx == pathSize / 2) {
                amount[path[bobIdx]] /= 2;
            }
            bobIdx--;
        }

        fill(visited.begin(), visited.end(), false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        rewrite(visited, amount, q, adjList);

        int ans = INT_MIN;
        fill(visited.begin(), visited.end(), false);
        maximizeLeaf(amount, adjList, visited, ans, 0);

        return ans;
    }
};
