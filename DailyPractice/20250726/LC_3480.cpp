#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii array<ll,2> 
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        ll m=conflictingPairs.size();

        for(ll i=0;i<m;i++){
            if(conflictingPairs[i][0] > conflictingPairs[i][1]){
                swap(conflictingPairs[i][0],conflictingPairs[i][1]);
            }
        }

        sort(conflictingPairs.begin(),conflictingPairs.end());
        ll ans=(1ll*(n+1ll)*n)/2ll;
        vector<ll> contri(m,0);
        priority_queue<pii,vector<pii>,greater<pii> > pq;
        
        ll j=m-1;
        for(ll i=n;i>=1;i--){
            while(j>=0 && conflictingPairs[j][0] >= i){
                pq.push({conflictingPairs[j][1],j});
                j--;
            }

            if(pq.empty()){
                continue;
            }

            pii item=pq.top();

            ll d=item[0],idx=item[1];
            ans-=(n-d+1);//

            pq.pop();

            if(pq.empty()){
                contri[idx]+=(n-d+1);
            }else{
                pii item2=pq.top();
                ll d2=item2[0];
                contri[idx]+=(d2-d);
            }

            pq.push(item);


        }

        
        ll res=0;
        
        for(int i=0;i<m;i++){
            res=max(res,ans+contri[i]);
        }
        
        return res;
        
    }
};