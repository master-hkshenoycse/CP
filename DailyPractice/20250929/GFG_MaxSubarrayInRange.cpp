#include<bits/stdc++.h>
using namespace std;
int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        
        ll n=arr.size(),ans=-1e18;
        vector<ll> csum(n+1,0);   
        
        for(ll i=1;i<=n;i++){
            csum[i]=csum[i-1]+arr[i-1];
        }
        
        deque<int> dq;
        for(int r=a;r<=n;r++){
            int l=r-a;
            while(dq.size()>0 && csum[dq.back()]>=csum[l]){
                dq.pop_back();
            }
            
            dq.push_back(l);
            
            while(!dq.empty() && dq.front()<r-b){
                dq.pop_front();
            }
            
            ans=max(ans,csum[r]-csum[dq.front()]);
            
        }
        
        
        return ans;
    }