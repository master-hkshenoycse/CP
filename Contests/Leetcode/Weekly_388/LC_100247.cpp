#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        ll ans=0,ex=0;
        while(k--){
            ll val=max(0ll,happiness.back()-ex);
            ans=ans+val;
            happiness.pop_back();
            ex++;
        }
        return ans;
    }
};