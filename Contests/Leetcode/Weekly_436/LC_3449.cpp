#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        ll n=points.size();
        ll lo=0,hi=1e16,ans=0;
        
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            
            vector<ll> req(n+1,0);
            ll cnt=0;
            for(ll i=0;i<n;i++){
                req[i]=(mid+points[i]-1)/points[i];
            }

            ll tot_req=n;
            for(ll i=0;i<n && tot_req>0;i++){
                cnt++;
                if(req[i]>0){
                    tot_req--;
                }
                req[i]--;

                if(req[i]>0){
                    cnt+=2*req[i];

                    req[i+1]=max(0ll,req[i+1]-req[i]);
                    req[i]-=req[i];
                    if(req[i+1] == 0){
                        tot_req--;
                    }
                }
            }
            
            if(cnt<=m){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
            
        }
        
        return ans;
    }
};