#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        if (a.empty() || b.empty()) {
            return {};
        }
        int n = a.size();
        int m = b.size();
        vector<int> lps(m, 0);
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && b[i] != b[j]) {
                j = lps[j - 1];
            }
            if (b[i] == b[j]) {
                j++;
                lps[i] = j;
            }
        }
        vector<int> result;
        j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && a[i] != b[j]) {
                j = lps[j - 1];
            }
            if (a[i] == b[j]) {
                j++;
            }
            if (j == m) {
                result.push_back(i - m + 1);
                j = lps[j - 1];
            }
        }
        return result;   
    }
};