#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        priority_queue<
            array<int,3>,
            vector<array<int,3>>,
            greater<array<int,3>>
        > pq;

        dp[0][1] = 0;
        pq.push({0, 0, 1});

        int ret = INT_MAX;

        while (!pq.empty()) {
            int d = pq.top()[0];
            int u = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            if (dp[u][c] != d)
                continue;

            if (u == n - 1)
                ret = min(ret, d);

            char prev = labels[u];

            for (auto to : adj[u]) {
                int nx = to.first;
                int ex = to.second;

                int nc;

                if (labels[nx] == prev)
                    nc = c + 1;
                else
                    nc = 1;

                if (nc <= k && dp[nx][nc] > d + ex) {
                    dp[nx][nc] = d + ex;
                    pq.push({dp[nx][nc], nx, nc});
                }
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }
};