class Solution {
private:
void heirholzer(string curr_node, unordered_map<string, vector<string>>& adj, vector<string>& ans) {
    while (!adj[curr_node].empty()) {
        string back = adj[curr_node].back();
        adj[curr_node].pop_back();
        heirholzer(back, adj, ans);
    }
    ans.push_back(curr_node);
}

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        vector<string> ans;
        ans.reserve(n + 1);
        unordered_map<string, vector<string>> adj;

        sort(tickets.begin(), tickets.end(), greater<>());

        for(auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        heirholzer("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};