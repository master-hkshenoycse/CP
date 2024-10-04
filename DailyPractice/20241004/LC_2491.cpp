#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long dividePlayers(vector<int>& skill) {
        ll n=skill.size(),s=0;
        map<ll,ll> help;
        for(ll i=0;i<n;i++){
            s=s+skill[i];
            help[skill[i]]++;
        }
        
        if(s%(n/2)){
            return -1;
        }
        ll req=s/(n/2);
        ll ans=0;
        
        
        map<ll,ll>::iterator it;
        for(it=help.begin();it!=help.end();it++){
            ll x=it->first;
            ll cnt=it->second;
            if(cnt==0){
                continue;
            }
            
            ll y=req-x;
            if(help.find(y)==help.end()){
                return -1;
            }
            
            if(x==y){
                if(cnt%2){
                    return -1;
                }
                ans=ans+(cnt/2)*(x*y);
                break;
            }else{
                if(help[x] != help[y]){
                    return -1;
                }
                help[y]=0;
                
                ans=ans+cnt*x*y;
            }
        }
        
        return ans;
        
        
    }
};