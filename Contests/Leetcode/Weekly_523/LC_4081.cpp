
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        if (n < 2 || s <= 1) return {};

        // Generate primes <= n.
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; 1LL * i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int p = 2; p <= n && p <= s; ++p) {
            if (isPrime[p]) primes.push_back(p);
        }

        int m = primes.size();
        const int INF = 1e8;

        // suf[i][x] = minimum number of primes needed
        // to form sum x using primes[i ... m-1].
        vector<vector<int>> suf(
            m + 1, vector<int>(s + 1, INF)
        );

        suf[m][0] = 0;

        for (int i = m - 1; i >= 0; --i) {
            int p = primes[i];

            for (int x = 0; x <= s; ++x) {
                // Do not select p.
                suf[i][x] = suf[i + 1][x];

                // Select p at most once.
                if (x >= p && suf[i + 1][x - p] != INF) {
                    suf[i][x] = min(
                        suf[i][x],
                        suf[i + 1][x - p] + 1
                    );
                }
            }
        }

        // 1. Maximize sum.
        int target = s;
        while (target > 0 && suf[0][target] == INF) {
            --target;
        }

        // Empty subset is the only feasible choice.
        if (target == 0) return {};

        // 2. Minimum number of primes for target sum.
        int remainingCount = suf[0][target];
        int remainingSum = target;

        // 3. Greedily choose the smallest possible primes.
        vector<int> ans;

        for (int i = 0; i < m && remainingCount > 0; ++i) {
            int p = primes[i];

            if (remainingSum >= p &&
                suf[i + 1][remainingSum - p] ==
                    remainingCount - 1) {

                ans.push_back(p);
                remainingSum -= p;
                --remainingCount;
            }
        }

        return ans;
    }
};
