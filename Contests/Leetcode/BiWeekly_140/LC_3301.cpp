#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end());
        ll ans=0,n=maximumHeight.size();
        for(ll i=n-1;i>=0;i--){
            ll max_poss=maximumHeight[i];
            if(i+1<n){
                max_poss=min(max_poss,maximumHeight[i+1]*1ll-1ll);
            }    
            maximumHeight[i]=max_poss;
            if(max_poss<=0){
                return -1;
            }

            ans=ans+max_poss;

            
        }

        return ans;
    }
};