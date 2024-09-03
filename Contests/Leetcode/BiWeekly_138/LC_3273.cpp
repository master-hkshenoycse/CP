#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    static bool comp(vector<ll> &a,vector<ll> &b){
        ll p1=a[1]*a[0]+(a[1]+b[1])*b[0];
        ll p2=b[1]*b[0]+(a[1]+b[1])*a[0];
        return p1<p2;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        ll n=damage.size();
        vector<vector<ll> > time_req(n);
        ll tot_time=0;
        for(ll i=0;i<n;i++){
            time_req[i]={damage[i]*1ll,-(health[i]*1ll+power-1ll)/power};
            tot_time+=time_req[i][1];
        }
        
        sort(time_req.begin(),time_req.end(),comp);
        reverse(time_req.begin(),time_req.end());
        ll ans=0;
        ll left_time=0;
        
        for(ll i=0;i<n;i++){
            left_time+=(-1*time_req[i][1]);
            ans=ans+(left_time)*time_req[i][0];
        }
        
        return ans;
        
        
        
    }
};