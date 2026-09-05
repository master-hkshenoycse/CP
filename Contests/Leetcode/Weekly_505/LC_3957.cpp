#include<bits/stdc++.h>
using namespace std;
class Solution {
    struct State {
        long long sum; // penalized sum
        int count;     // number of segments used
    };

    // Maximize:
    // actual_sum - penalty * number_of_segments
    State runDP(
        int n,
        int l,
        int r,
        long long penalty,
        const vector<long long>& prefix
    ) {
        vector<State> dp(n + 1, {0, 0});

        // Stores candidate segment starting positions.
        deque<int> dq;

        auto value = [&](int j) {
            return dp[j].sum - prefix[j];
        };

        for (int i = 1; i <= n; i++) {

            // j can become the start-prefix index of a segment ending at i.
            int j = i - l;

            if (j >= 0) {
                // We want maximum:
                // dp[j].sum - prefix[j]
                while (!dq.empty()) {
                    int k = dq.back();

                    if (value(j) > value(k) ||
                        (value(j) == value(k) &&
                         dp[j].count <= dp[k].count)) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }

                dq.push_back(j);
            }

            // Segment length cannot exceed r.
            while (!dq.empty() && dq.front() < i - r) {
                dq.pop_front();
            }

            // Option 1: don't end a segment at i.
            dp[i] = dp[i - 1];

            // Option 2: choose [j, i).
            if (!dq.empty()) {
                int j = dq.front();

                State take = {
                    dp[j].sum + prefix[i] - prefix[j] - penalty,
                    dp[j].count + 1
                };

                if (take.sum > dp[i].sum ||
                    (take.sum == dp[i].sum &&
                     take.count < dp[i].count)) {
                    dp[i] = take;
                }
            }
        }

        return dp[n];
    }

    // Maximum sum of ONE subarray with length in [l, r].
    long long bestSingleSegment(
        int n,
        int l,
        int r,
        const vector<long long>& prefix
    ) {
        long long answer = LLONG_MIN;
        deque<int> dq;

        for (int i = 1; i <= n; i++) {
            int j = i - l;

            if (j >= 0) {
                // Maintain minimum prefix[j].
                while (!dq.empty() &&
                       prefix[dq.back()] >= prefix[j]) {
                    dq.pop_back();
                }

                dq.push_back(j);
            }

            while (!dq.empty() && dq.front() < i - r) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                answer = max(
                    answer,
                    prefix[i] - prefix[dq.front()]
                );
            }
        }

        return answer;
    }

public:
    long long maximumSum(
        vector<int>& nums,
        int m,
        int l,
        int r
    ) {
        int n = nums.size();

        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // First see what happens with no penalty.
        State initial = runDP(n, l, r, 0, prefix);

        // DP is allowed to choose zero segments.
        // If everything is negative, force at least one segment.
        if (initial.count == 0) {
            return bestSingleSegment(n, l, r, prefix);
        }

        // Already uses <= m segments, so constraint doesn't bind.
        if (initial.count <= m) {
            return initial.sum;
        }

        // Otherwise penalize every chosen segment until
        // the optimal solution uses <= m of them.
        long long low = 0;
        long long high = 200000000000LL;
        long long answer = -1;

        while (low <= high) {
            long long penalty = low + (high - low) / 2;

            State cur = runDP(n, l, r, penalty, prefix);

            if (cur.count <= m) {
                // cur.sum = real_sum - penalty * count
                //
                // WQS reconstruction for exactly/at-most m boundary:
                answer = cur.sum + penalty * m;
                high = penalty - 1;
            } else {
                low = penalty + 1;
            }
        }

        return answer;
    }
};