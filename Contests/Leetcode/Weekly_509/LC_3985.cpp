#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // 1. Compute Prefix Sums for O(1) range sum queries
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Helper lambda to calculate sum in original array [l, r]
        auto getRangeSum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };

        // 2. Transform array with dummy value (-1 as separator)
        vector<int> t;
        t.reserve(2 * n + 1);
        for (int x : nums) {
            t.push_back(-1);
            t.push_back(x);
        }
        t.push_back(-1);

        int m = t.size();
        vector P(m, 0);
        int C = 0, R = 0;

        long long maxSum = 0;

        // 3. Manacher's Algorithm
        for (int i = 0; i < m; ++i) {
            int i_mirror = 2 * C - i;

            if (R > i) {
                P[i] = min(R - i, P[i_mirror]);
            } else {
                P[i] = 0;
            }

            // Expand around center i
            while (i - 1 - P[i] >= 0 && i + 1 + P[i] < m && t[i - 1 - P[i]] == t[i + 1 + P[i]]) {
                P[i]++;
            }

            // Update rightmost palindrome boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            // Convert transformed radius to original bounds
            // Element at transformed index i corresponds to original index (i - 1) / 2
            int orig_left = (i - P[i]) / 2;
            int orig_right = (i + P[i] - 2) / 2;

            if (orig_left <= orig_right) {
                maxSum = max(maxSum, getRangeSum(orig_left, orig_right));
            }
        }

        return maxSum;
    }
};