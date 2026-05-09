#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long determinant(vector<vector<long double>>& mat, int n) {
        long double det = 1;

        for (int i = 0; i < n; i++) {

            int pivot = i;

            for (int j = i; j < n; j++) {
                if (fabsl(mat[j][i]) > fabsl(mat[pivot][i]))
                    pivot = j;
            }

            if (fabsl(mat[pivot][i]) < 1e-9)
                return 0;

            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n; j++) {
                long double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return llround(det);
    }
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<long double>> lap(n, vector<long double>(n, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        // Build cofactor matrix
        vector<vector<long double>> cofactor(n - 1,
                                             vector<long double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                cofactor[i][j] = lap[i][j];
            }
        }

        return determinant(cofactor, n - 1);
    }
};