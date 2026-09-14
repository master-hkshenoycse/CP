#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int MAXN = 200000;

    // factorials
    vector<ll> fact(MAXN + 1);
    fact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // modular inverses
    vector<ll> inv(MAXN + 1);
    inv[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (auto &x : a)
            cin >> x;

        // Required verification: ratings must be distinct.
        sort(a.begin(), a.end());

        bool distinct = true;

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                distinct = false;
                break;
            }
        }

        if (!distinct) {
            cout << -1 << '\n';
            continue;
        }

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        /*
            suffix = sum of a[i+1 ... n-1]

            For i:
                possible parents = n-i-1 (0-indexed)

            Number of complete dynasties for a fixed
            parent choice of i:

                (n-1)! / (n-i-1)
        */

        ll ans = 0;
        ll suffix = a[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            ll choices = n - i - 1;

            // Sum of costs for all possible parents of i:
            //
            // sum(a[j] - a[i])
            // = suffix - choices * a[i]

            ll edgeSum =
                (suffix - choices % MOD * (a[i] % MOD)) % MOD;

            if (edgeSum < 0)
                edgeSum += MOD;

            // Number of ways to choose the remaining parents
            ll ways =
                fact[n - 1] * inv[choices] % MOD;

            ans = (ans + edgeSum * ways) % MOD;

            suffix += a[i];
            suffix %= MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}