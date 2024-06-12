#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<ll,ll> > a;
        for(ll i=0;i<n;i++){
            a.push_back({arr[i]-brr[i],i});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        
        ll ans=0;
        vector<ll> suffix_gain(n+1,0);
        for(ll i=n-1;i>=0;i--){
            suffix_gain[i]=brr[a[i].second];
            if(i+1<n){
                suffix_gain[i]+=suffix_gain[i+1];
            }
        }
        
        ll cs=0;
        for(ll i=0;i<=n;i++){
            if(i<=x and n-i<=y){
                ll tot=cs;
                if(i<n)tot+=suffix_gain[i];
                ans=max(ans,tot);
            }
            if(i<n){
                cs=cs+arr[a[i].second];
            }
        }
        
        return ans;
    }
};