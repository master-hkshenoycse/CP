#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;

    struct Node {
        int firstPeak = -1;
        int lastPeak = -1;
        ll bad = 0;

        Node() {}

        Node(int first, int last, ll b)
            : firstPeak(first), lastPeak(last), bad(b) {}
    };

    int size;
    vector<Node> seg;

    // C(x) = number of ways to choose 2 positions from x-1 positions
    ll calc(ll x) {
        if (x <= 1) return 0;
        return (x - 1) * (x - 2) / 2;
    }

    Node merge(Node left, Node right) {

        if (left.firstPeak == -1)
            return right;

        if (right.firstPeak == -1)
            return left;

        ll extra = calc(right.firstPeak - left.lastPeak + 1);

        return Node(
            left.firstPeak,
            right.lastPeak,
            left.bad + right.bad + extra
        );
    }

    void build(int node, int l, int r, vector<int>& peak) {

        if (r - l == 1) {
            if (l < peak.size() && peak[l])
                seg[node] = Node(l, l, 0);

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2 + 1, l, mid, peak);
        build(node * 2 + 2, mid, r, peak);

        seg[node] = merge(
            seg[node * 2 + 1],
            seg[node * 2 + 2]
        );
    }

    void update(int node, int l, int r, int idx, bool isPeak) {

        if (r - l == 1) {
            if (isPeak)
                seg[node] = Node(idx, idx, 0);
            else
                seg[node] = Node();

            return;
        }

        int mid = (l + r) / 2;

        if (idx < mid)
            update(node * 2 + 1, l, mid, idx, isPeak);
        else
            update(node * 2 + 2, mid, r, idx, isPeak);

        seg[node] = merge(
            seg[node * 2 + 1],
            seg[node * 2 + 2]
        );
    }

    Node query(int node, int l, int r, int ql, int qr) {

        if (r <= ql || qr <= l)
            return Node();

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return merge(
            query(node * 2 + 1, l, mid, ql, qr),
            query(node * 2 + 2, mid, r, ql, qr)
        );
    }

    vector<ll> countOfPeaks(
        vector<int>& A,
        vector<vector<int>>& queries
    ) {

        int n = A.size();

        // peak[i] = whether i is a peak
        vector<int> peak(n, 0);

        for (int i = 1; i + 1 < n; i++) {
            peak[i] =
                A[i] > A[i - 1] &&
                A[i] > A[i + 1];
        }

        // Build segment tree
        size = 1;
        while (size < n)
            size *= 2;

        seg.resize(2 * size);

        build(0, 0, size, peak);

        vector<ll> ans;

        for (auto& q : queries) {

            // Type 1: query
            if (q[0] == 1) {

                int l = q[1];
                int r = q[2];

                if (r - l + 1 < 3) {
                    ans.push_back(0);
                    continue;
                }

                /*
                    Only peaks in (l, r) matter.
                    l and r themselves cannot be used as
                    the peak of a valid subarray.
                */
                Node cur = query(
                    0, 0, size,
                    l + 1, r
                );

                if (cur.firstPeak == -1) {
                    ans.push_back(0);
                    continue;
                }

                /*
                    Total subarrays of length >= 3
                    minus subarrays containing >= 2 peaks.
                */
                ll total = calc(r - l + 1);

                ll bad =
                    cur.bad
                    + calc(cur.firstPeak - l + 1)
                    + calc(r - cur.lastPeak + 1);

                ans.push_back(total - bad);
            }

            // Type 2: update
            else {

                int idx = q[1];
                int value = q[2];

                A[idx] = value;

                // Only these three positions can change
                // their peak status.
                for (int i = idx - 1; i <= idx + 1; i++) {

                    if (i <= 0 || i >= n - 1)
                        continue;

                    bool isPeak =
                        A[i] > A[i - 1] &&
                        A[i] > A[i + 1];

                    update(
                        0, 0, size,
                        i, isPeak
                    );
                }
            }
        }

        return ans;
    }
};