#include<bits/stdc++.h>
using namespace std;
 
 int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
         // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int minCycle = INT_MAX;

        // Step 2: BFS from each vertex
        for (int i = 0; i < V; i++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) { // not visited
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } 
                    else if (parent[u] != v) {
                        // Found a cycle
                        int cycleLen = dist[u] + dist[v] + 1;
                        minCycle = min(minCycle, cycleLen);
                    }
                }
            }
        }

        if (minCycle == INT_MAX) return -1;
        return minCycle;
    }