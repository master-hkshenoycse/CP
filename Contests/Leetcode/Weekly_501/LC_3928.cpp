#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;

    static constexpr ll INF = 4e18;

    struct Edge {
        int to;
        ll cost;
        ll taxiCost;
    };

    // Dijkstra using either:
    // type = 0 -> normal road cost
    // type = 1 -> taxi cost = cost * taxi
    void dijkstra(
        int src,
        const vector<vector<Edge>>& graph,
        vector<ll>& dist,
        int type
    ) {
        int n = graph.size();

        fill(dist.begin(), dist.end(), INF);

        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            // Stale entry
            if (d != dist[u])
                continue;

            for (const Edge& e : graph[u]) {

                ll w = (type == 0)
                     ? e.cost
                     : e.taxiCost;

                if (d + w < dist[e.to]) {

                    dist[e.to] = d + w;

                    pq.push({
                        dist[e.to],
                        e.to
                    });
                }
            }
        }
    }

    vector<int> minCost(
        int n,
        vector<int>& prices,
        vector<vector<int>>& roads
    ) {

        vector<vector<Edge>> graph(n);

        for (auto& r : roads) {

            int u = r[0];
            int v = r[1];

            ll cost = r[2];
            ll taxi = r[3];

            ll taxiCost = cost * taxi;

            graph[u].push_back({
                v,
                cost,
                taxiCost
            });

            graph[v].push_back({
                u,
                cost,
                taxiCost
            });
        }

        /*
            taxDist[i][j] =
            minimum taxi cost from i -> j.

            We keep this matrix because in the final
            formula we need:

                distTax[j][i]
        */
        vector<vector<ll>> taxDist(
            n,
            vector<ll>(n, INF)
        );

        vector<ll> dist(n);

        // -------------------------------------------------
        // First: all-pairs shortest paths using taxi cost
        // -------------------------------------------------

        for (int src = 0; src < n; src++) {

            dijkstra(
                src,
                graph,
                dist,
                1
            );

            for (int v = 0; v < n; v++) {
                taxDist[src][v] = dist[v];
            }
        }

        vector<int> ans(n);

        // -------------------------------------------------
        // For every starting city i:
        //
        // i --normal cost--> j
        // j --taxi cost----> i
        //
        // Total:
        //
        // distCost(i,j)
        // + prices[j]
        // + distTaxi(j,i)
        // -------------------------------------------------

        for (int i = 0; i < n; i++) {

            // Don't travel anywhere.
            ll best = prices[i];

            // Run Dijkstra from i using normal road cost.
            dijkstra(
                i,
                graph,
                dist,
                0
            );

            for (int j = 0; j < n; j++) {

                if (dist[j] == INF ||
                    taxDist[j][i] == INF) {
                    continue;
                }

                ll candidate =
                    dist[j]
                    + prices[j]
                    + taxDist[j][i];

                best = min(best, candidate);
            }

            ans[i] = (int)best;
        }

        return ans;
    }
};