#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int LOG = 17;

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {

        // ---------- Build tree ----------
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<vector<int>> parent(LOG, vector<int>(n, -1));
        vector<int> depth(n), tin(n), tout(n);
        int timer = 0;

        dfs(0, -1, g, parent, depth, tin, tout, timer);

        // ---------- Binary lifting ----------
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++) {
                int p = parent[k-1][i];
                if (p != -1)
                    parent[k][i] = parent[k-1][p];
            }

        // ---------- Fenwick ----------
        Fenwick fenwick(n);

        for (int i = 0; i < n; i++) {
            int m = mask(s[i]);
            fenwick.add(tin[i], m);
            fenwick.add(tout[i] + 1, m);
        }

        vector<bool> ans;

        for (auto &q : queries) {

            stringstream ss(q);
            string t;
            ss >> t;

            if (t == "update") {

                int u; char c;
                ss >> u >> c;

                int delta = mask(s[u]) ^ mask(c);
                s[u] = c;

                fenwick.add(tin[u], delta);
                fenwick.add(tout[u] + 1, delta);

            } else {

                int u, v;
                ss >> u >> v;

                int w = lca(u, v, parent, depth);

                int m = fenwick.sum(tin[u])
                        ^ fenwick.sum(tin[v])
                        ^ mask(s[w]);

                ans.push_back(m == 0 || (m & (m - 1)) == 0);
            }
        }

        return ans;
    }

private:

    // ---------- DFS ----------
    void dfs(
        int u, int p,
        vector<vector<int>>& g,
        vector<vector<int>>& parent,
        vector<int>& depth,
        vector<int>& tin,
        vector<int>& tout,
        int& timer
    ) {
        tin[u] = timer++;
        parent[0][u] = p;

        for (int v : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, g, parent, depth, tin, tout, timer);
        }

        tout[u] = timer - 1;
    }

    // ---------- LCA ----------
    int lca(int u, int v,
            vector<vector<int>>& parent,
            vector<int>& depth) {

        if (depth[u] < depth[v])
            swap(u, v);

        int d = depth[u] - depth[v];
        for (int k = 0; k < LOG; k++)
            if (d & (1 << k))
                u = parent[k][u];

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--)
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }

        return parent[0][u];
    }

    int mask(char c) {
        return 1 << (c - 'a');
    }

    // ---------- Fenwick ----------
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n+1) {}

        void add(int i, int val) {
            for (++i; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int sum(int i) {
            int r = 0;
            for (++i; i > 0; i -= i & -i)
                r ^= bit[i];
            return r;
        }
    };
};