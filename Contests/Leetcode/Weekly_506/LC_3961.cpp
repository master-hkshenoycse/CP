#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        ll n=units.size(),m=units[0].size();
        
        ll ans=0,mino=INT_MAX,sec_mino=INT_MAX;

        for(ll i=0;i<n;i++){
            ll mini=INT_MAX;
            ll sec_mini=INT_MAX;

            for(ll j=0;j<m;j++){
                if(m==1){
                    mini=min(mini,units[i][j]*1ll);
                    sec_mini=mini;
                }else{
                    if(units[i][j]<=mini){
                        sec_mini=mini;
                        mini=units[i][j];
                    }else if(units[i][j]<sec_mini){
                        sec_mini=min(sec_mini,units[i][j]*1ll);
                    }
                }
            }

            ans+=sec_mini;
            mino=min(mino,mini);
            sec_mino=min(sec_mino,sec_mini);
        }
        ans+=mino;
        ans-=sec_mino;
        return ans;

    }
};