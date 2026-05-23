#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int d) {

        int n = grid.size();
        int m = grid[0].size();

        const int mod = 1e9 + 7;

        vector<vector<int>> dp1(n, vector<int>(m, 0));
        vector<vector<int>> dp2(n, vector<int>(m, 0));

        int R = 0;

        if (d * d - 1 >= 0)
            R = (int)sqrt(d * d - 1);

        for (int i = n - 1; i >= 0; i--) {

            if (i == n - 1) {

                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '.')
                        dp1[i][j] = 1;
                }

                vector<long long> pref(m + 1, 0);

                for (int j = 0; j < m; j++) {
                    pref[j + 1] =
                        (pref[j] + dp1[i][j]) % mod;
                }

                for (int j = 0; j < m; j++) {

                    if (grid[i][j] != '.')
                        continue;

                    int L = max(0, j - d);
                    int RR = min(m - 1, j + d);

                    long long val =
                        (pref[RR + 1] - pref[L] + mod) % mod;

                    val = (val - dp1[i][j] + mod) % mod;

                    dp2[i][j] = val;
                }
            }
            else {

                vector<long long> pref(m + 1, 0);

                for (int j = 0; j < m; j++) {

                    long long cur =
                        (dp1[i + 1][j] + dp2[i + 1][j]) % mod;

                    pref[j + 1] =
                        (pref[j] + cur) % mod;
                }

                for (int j = 0; j < m; j++) {

                    if (grid[i][j] != '.')
                        continue;

                    int L = max(0, j - R);
                    int RR = min(m - 1, j + R);

                    dp1[i][j] =
                        (pref[RR + 1] - pref[L] + mod) % mod;
                }

                vector<long long> pref2(m + 1, 0);

                for (int j = 0; j < m; j++) {
                    pref2[j + 1] =
                        (pref2[j] + dp1[i][j]) % mod;
                }

                for (int j = 0; j < m; j++) {

                    if (grid[i][j] != '.')
                        continue;

                    int L = max(0, j - d);
                    int RR = min(m - 1, j + d);

                    long long val =
                        (pref2[RR + 1] - pref2[L] + mod) % mod;

                    val = (val - dp1[i][j] + mod) % mod;

                    dp2[i][j] = val;
                }
            }
        }

        long long ans = 0;

        for (int j = 0; j < m; j++) {
            ans = (ans + dp1[0][j]) % mod;
            ans = (ans + dp2[0][j]) % mod;
        }

        return ans;
    }
};