#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
         int n = nums.size();

        // Two moduli to make collisions extremely unlikely.
        const ll MOD1 = 1000000007;
        const ll MOD2 = 1000000009;
        const ll BASE = 100003;

        vector<ll> pow1(n + 1), pow2(n + 1);
        vector<ll> pref1(n + 1), pref2(n + 1);

        pow1[0] = pow2[0] = 1;

        for (int i = 0; i < n; i++) {
            pow1[i + 1] = pow1[i] * BASE % MOD1;
            pow2[i + 1] = pow2[i] * BASE % MOD2;

            pref1[i + 1] =
                (pref1[i] * BASE + nums[i]) % MOD1;

            pref2[i + 1] =
                (pref2[i] * BASE + nums[i]) % MOD2;
        }

        auto getHash = [&](int l, int r) {
            ll h1 =
                (pref1[r] -
                 pref1[l] * pow1[r - l] % MOD1 +
                 MOD1) % MOD1;

            ll h2 =
                (pref2[r] -
                 pref2[l] * pow2[r - l] % MOD2 +
                 MOD2) % MOD2;

            return pair<ll,ll>{h1, h2};
        };

        auto existsUnique = [&](int len) {

            map<pair<ll,ll>, int> freq;

            for (int i = 0; i + len <= n; i++) {
                auto h = getHash(i, i + len);
                freq[h]++;
            }

            for (auto &[h, count] : freq) {
                if (count == 1)
                    return true;
            }

            return false;
        };

        int lo = 1;
        int hi = n;
        int ans = n;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (existsUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};