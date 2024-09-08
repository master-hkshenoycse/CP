#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n=start.size();
        sort(start.begin(),start.end());
        ll lo=0,hi=2e9,ans=0;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll f=1;
            ll prev=start[0];
            for(ll i=1;i<n;i++){
                ll min_poss=prev+mid;
                if(min_poss>start[i]+d){
                    f=0;
                    break;
                }
                
                min_poss=max(min_poss,start[i]*1ll);
                prev=min_poss;
            }
            
            if(f){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};