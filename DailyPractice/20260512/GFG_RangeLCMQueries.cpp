#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<long long> seg;
    int n;

    long long safeLCM(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        long long g = std::gcd(a, b);
        __int128 val = (__int128)(a / g) * b;
        if (val > LLONG_MAX) return LLONG_MAX;
        return (long long)val;
    }

    void build(int node, int l, int r, vector<int> &arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid, arr);
        build(2 * node + 2, mid + 1, r, arr);
        seg[node] = safeLCM(seg[2 * node + 1], seg[2 * node + 2]);
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) update(2 * node + 1, l, mid, idx, val);
        else update(2 * node + 2, mid + 1, r, idx, val);

        seg[node] = safeLCM(seg[2 * node + 1], seg[2 * node + 2]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 1;
        if (ql <= l && r <= qr) return seg[node];

        int mid = l + (r - l) / 2;
        long long left = query(2 * node + 1, l, mid, ql, qr);
        long long right = query(2 * node + 2, mid + 1, r, ql, qr);
        return safeLCM(left, right);
    }
    
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        n = arr.size();
        vector<long long> result;
        if (n == 0) return result;

        seg.assign(4 * n, 1);
        build(0, 0, n - 1, arr);

        for (auto &q : queries) {
            if (q[0] == 1) {
                int index = q[1];
                int value = q[2];
                update(0, 0, n - 1, index, value);
            } else if (q[0] == 2) {
                int L = q[1], R = q[2];
                result.push_back(query(0, 0, n - 1, L, R));
            }
        }
        return result;
        
    }
};