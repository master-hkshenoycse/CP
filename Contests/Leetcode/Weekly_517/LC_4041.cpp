#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {

        const int INF = 1e9;

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int x : nums) {

            int M = max(sum, x);

            vector<int> cost(M + 1, INF);
            queue<int> q;

            cost[x] = 0;
            q.push(x);

            vector<pair<int,int>> options;

            while (!q.empty()) {

                int v = q.front();
                q.pop();

                int c = cost[v];

                // v is a useful value only if it can contribute to sum
                if (v <= sum)
                    options.push_back({v, c});

                // divide
                int a = v / 2;

                if (a >= 1 && cost[a] == INF) {
                    cost[a] = c + 1;
                    q.push(a);
                }

                // multiply
                long long b = 2LL * v;

                if (b <= sum && cost[b] == INF) {
                    cost[b] = c + 1;
                    q.push((int)b);
                }
            }

            // 0/1 knapsack
            for (int s = sum; s >= 0; s--) {

                if (dp[s] == INF)
                    continue;

                for (auto [v, c] : options) {

                    if (s + v > sum)
                        continue;

                    dp[s + v] = min(dp[s + v],
                                    dp[s] + c);
                }
            }
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};