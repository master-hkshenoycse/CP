#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        ll n=pizzas.size();
        
        ll sz=n/4;
        ll ev=sz/2;
        ll od=sz-ev;
        ll ans=0;
        ll ele_req=od+ev*2;
        sort(pizzas.begin(),pizzas.end());
        
        ll od_req=od;
        ll ev_req=ev;
        for(ll i=n-1;i>=0;){
            if(od_req>0){
                ans=ans+pizzas[i];
                i--;
                od_req--;
            }else if(ev_req>0){
                ans=ans+pizzas[i-1];
                i-=2;
                ev_req--;
            }else{
                break;
            }
        }
        
        
        return ans;
    }
};