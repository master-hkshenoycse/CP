#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> deg(n,0);
        for(auto r:roads){
            deg[r[0]]++;
            deg[r[1]]++;
        }
        
        sort(deg.begin(),deg.end());
        ll ans=0;
        for(ll i=n-1;i>=0;i--){
            ans=ans+deg[i]*(i+1);
        }
        return ans;
    }
};