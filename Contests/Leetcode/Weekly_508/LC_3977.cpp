#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost,
                                      int source, int target) {
        vector<vector<pair<int, int>>> g(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            g[u].push_back({v, t});
        }

        const long long INF = 4e18;

        vector<vector<long long>> dist(
            n, vector<long long>(power + 1, INF)
        );

        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        long long bestTime = INF;
        long long bestPower = -1;

        while (!pq.empty()) {
            auto [time, u, p] = pq.top();
            pq.pop();

            if (time != dist[u][p])
                continue;

            if (time > bestTime)
                break;

            if (u == target) {
                if (time < bestTime) {
                    bestTime = time;
                    bestPower = p;
                } else {
                    bestPower = max(bestPower, (long long)p);
                }

                continue;
            }

            if (p < cost[u])
                continue;

            int newPower = p - cost[u];

            for (auto &[v, edgeTime] : g[u]) {
                long long newTime = time + edgeTime;

                if (newTime < dist[v][newPower]) {
                    dist[v][newPower] = newTime;
                    pq.push({newTime, v, newPower});
                }
            }
        }

        if (bestTime == INF)
            return {-1, -1};

        return {bestTime, bestPower};
    }
};