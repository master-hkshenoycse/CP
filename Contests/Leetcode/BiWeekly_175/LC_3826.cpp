#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;

    /*
        Large value representing "impossible".
    */
    static constexpr ll INF = (ll)4e18;

    /*
        Represents a line:

            y = m*x + b

        where

            m = slope
            b = intercept
    */
    struct Line {
        ll m;
        ll b;

        /*
            Evaluate line at x.

            We use __int128 during multiplication
            to avoid overflow in intermediate calculations.
        */
        ll eval(ll x) const {
            return (ll)((__int128)m * x + b);
        }
    };

    /*
        Returns true if l2 is useless.

        Suppose hull currently contains:

            l1, l2

        and we want to insert:

            l3

        If l2 can never become the minimum line,
        we remove it.

        This compares intersection points without
        using floating point arithmetic.

        We use __int128 because:

            b can be ~1e17
            m can be ~1e7

        and cross multiplication may exceed int64.
    */
    bool bad(const Line& l1,
             const Line& l2,
             const Line& l3) {

        __int128 left =
            (__int128)(l3.b - l1.b) *
            (l1.m - l2.m);

        __int128 right =
            (__int128)(l2.b - l1.b) *
            (l1.m - l3.m);

        return left <= right;
    }

    long long minPartitionScore(vector<int>& nums, int k) {

        int n = nums.size();

        /*
            Prefix sums

            pref[i] = sum of first i elements

            Example:

                nums = [3,5,2]

                pref[0] = 0
                pref[1] = 3
                pref[2] = 8
                pref[3] = 10
        */
        vector<ll> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        /*
            dp[i][p]

            Minimum score to partition first i elements
            into exactly p partitions.

            dp[0][0] = 0
            everything else starts as INF.
        */
        vector<vector<ll>> dp(
            n + 1,
            vector<ll>(k + 1, INF)
        );

        dp[0][0] = 0;

        /*
            Iterate over number of partitions.
        */
        for (int parts = 1; parts <= k; parts++) {

            /*
                Hull stores candidate transitions
                from previous partition count.

                Each previous state contributes a line.
            */
            deque<Line> hull;

            /*
                We process positions left-to-right.

                IMPORTANT:

                pref[i] is increasing because nums[i] > 0.

                Therefore:

                    slopes are inserted in sorted order

                and

                    query x values are also increasing.

                This is exactly the monotone CHT case,
                allowing O(1) amortized queries.
            */
            for (int i = parts - 1; i < n; i++) {

                /*
                    Insert transition corresponding
                    to state:

                        dp[i][parts-1]

                    before computing states that use it.
                */
                if (dp[i][parts - 1] < INF) {

                    ll T = pref[i];

                    /*
                        Original recurrence:

                        dp[r][parts]
                        =
                        min_i
                        (
                            dp[i][parts-1]
                            +
                            cost(pref[r]-pref[i])
                        )

                        where

                        cost(x)=x(x+1)/2

                        Expanding gives:

                        dp[r][parts]
                        =
                        (S²+S)/2
                        +
                        min_i
                        (
                            (-T)S
                            +
                            dp[i][parts-1]
                            +
                            (T²-T)/2
                        )

                        where:

                            S = pref[r]
                            T = pref[i]

                        Therefore each i creates a line:

                            y = m*x + b

                        with:

                            m = -T

                            b =
                            dp[i][parts-1]
                            + (T²-T)/2
                    */
                    Line cur;

                    cur.m = -T;

                    cur.b =
                        dp[i][parts - 1]
                        + (T * T - T) / 2;

                    /*
                        Remove useless lines.

                        If the newly added line makes
                        the previous line irrelevant,
                        remove that previous line.
                    */
                    while (
                        hull.size() >= 2 &&
                        bad(
                            hull[hull.size() - 2],
                            hull[hull.size() - 1],
                            cur
                        )
                    ) {
                        hull.pop_back();
                    }

                    hull.push_back(cur);
                }

                /*
                    Current query point.

                    We are computing:

                        dp[i+1][parts]

                    so

                        S = pref[i+1]
                */
                ll S = pref[i + 1];

                /*
                    Query minimum line.

                    Because query x values are increasing,
                    once line #2 becomes better than line #1,
                    line #1 can never become optimal again.

                    Therefore we can safely pop it forever.
                */
                while (
                    hull.size() >= 2 &&
                    hull[1].eval(S)
                        <=
                    hull[0].eval(S)
                ) {
                    hull.pop_front();
                }

                /*
                    Best value of:

                        min(m*x+b)
                */
                ll bestLine = hull.front().eval(S);

                /*
                    Add back the part that depends
                    only on S:

                        (S²+S)/2

                    giving:

                        dp[i+1][parts]
                */
                dp[i + 1][parts] =
                    bestLine
                    + (S * S + S) / 2;
            }
        }

        return dp[n][k];
    }
};