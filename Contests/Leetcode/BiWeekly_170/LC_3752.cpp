#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll tot=(n*1ll*n*1ll+n*1ll)/2ll;
        vector<int> ret;

        if((tot+target)%2)
            return ret;

        ll pos=(tot+target)/2;
        ll neg=(tot-target)/2;
        set<ll> avail;
        for(ll i=n;i>=1;i--){
            avail.insert(i);
            if(neg>=i){
                ret.push_back(-i);
                neg-=i;
                avail.erase(i);
            }
        }

        if(neg!=0){
            ret.clear();
            return ret;
        }

        for(auto a:avail)
            ret.push_back(a);

        return ret;
    }
};