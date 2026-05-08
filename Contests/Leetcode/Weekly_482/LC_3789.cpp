#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ret=cost1*1ll*need1*1ll+cost2*1ll*need2*1ll;
        ret=min(ret, costBoth*1ll*max(need1,need2)*1ll);
        ret=min(ret, max(0ll,need1*1ll-need2*1ll)*1ll*cost1*1ll + costBoth*1ll*need2*1ll);
        ret=min(ret, need1*1ll*costBoth*1ll + max(0ll,need2*1ll-need1*1ll)*cost2*1ll);
        return ret;
    }
};