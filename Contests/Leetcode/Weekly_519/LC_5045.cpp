#include<bits/stdc++.h>
using namespace std;
class Solution {
    using ll = long long;
    const int INF = 1e9;

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, int val) {
            for (; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }

        int sum(int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx)
                res += bit[idx];
            return res;
        }

        int rangeSum(int l, int r) {
            if (l > r) return 0;
            return sum(r) - sum(l - 1);
        }
    };

    vector<int> a;
    vector<int> comp;

    int getId(int x) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
    }

    ll solve(int l, int r) {
        if (l >= r)
            return 0;

        int mid = (l + r) / 2;

        ll ans = solve(l, mid);
        ans += solve(mid + 1, r);

        /*
            B[i] = smallest value > a[i]
                   among positions i+1 ... mid

            C[j] = largest value < a[j]
                   among positions mid+1 ... j-1
        */

        vector<int> B(mid - l + 1, INF);
        vector<int> C(r - mid, -INF);

        // Compute B[i]
        // Sweep from right to left while maintaining
        // the smallest value greater than a[i].
        multiset<int> ms;

        for (int i = mid; i >= l; --i) {
            if (!ms.empty()) {
                auto it = ms.upper_bound(a[i]);
                if (it != ms.end())
                    B[i - l] = *it;
            }

            ms.insert(a[i]);
        }

        // Compute C[j]
        // Sweep from left to right while maintaining
        // the largest value smaller than a[j].
        ms.clear();

        for (int j = mid + 1; j <= r; ++j) {
            if (!ms.empty()) {
                auto it = ms.lower_bound(a[j]);

                if (it != ms.begin()) {
                    --it;
                    C[j - (mid + 1)] = *it;
                }
            }

            ms.insert(a[j]);
        }

        /*
            Crossing pair (i,j) is valid iff

                C[j] <= a[i] < a[j] <= B[i]

            For a fixed j:

                B[i] >= a[j]
                C[j] <= a[i] < a[j]

            Process j in decreasing a[j].

            Activate left indices whose B[i] >= a[j].

            Fenwick stores frequencies of a[i].
        */

        vector<int> leftIndices;

        for (int i = l; i <= mid; ++i)
            leftIndices.push_back(i);

        sort(leftIndices.begin(), leftIndices.end(),
             [&](int x, int y) {
                 return B[x - l] > B[y - l];
             });

        vector<int> rightIndices;

        for (int j = mid + 1; j <= r; ++j)
            rightIndices.push_back(j);

        sort(rightIndices.begin(), rightIndices.end(),
             [&](int x, int y) {
                 return a[x] > a[y];
             });

        Fenwick fw(comp.size());

        int p = 0;

        for (int j : rightIndices) {

            // Activate all i satisfying B[i] >= a[j]
            while (p < (int)leftIndices.size() &&
                   B[leftIndices[p] - l] >= a[j]) {

                int i = leftIndices[p];

                fw.add(getId(a[i]), 1);

                p++;
            }

            /*
                Need:

                    C[j] <= a[i] < a[j]

                count = count(< a[j]) - count(< C[j])
            */

            int cj = C[j - (mid + 1)];

            int rightCount =
                fw.sum(getId(a[j]) - 1);

            int leftCount = 0;

            if (cj != -INF)
                leftCount = fw.sum(getId(cj) - 1);

            ans += rightCount - leftCount;
        }

        return ans;
    }

public:
    long long shadowPairs(vector<int>& nums) {
        a = nums;

        comp = a;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        return solve(0, a.size() - 1);
    }
};