#include<bits/stdc++.h>
using namespace std;
/*https://practice.geeksforgeeks.org/contest/gfg-weekly-157-rated-contest/problems*/

#define ll long long
class Solution {
  public:
    int minimumOperations(int n, vector<int> &arr, int p, int q) {
        // code here
        ll ans=1e12,lo=0,hi=1e12;
        
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            
            ll req=0;
            ll ex=p-q;
            for(ll i=0;i<n;i++){
                ll curr=arr[i];
                curr=max(0ll,curr-mid*q);
                
                req+=(curr+ex-1)/ex;
                
            }
            
            if(req<=mid){
                ans=min(ans,mid);
                hi=mid-1;
                
            }else{
                lo=mid+1;
            }
        }
        
        return ans;
    
    }
};