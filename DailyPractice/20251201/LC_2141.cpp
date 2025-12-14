#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
       ll extra=0,m=batteries.size();
       for(ll i=0;i<m-n;i++){
           extra=extra+1ll*batteries[i];
       }
       vector<ll> curr;
       for(ll i=m-n;i<m;i++){
           curr.push_back(batteries[i]);
       }

       for(ll i=0;i<n-1;i++){
           if(extra<(i+1)*(curr[i+1]-curr[i])){
               return curr[i]+extra/(i+1);
           }

           extra-=(i+1)*(curr[i+1]-curr[i]);
       }
       return curr[n-1]+extra/n;
    }
};