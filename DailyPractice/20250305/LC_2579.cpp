#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        ll v=n;
        ll ans=v*v+(v-1)*(v-1);
        return ans;
    }
};