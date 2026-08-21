#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int evenSumSubgraphs(vector<int>& nums,
                         vector<vector<int>>& edges) {

        int n = nums.size();
        int ans = 0;

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // ----------------------------------------------------
        // Try every subset of vertices.
        //
        // mask tells us which vertices belong to the
        // selected subgraph.
        // ----------------------------------------------------
        for (int mask = 1; mask < (1 << n); mask++) {

            vector<int> vis(n, 0);

            // DFS for this particular subset
            auto dfs = [&](auto&& self, int v) -> void {

                vis[v] = 1;

                for (int to : adj[v]) {

                    // Visit 'to' only if:
                    // 1. It belongs to this subset
                    // 2. It hasn't been visited
                    if ((mask & (1 << to)) &&
                        !vis[to]) {

                        self(self, to);
                    }
                }
            };

            // ------------------------------------------------
            // Check whether the selected vertices form a
            // connected subgraph.
            // ------------------------------------------------
            int start = -1;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    start = j;
                    break;
                }
            }

            dfs(dfs, start);

            bool connected = true;

            for (int j = 0; j < n; j++) {

                // j belongs to subset but wasn't visited
                if ((mask & (1 << j)) &&
                    !vis[j]) {

                    connected = false;
                    break;
                }
            }

            if (!connected)
                continue;

            // ------------------------------------------------
            // Calculate sum of values in this subgraph.
            // ------------------------------------------------
            int sum = 0;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    sum += nums[j];
                }
            }

            // Count if sum is even
            if (sum % 2 == 0)
                ans++;
        }

        return ans;
    }
};