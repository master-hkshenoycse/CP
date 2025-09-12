#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSensors(int n, int m, int k) {
        k=(2*k+1);
        int row_cover = (n+k-1)/k;
        int col_cover = (m+k-1)/k;

        return row_cover*col_cover;
    }
};