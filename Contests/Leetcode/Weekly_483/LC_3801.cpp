#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:

    long long minMergeCost(vector<vector<int>>& lists) {

        ll n = lists.size();

        ll lim = (1LL << n);

        vector<ll> mask_median(lim, 0);
        vector<ll> mask_len(lim, 0);

        for (ll mask = 1; mask < lim; mask++) {

            vector<ll> vals;

            for (ll j = 0; j < n; j++) {

                if (mask & (1LL << j)) {

                    for (auto x : lists[j]) {
                        vals.push_back(x);
                    }
                }
            }

            sort(vals.begin(), vals.end());

            mask_len[mask] = vals.size();

            mask_median[mask] =
                vals[(mask_len[mask] + 1) / 2 - 1];
        }

        vector<ll> dp(lim, (ll)1e18);

        dp[0] = 0;

        for (ll mask = 1; mask < lim; mask++) {

            if ((mask & (mask - 1)) == 0) {
                dp[mask] = 0;
                continue;
            }

            ll sub = (mask - 1) & mask;

            while (sub > 0) {

                ll other = mask ^ sub;

                ll cost =
                    mask_len[sub]
                    + mask_len[other]
                    + abs(mask_median[sub] - mask_median[other]);

                dp[mask] = min(
                    dp[mask],
                    dp[sub] + dp[other] + cost
                );

                sub = (sub - 1) & mask;
            }
        }

        return dp[lim - 1];
    }
};